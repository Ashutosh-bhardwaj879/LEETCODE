/*66. Plus ONE
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]*/
//https://www.youtube.com/watch?v=G737jzcxG9A
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    bool carry = true;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i] += 1;
            carry = false;
            break;
        }
    }
    if (carry)
    {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}
vector<int> plusOne(vector<int>& digits)
{
    for (int i = digits.size() - 1; i >= 0; i++)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    int result = new int[digits.size() + 1];
    result[0] = 1;
    return result;
}
/*129
last is 9 so make it 0
move to second last its less than 9 increase it and return spontaneously
//128
last is 8 inc it and return
//999
all are 999 change all to 0 ie 000 no need to copy A to B just hcange 0
B[0]=1
reurn B*/