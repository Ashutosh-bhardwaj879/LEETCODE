/*442. Find All Duplicates in an Array
Medium
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]*/
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // sorting se bhi ho jayega but
        // o(nlogn) akela sorting le lega
        // o(n) time complexity ans o(1) spce complexity
        vector<int> res;
        for (int i : nums)
        {
            int n = abs(i);
            if (nums[n - 1] > 0)
                nums[n - 1] *= (-1);
            else
                res.push_back(n);
        }
        return res;
    }
};