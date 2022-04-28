#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<vector<int>> jobs = {{3, 20}, {5, 20}, {10, 100}, {6, 70}, {9, 60}};
    int max_deadline = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        if (jobs[i][0] > max_deadline)
        {
            max_deadline = jobs[i][0];
        }
    }
    for (int i = 0; i < jobs.size(); i++)
    {
        swap(jobs[i][0], jobs[i][1]);
    }
    sort(jobs.begin(), jobs.end(), greater<>());
    for (int i = 0; i < jobs.size(); i++)
    {
        swap(jobs[i][0], jobs[i][1]);
    }
    vector<int> slots(max_deadline, 0);
    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i][0] - 1; j >= 0; j--)
        {
            if (slots[j] == 0)
            {
                slots[j] = jobs[i][1];
                break;
            }
        }
    }
    cout << accumulate(slots.begin(), slots.end(), 0) << endl;
    getch();
    return 0;
}