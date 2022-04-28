#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<int> files = {20, 30, 10, 5, 30};
    int sum = 0;
    while (files.size() != 1)
    {
        sort(files.begin(), files.end());
        int temp = files[0] + files[1];
        sum += temp;
        files.erase(files.begin());
        files.erase(files.begin());
        files.insert(files.begin(), temp);
    }
    cout << sum << endl;
    getch();
    return 0;
}