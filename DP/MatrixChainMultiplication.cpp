#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int dp[10000][10000]; // Here the DP Memo is 2 - D as (start & end) both are changing during recursion

int func(vector<int> &inputs, int start, int end)
{
    if (start == end)
    {
        return 0; // Only one Matrix is present
    }
    if (dp[start][end] != INT_MAX)
    {
        return dp[start][end];
    }
    for (int k = start; k < end; k++)
    {
        dp[start][end] = min(dp[start][end], ((inputs[start - 1] * inputs[k] * inputs[end]) + func(inputs, start, k) + func(inputs, k + 1, end)));
    }
    return dp[start][end];
}
int main(int argc, char **argv)
{
    vector<int> input = {10, 20, 30, 40, 30};
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    cout << func(input, 1, 4) << endl;
    getch();
    return 0;
}