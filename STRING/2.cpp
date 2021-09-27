//https://www.youtube.com/watch?v=rnwmE9m9EMM
/*1221. Split a String in Balanced Strings
Balanced strings are those who have equal quantity of 'L' and 'R' characters.
Given a balanced string s split it in the maximum amount of balanced strings.
Return the maximum amount of splitted balanced strings.
Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.*/
#include <bits/stdc++.h>
using namespace std;
int balancedStringSplit(string s)
{
    int balancedCount = 0;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char current = s[i];
        if (current == 'L')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
            balancedCount++;
    }
    return balancedCount;
}
int main()
{
    string s;
    getline(cin, s);
    cout << balancedStringSplit(s);
    return 0;
}