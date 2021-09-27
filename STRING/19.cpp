/*1704. Determine if String Halves Are Alike
Easy
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
Example 3:

Input: s = "MerryChristmas"
Output: false
Example 4:

Input: s = "AbCdEfGh"
Output: true*/
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                count1++;
            }
        }
        for (int i = n / 2; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' ||
                s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                count2++;
            }
        }
        return count1 == count2;
    }
};
//JAVA
class Solution
{
public
    boolean halvesAreAlike(String s)
    {
        String firstHalf = s.substring(0, s.length() / 2);
        String secondHalf = s.substring(s.length() / 2);
        return countVowels(firstHalf) == countVowels(secondHalf);
    }

private
    int countVowels(String str)
    {
        int count = 0;
        char ch[] = str.toCharArray();
        for (char c : ch)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                count++;
        }
        return count;
    }
}
