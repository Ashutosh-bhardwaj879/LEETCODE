//TWO SUM
/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int res[2]={0,0};
    int target = 9;
    int nums[] = {2, 7, 11, 15};
    int n = sizeof(nums) / sizeof(nums[0]);
    sort(nums, nums + n);
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (nums[start] + nums[end] == target)
        {
            res[0] = start;
            res[1] = end;
            break;
        }
        else if (nums[start] + nums[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}
