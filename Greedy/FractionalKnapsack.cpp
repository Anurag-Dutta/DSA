#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int main(int argc, char **argv)
{
    int knapsack_capacity = 20;
    vector<vector<int>> items = {{21, 7}, {24, 4}, {12, 6}, {40, 5}, {30, 6}}; // {a, b} -> Cost: a, Weight: b
    vector<vector<int>> items_modified(5, vector<int>(3));
    for (int i = 0; i < 5; i++)
    {
        items_modified[i][0] = items[i][0];
        items_modified[i][1] = items[i][1];
        items_modified[i][2] = double((items[i][0]) / (items[i][1]));
    }
    for (int i = 0; i < items_modified.size(); i++)
    {
        swap(items_modified[i][0], items_modified[i][2]);
    }
    sort(items_modified.begin(), items_modified.end(), greater<>());
    for (int i = 0; i < items_modified.size(); i++)
    {
        swap(items_modified[i][0], items_modified[i][2]);
    }
    int profit = 0, initial = 0;
    while (knapsack_capacity != 0)
    {
        if (items_modified[initial][1] <= knapsack_capacity)
        {
            profit += items_modified[initial][0];
            knapsack_capacity -= items_modified[initial][1];
            initial++;
        }
        else
        {
            profit += (items_modified[initial][2]) * knapsack_capacity;
            knapsack_capacity = 0;
        }
    }
    cout << "profit: " << profit << endl;
    getch();
    return 0;
}