// getting WA of first and second test case
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

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
        instrumentPnlQueue[instrument_id].push({(price - prices[instrument_id]) * (buy_sell == "BUY" ? -1 : 1), trade_id});
    }

    void process_price_update(const string &instrument_id, double price)
    {
        prices[instrument_id] = price;
    }

    int output_worst_trade(const string &instrument_id)
    {
        int worstTradeId = -1;
        if (instrumentPnlQueue.count(instrument_id) > 0 && !instrumentPnlQueue[instrument_id].empty())
        {
            if (instrumentPnlQueue[instrument_id].top().first < 0)
            {
                worstTradeId = instrumentPnlQueue[instrument_id].top().second;
                cout << worstTradeId << endl;
            }
        }
        if (worstTradeId == -1)
        {
            cout << "NO BAD TRADES" << endl;
        }
        return worstTradeId;
    }

private:
    // We need a DS for storing the prices
    unordered_map<string, double> prices;
    // We need a DS for storing the Trades
    vector<Trade> trades;
    // We need a DS for storing the priority queue for each instrument ID
    unordered_map<string, priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>> instrumentPnlQueue;
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