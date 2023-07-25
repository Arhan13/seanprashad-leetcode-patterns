#include <bits/stdc++.h>

using namespace std;

struct Trade
{
    int trade_id;
    string instrument_id;
    string buy_sell;
    double price;
    int volume;
};

class PnLCalculator
{
public:
    void process_trade(int trade_id, const string &instrument_id, const string &buy_sell, double price, int volume)
    {
        trades.push_back({trade_id, instrument_id, buy_sell, price, volume});
    }

    void process_price_update(const string &instrument_id, double price)
    {
        prices[instrument_id] = price;
    }

    int output_worst_trade(const string &instrument_id)
    {
        double worst_pnl_per_lot = 0;
        int worst_trade_id = -1;
        double instrument_price = prices[instrument_id];
        priority_queue<pair<double, int>> buy_heap;
        priority_queue<pair<double, int>, vector<pair<double, int>>, std::greater<pair<double, int>>> sell_heap;
        for (const auto &trade : trades)
        {
            if (trade.instrument_id == instrument_id)
            {
                if (trade.buy_sell == "BUY")
                {
                    buy_heap.push({trade.price, trade.volume});
                }
                else
                {
                    sell_heap.push({trade.price, trade.volume});
                }
            }
        }
        if (buy_heap.empty() || sell_heap.empty())
        {
            cout << "NO BAD TRADES" << endl;
            return -1;
        }
        auto buy_trade = buy_heap.top();
        auto sell_trade = sell_heap.top();
        double pnl_per_lot = (instrument_price - buy_trade.first) * buy_trade.second - (instrument_price - sell_trade.first) * sell_trade.second;
        if (pnl_per_lot < worst_pnl_per_lot)
        {
            worst_pnl_per_lot = pnl_per_lot;
            worst_trade_id = buy_trade_id[buy_trade];
        }
        pnl_per_lot = (instrument_price - sell_trade.first) * sell_trade.second - (instrument_price - buy_trade.first) * buy_trade.second;
        if (pnl_per_lot < worst_pnl_per_lot)
        {
            worst_pnl_per_lot = pnl_per_lot;
            worst_trade_id = sell_trade_id[sell_trade];
        }
        if (worst_trade_id == -1)
        {
            cout << "NO BAD TRADES" << endl;
        }
        else
        {
            cout << worst_trade_id << endl;
        }
        return worst_trade_id;
    }

private:
    vector<Trade> trades;
    unordered_map<string, double> prices;
    unordered_map<pair<double, int>, int> buy_trade_id;
    unordered_map<pair<double, int>, int> sell_trade_id;

    void update_trade_id_maps()
    {
        for (const auto &trade : trades)
        {
            if (trade.buy_sell == "BUY")
            {
                buy_trade_id[{trade.price, trade.volume}] = trade.trade_id;
            }
            else
            {
                sell_trade_id[{trade.price, trade.volume}] = trade.trade_id;
            }
        }
    }
};

void run_pnl_calculator()
{
    PnLCalculator calculator;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "TRADE")
        {
            int trade_id, volume;
            double price;
            string instrument_id, buy_sell;
            cin >> trade_id >> instrument_id >> buy_sell >> price >> volume;
            calculator.process_trade(trade_id, instrument_id, buy_sell, price, volume);
        }
        else if (command == "PRICE")
        {
            string instrument_id;
            double price;
            cin >> instrument_id >> price;
            calculator.process_price_update(instrument_id, price);
        }
        else if (command == "WORST_TRADE")
        {
            string instrument_id;
            cin >> instrument_id;
            calculator.output_worst_trade(instrument_id);
        }
    }
}

int main()
{
    run_pnl_calculator();
    return 0;
}