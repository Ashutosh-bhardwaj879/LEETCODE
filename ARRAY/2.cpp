/*Remove Duplicates from Sorted Array
Easy
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[] = {0, 0, 2, 2, 2, 3, 3, 4, 4, 5};
    int N = sizeof(A) / sizeof(A[0]);
    int count = 1;//it is because first element is always unique
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] != A[i + 1])
        {
            //count++ gives increases index 
            //A[count++] stores unique element in same array 
            A[count++] = A[i + 1];
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
