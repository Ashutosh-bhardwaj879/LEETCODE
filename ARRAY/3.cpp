//Remove target Elements all duplicacy in array
/*Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length. For example if you return 2 with nums = [2,2,3,3] or nums = [2,2,0,0], your answer will be accepted.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[] = {3, 2, 2, 3};
    int N = sizeof(A) / sizeof(A[0]);
    int target = 2;
    //ie remove 2
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] != target)
        {
            A[index++] = A[i];
        }
    }
    for (int i = 0; i < index; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << index << endl;
    return 0;
}
