#include <bits/stdc++.h>
using namespace std;

bool duplicates_sort_method(vector<int> arr) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++)
        if (arr[i] == arr[i + 1]) return true;
    return false;
}

bool duplicates_set_method(vector<int> arr) {
    return arr.size() > set<int>(arr.begin(), arr.end()).size();
}

bool duplicates_map_method(vector<int> arr) {
    map<int, int> arr_map;
    for (auto i: arr) arr_map[i]++;
    for (auto i: arr_map)
        if (i.second > 1)
            return true;
    return false;
}

bool duplicates_hashmap_method(vector<int> arr) {
    unordered_map<int, int> arr_map;
    for (auto i: arr) arr_map[i]++;
    for (auto i: arr_map)
        if (i.second > 1)
            return true;
    return false;
}

int main() {
    vector<int> arr{ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    cout << duplicates_sort_method(arr) << endl;
    cout << duplicates_set_method(arr) << endl;
    cout << duplicates_map_method(arr) << endl;
    cout << duplicates_hashmap_method(arr) << endl;
    return 0;
}
