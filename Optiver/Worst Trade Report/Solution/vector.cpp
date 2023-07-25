#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Trade
{
    int tradeId;
    string instrumentId;
    string buyOrSell;
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
        int worstPnlPerLot = 0;
        int worstTradeId = -1;
        for (Trade trade : trades)
        {
            if (trade.instrumentId == instrument_id)
            {
                double pnlPerLot = (trade.price - prices[instrument_id]) * (trade.buyOrSell == "BUY" ? -1 : 1);
                if (pnlPerLot < worstPnlPerLot)
                {
                    worstPnlPerLot = pnlPerLot;
                    worstTradeId = trade.tradeId;
                }
            }
        }
        if (worstTradeId == -1)
        {
            cout << "NO BAD TRADES" << endl;
        }
        else
        {
            cout << worstTradeId << endl;
        }
        return worstTradeId;
    }

private:
    // We need a DS for storing the prices
    unordered_map<string, double> prices;
    // We need a DS for storing the Trades
    vector<Trade> trades;
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