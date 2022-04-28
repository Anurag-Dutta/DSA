/*
You are given an array of denominations and a value X.
You have to make the amount X using minimum number of coins.
Find the minimum number of coins required for this operation.
*/
#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int main(int argc, char **argv)
{
    int x = 350;
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    sort(denominations.begin(), denominations.end(), greater<>());
    for (auto &i : denominations)
    {
        cout << i << " ";
    }
    int init = 0;
    int count = 0;
    while (x > 0)
    {
        if (denominations[init] <= x)
        {
            x -= denominations[init];
            count++;
        }
        else
        {
            init++;
        }
    }
    cout << "\n"
         << count << endl;
    getch();
    return 0;
}