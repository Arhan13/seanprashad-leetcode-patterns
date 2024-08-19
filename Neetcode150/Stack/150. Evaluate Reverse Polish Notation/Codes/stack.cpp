#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string &c : tokens)
        {
            if (c == "+" || c == "-" || c == "*" || c == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (c == "+")
                {
                    st.push(num2 + num1);
                }
                else if (c == "-")
                {
                    st.push(num2 - num1);
                }
                else if (c == "*")
                {
                    st.push(num2 * num1);
                }
                else if (c == "/")
                {
                    st.push(num2 / num1);
                }
            }
            else
            {
                st.push(int(stoi(c)));
            }
        }
        return st.top();
    }
};