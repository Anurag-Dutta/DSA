/*
Given a number n, your task is to find the minimum number of numbers which sums to n.
*/
#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

const int N = 10e5;
int dp[N];

int min_sq(int n)
{
    if (n <= 3 && n >= 0)
    {
        return n;
    }
    if (dp[n] != INT_MAX)
    {
        return dp[n];
    }
    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], min_sq(n - (i * i)) + 1);
    }
    return dp[n];
}
int main(int argc, char **argv)
{
    int n = 11;
    for (int i = 0; i < N; i++)
    {
        dp[i] = INT_MAX;
    }
    cout << min_sq(n) << endl;
    getch();
    return 0;
}