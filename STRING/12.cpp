/*125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.
Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:
Input: "race a car"
Output: false*/
//https://leetcode.com/problems/valid-palindrome/
//https://www.youtube.com/watch?v=028pTf2kBFI
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.length() <= 1) //ye empty string ya sirf 1 digit vala case sambhal lega
            return true;
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            while (start < end && !isalnum(s[start])) //agar alpha numberic
                                                      //nahi hia mtab space ignore karo aage badho
                start++;
            while (start < end && !isalnum(s[end])) //agar alnum nahi hia
                                                    //matlab space ignore karo aage badho
                end--;
            if (start < end && tolower(s[start]) != tolower(s[end]))
                //manle agar bada character hain A to a ban jayega agar equal nahi hai
                //to false seedhi baat
                return false;
            start++;
            end--;
        }
        //loo ke bahar aa gaya matlab equal hi hoga
        return true;
    }
};