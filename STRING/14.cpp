/*709. To Lower Case
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"*/
#include <bits/stdc++.h>
using namespace std;

string toLowerCase(string str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str;
}
int main()
{
    string str = "ABC";
    cout << toLowerCase(str) << endl;
    return 0;
}
class Solution
{
public:
    string toLowerCase(string str)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};