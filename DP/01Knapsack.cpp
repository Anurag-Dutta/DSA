#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int dp[1000][1000]; // Here the DP Memo is 2 - D as (knapsack_capacity & n) both are changing during recursion

int knapsack(vector<int> &values, vector<int> &weights, int n, int knapsack_capacity)
{
    if (n == 0 || knapsack_capacity == 0)
    {
        return 0;
    }
    if (dp[n][knapsack_capacity] != -1)
    {
        return dp[n][knapsack_capacity];
    }
    if (weights[n - 1] > knapsack_capacity)
    {
        dp[n][knapsack_capacity] = knapsack(values, weights, n - 1, knapsack_capacity);
        return dp[n][knapsack_capacity];
    }
    dp[n][knapsack_capacity] = max((knapsack(values, weights, n - 1, knapsack_capacity - weights[n - 1]) + values[n - 1]), knapsack(values, weights, n - 1, knapsack_capacity));
    return dp[n][knapsack_capacity];
}
int main(int argc, char **argv)
{
    vector<int> values = {100, 50, 150};
    vector<int> weights = {10, 20, 30};
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(values, weights, values.size(), 50) << endl;
    getch();
    return 0;
}