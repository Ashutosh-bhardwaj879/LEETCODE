//Length of last word
/*58. Length of Last Word
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
A word is a maximal substring consisting of non-space characters only.
Example 1:

Input: s = "Hello World"
Output: 5
Example 2:

Input: s = " "
Output: 0*/
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.length();
        int count = 0;
        while (n > 0)
        {
            if (s[--n] != ' ')
                count++;
            else if (count > 0)
                return count;
        }
        return count;
    }
};