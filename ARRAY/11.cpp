/*https://leetcode.com/problems/third-maximum-number/
414. Third Maximum Number
Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.
Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.
Example 2:
Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: nums = [2,2,3,1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.*/
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<int> res;
        for (int x : nums)
        {
            res.insert(x);
            if (res.size() > 3)
            {
                res.erase(res.begin());
            }
        }
        return res.size() == 3 ? *res.begin() : *res.rbegin();
    }
};
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == first || nums[i] == second || nums[i] == third) // to avoid duplicate elements
                continue;
            if (nums[i] > first)
            {
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] > second)
            {
                third = second;
                second = nums[i];
            }
            else if (nums[i] > third)
                third = nums[i];
            else
                continue;
        }
        return third == LONG_MIN ? first : third;
    }
};