#include <iostream>
using namespace std;

struct Minmax
{
    int min;
    int max;
};

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    print(array, sizeof(array) / sizeof(int));
    Minmax min_max = {array[0], array[0]};
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        if (array[i] < min_max.min)
            min_max.min = array[i];
        if (array[i] > min_max.max)
            min_max.max = array[i];
    }
    cout << "\nMin: " << min_max.min << "\nMax: " << min_max.max << endl;
    return 0;
}
