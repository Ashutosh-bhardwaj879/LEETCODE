/*128. Longest Consecutive Sequence
Hard
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9*/
//o(n) + o(nlogn)[for loop + sorting]
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int currentStreak = 1;
        int longestStreak = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    currentStreak++;
                }
                else
                {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }
        return max(longestStreak, currentStreak);
    }
};

//12 ms using unordered_set o(n) + o(n)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        int longestStreak = 0;
        for (auto num : nums)
        {
            s.insert(num);
        }
        for (auto n : s)
        {
            if (s.count(n - 1) == 0)
            {
                int currentStreak = 0;
                int currentElement = n;

                while (s.count(currentElement))
                {
                    currentElement += 1;
                    currentStreak += 1;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};
//16 ms using set
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> s;
        int longestStreak = 0;
        for (auto num : nums)
        {
            s.insert(num);
        }
        for (auto n : s)
        {
            if (s.count(n - 1) == 0)
            {
                int currentStreak = 0;
                int currentElement = n;

                while (s.count(currentElement))
                {
                    currentElement += 1;
                    currentStreak += 1;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};
