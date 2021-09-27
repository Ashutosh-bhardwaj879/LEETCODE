/*38. Count and Say
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.
For example, the saying and conversion for digit string "3322251":
Given a positive integer n, return the nth term of the count-and-say sequence.
Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"

Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"*/
//https://www.youtube.com/watch?v=UOs4HSF72vY&feature=youtu.be
//https://www.youtube.com/watch?v=1YUqtoT9YoE
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 0)
            return 0;
        string res = "1";
        while (--n)
        {
            string curr = ""; //current string will pass on to res string
            for (int i = 0; i < res.size(); i++)
            {
                int c = 1; //counter which is in int
                while (i < res.size() - 1 and res[i] == res[i + 1])
                {
                    c++; //increse counter
                    i++; //will increase values
                }
                curr += to_string(c) + res[i]; //to_string change int to string
                //res[i] will contain element to be counted
            }
            res = curr; //result is current passed on
        }
        return res;
    }
};