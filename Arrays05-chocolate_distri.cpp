#include <bits/stdc++.h>
using namespace std;

int min_differece_choco_distri(vector<int> vec, int num_of_studs)
{
    int min_diff = INT_MAX;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - num_of_studs - 1; i++)
    {
        min_diff = min(min_diff, vec[i + num_of_studs - 1] - vec[i]);
    }
    return min_diff;
}

int main()
{
    vector<int> vec = {7, 3, 2, 4, 9, 12, 56};
    int num = 3;
    cout << min_differece_choco_distri(vec, num) << endl;
    return 0;
}
