//https://www.youtube.com/watch?v=Ev11iLc84lk
/*14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input string*/
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int count = 0;
        int min = 1000;
        string str; ///taking new string to keep the smallest string ie fly
        for (int i = 0; i < strs.size(); i++)
        {
            int len = strs[i].length();
            if (len < min)
            {
                min = len;     //min is length of smallest string ie fly = 3
                str = strs[i]; //str mein fly chala gaya
            }
        }
        //loop count ke liye hian fl =2
        for (int i = 0; i < min; i++) //fly tak chalegi loop 0 to < 3
        {
            for (int j = 0; j < strs.size(); j++) //0 to 2
            {
                if (strs[j][i] != str[i]) //strs[0][0]!=str[0]
                                          //pehla hi elment same nahi to aage kyon chale return kardo
                    return str.substr(0, count);
            }
            count++;
        }
        return str.substr(0, count); //str ka substring 0 se < 2 ie fl
    }
};