#include <bits/stdc++.h>
using namespace std;

/*
Things to remember for this algorithm:
1. There are negative and positive integers scattered across the array.
2. And the maximum sum will either be
    i. greatest negative element
    ii. zero
    iii. any single positive element
    iv. sum of consecutive positive elements.

So,
1. There will be two variables max_so_far, max_end_here.
2. max_so_far will contain the maximum sum found so far.
3. max_end_here will contain the maximum sum found since last zero.
4. max_end_here will be initialized with zero everytime it's value goes negative, to ensure 2.ii.
5. if max_end_here goes negative and if that negative is greater than max_so_far,
   assign max_so_far the value of max_end_here, to ensure that 2.i holds true.
6. if max_end_here doesn't go zero and encounters a series of positive elements,
   then it will have the sum of them all. And if max_so_far is smaller than max_end_here,
   then it will be assigned the new value of max_end_here to ensure 2.iii and 2.iv.

There are several cases of input here:
1. All the elements are negative in which we have to output the greatest negative element as the sum of maximum subarray.
2. All the elements are positive in which we have to output the sum of all the elements in the array.
3. It will be a mix of negatives and positives -
    i. Among large positive elements there are negative elements.
    ii. Among large subarray of positive elements there will be negative elements scattered in between.
    iii. A subarray containing only positive elements.
    iv. A mixture of the above three cases with each having different sum.

Here nested looping is avoided with the help of an additional variable that traverses the array
and keeps track of the sum of elements while getting reinitialized to zero everytime it gets negative.
It reports its value on every iteration to max_so_far which checks if a new maximum has been found or not.

*/

int max_subarray(int *arr, int size)
{
    int max_as_of_now = INT_MIN, max_end_here = 0;
    for (int i = 0; i < size - 1; i++)
    {
        max_end_here += arr[i];
        if (max_as_of_now < max_end_here)
            max_as_of_now = max_end_here;
        if (max_end_here < 0)
            max_end_here = 0;
    }
    return max_as_of_now;
}

int kadanes_algorithgm(vector<int> arr)
{
    int max_so_far = INT_MIN, max_end_here = 0;
    for (auto a : arr)
    {
        max_end_here += a;
        if (max_so_far < max_end_here)
            max_so_far = max_end_here;
        if (max_end_here < 0)
            max_end_here = 0;
    }
    return max_so_far;
}

int main()
{
    int a[] = {1, 3, -5, -9, 7, 8, 0};
    int size = sizeof(a) / sizeof(int);
    cout << max_subarray(a, size) << endl;
}
