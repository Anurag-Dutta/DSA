#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int main(int argc, char **argv)
{
    int n = 8;
    int table[n];
    table[0] = 0, table[1] = 0, table[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2]; // Tabulation : Bottom -> Top
    }
    cout << table[n] << endl;
    getch();
    return 0;
}