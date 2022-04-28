/*
You are given an array of activities enlisted with their starting and ending time.
Find out the maximum activities that a person can perform.
Only one activity can be active at a time.
*/
#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<vector<int>> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}}; //{{10, 20}, {12, 25}, {20, 30}}
    for (int i = 0; i < activities.size(); i++)
    {
        swap(activities[i][0], activities[i][1]);
    }
    sort(activities.begin(), activities.end());
    for (int i = 0; i < activities.size(); i++)
    {
        swap(activities[i][0], activities[i][1]);
    }
    int count = 1;
    int end = activities[0][1];
    for (int i = 0; i < activities.size(); i++)
    {
        if (activities[i][0] > end)
        {
            end = activities[i][1];
            count++;
        }
    }
    cout << "\n"
         << count << endl;
    getch();
    return 0;
}