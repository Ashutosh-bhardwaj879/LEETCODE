/*1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        //iterator i jo begin se laekar end tak chalega
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            //iterator jo i+! se end tak chalega aur find karega (target - i)
            auto j = find(i + 1, nums.end(), target - *i);
            if (j != nums.end()) //found the number
            {
                result.push_back(i - nums.begin());
                result.push_back(j - nums.begin());
            }
        }
        return result;
    }
};