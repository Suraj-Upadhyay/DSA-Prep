#include <iostream>
using namespace std;

void print(int *arr, int size)
{
    cout << '\n';
    for (int i = 0; i < size - 1 ; i++)
        cout << arr[i] << ' ';
    cout << arr[size - 1];
    cout << endl;
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void array_reverse_0(int *arr, int size) {
    // iterative method
    for (int i = 0, j = size - 1; i <= j; i++, j--) swap(arr[i], arr[j]);
}

void array_reverse_1(int *arr, int start, int end) {
    // recursive method
    if ( start > end ) return;
    swap(arr[start++], arr[end--]);
    array_reverse_1(arr, start, end);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = sizeof(arr)/sizeof(int);
    print(arr, size);
    array_reverse_0(arr, size);
    print(arr, size);
    array_reverse_1(arr, 0, size - 1);
    print(arr, size);
    return 0;
}
