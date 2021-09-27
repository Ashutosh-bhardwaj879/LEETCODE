/*Given a roman numeral, convert it to an integer.
Example 1:
Input: s = "III"
Output: 3*/
#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    map<char, int> roman;
    roman.insert(make_pair('I', 1));
    roman.insert(make_pair('V', 5));
    roman.insert(make_pair('X', 10));
    roman.insert(make_pair('L', 50));
    roman.insert(make_pair('C', 100));
    roman.insert(make_pair('D', 500));
    roman.insert(make_pair('M', 1000));
    int len = s.length();
    int sum = 0;
    int num;
    for (int i = 0; i < len;)
    {
        if (i == (len - 1) || (roman[s[i]] >= roman[s[i + 1]]))
        {
            num = roman[s[i]];
            i++;
        }
        else
        {
            num = roman[s[i + 1]] - roman[s[i]];
            i += 2;
        }
        sum = sum + num;
    }
    return sum;
}
int main()
{
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
}
