//https://www.youtube.com/watch?v=og8SijKgPtY
/*1684. Count the Number of Consistent Strings
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.
Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.*/

//ye vala samjh nahi aaya
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int cnt = 0;

        for (string w : words)
        {
            for (char c : w)
            {
                if (allowed.find(c) == string::npos)
                {
                    cnt--;
                    break;
                }
            }
            cnt++;
        }

        return cnt;
    }
};
// ye vala smajh gaya
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_map<char, int> map;
        for (auto c : allowed)
        {
            map[c] = 1;
        }
        int count = 0;
        for (auto s : words)
        {
            int flag = 1;
            for (auto c : s)
            {
                if (map[c] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                count++;
            }
        }
        return count;
    }
};
