/*https://www.youtube.com/watch?v=20v8zSo2v18&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=19
560. Subarray Sum Equals K
Medium

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int count = 0;
        int sum = 0;
        map[sum]++;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (map.find(sum - k) != map.end())
            {
                count += map[sum - k];
            }
            map[sum]++;
        }
        return count;
    }
};

// C++ program for
// the above approach
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int k = -10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = 0;

    // Calculate all subarrays
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            // Calculate required sum
            sum += arr[j];

            // Check if sum is equal to
            // required sum
            if (sum == k)
                res++;
        }
    }
    cout << (res) << endl;
}

// This code is contributed by Chitranayal
