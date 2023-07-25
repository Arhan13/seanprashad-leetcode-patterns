#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

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
        for (const auto &trade : trades)
        {
            if (trade.instrument_id == instrument_id)
            {
                double pnl_per_lot = (prices[instrument_id] - trade.price) * (trade.buy_sell == "BUY" ? 1 : -1) * trade.volume;
                if (pnl_per_lot < worst_pnl_per_lot)
                {
                    worst_pnl_per_lot = pnl_per_lot;
                    worst_trade_id = trade.trade_id;
                }
            }
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    run_pnl_calculator();
    return 0;
}