#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int knapsack(vector<int> &values, vector<int> &weights, int number, int capacity)
{
    if (number == 0 || capacity == 0)
    {
        return 0; // Base Case
    }
    if (weights[number - 1] > capacity)
    {
        return knapsack(values, weights, number - 1, capacity);
    }
    return max(knapsack(values, weights, number - 1, capacity), (knapsack(values, weights, number - 1, capacity - weights[number - 1]) + values[number - 1]));
}
int main(int argc, char **argv)
{
    vector<int> values = {100, 50, 150};
    vector<int> weights = {10, 20, 30};
    cout << knapsack(values, weights, values.size(), 50) << endl;
    getch();
    return 0;
}