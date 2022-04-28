#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

const int N = 10e5;
int dp[N];

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n]; // Memoization : Top -> Bottom
    }
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}
int main(int argc, char **argv)
{
    int n = 8;
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
    cout << fib(n) << endl;
    getch();
    return 0;
}