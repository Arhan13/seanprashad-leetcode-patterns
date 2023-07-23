#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Stock
{
public:
    string name;
    string date;
    double price;

    Stock(string n, string d, double p)
    {
        name = n;
        date = d;
        price = p;
    }
};

class Trader
{
public:
    double balance;
    vector<Stock> portfolio;

    Trader(double b)
    {
        balance = b;
    }

    void buy(Stock s, double amount)
    {
        double shares = amount / s.price;
        balance -= amount;
        portfolio.push_back(Stock(s.name, s.date, shares));
    }

    void sell(Stock s, double amount)
    {
        double shares = amount / s.price;
        balance += amount;
        for (int i = 0; i < portfolio.size(); i++)
        {
            if (portfolio[i].name == s.name)
            {
                if (shares >= portfolio[i].price)
                {
                    shares -= portfolio[i].price;
                    portfolio.erase(portfolio.begin() + i);
                    i--;
                }
                else
                {
                    portfolio[i].price -= shares;
                    break;
                }
            }
        }
    }

    double getPortfolioValue(vector<Stock> prices)
    {
        double value = 0;
        for (int i = 0; i < portfolio.size(); i++)
        {
            for (int j = 0; j < prices.size(); j++)
            {
                if (portfolio[i].name == prices[j].name && portfolio[i].date == prices[j].date)
                {
                    value += portfolio[i].price * prices[j].price;
                    break;
                }
            }
        }
        return value;
    }
};

double getMaxProfit(int k, vector<Stock> prices)
{
    int n = prices.size();
    if (k >= n / 2)
    {
        double maxProfit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i].price > prices[i - 1].price)
            {
                maxProfit += prices[i].price - prices[i - 1].price;
            }
        }
        return maxProfit;
    }
    if (k <= 0)
    {
        return 0;
    }
    vector<vector<double>> dp(k + 1, vector<double>(n, 0));
    for (int i = 1; i <= k; i++)
    {
        double maxDiff = -prices[0].price;
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], prices[j].price + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j].price);
        }
    }
    return dp[k][n - 1];
}

int main()
{
    vector<Stock> prices = {
        Stock("CSCO", "10/18/2024", 41.89),
        Stock("AMZN", "10/10/2024", 113.67),
        Stock("AMZN", "10/18/2024", 120.5),
        Stock("CSCO", "10/10/2024", 43.12)};
    double startingBalance = 1000.0;
    Trader trader(startingBalance);
    double maxProfit = getMaxProfit(1000, prices);
    double portfolioValue = trader.getPortfolioValue(prices);
    double finalBalance = startingBalance + maxProfit + portfolioValue;
    cout << "Maximum profit: $" << maxProfit << endl;
    cout << "Portfolio value: $" << portfolioValue << endl;
    cout << "Final balance: $" << finalBalance << endl;
    return 0;
}
