/*67. Add Binary
Given two binary strings a and b, return their sum as a binary string.
Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/
//https://www.youtube.com/watch?v=SwPXgTiv8Ag
/*ab c r  as(a+b+c)   as = actual sumr = rsult c = carry
  00 0 0   0
  00 1 1   1
  01 1 0   2
  11 1 1   3
*/
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;    //isme save hoga result stirng
        int carry = 0; //ye carry
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0)
        {
            int sum = carry; //bar bar hum sum ko initialize kar rah ehain cary se aur carry
            //har bar change ho rahi hai
            if (i >= 0)
                sum += a[i--] - '0'; //-'0' taki ascii value similar ahe
            if (j >= 0)
                sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;   //if sum2 or sum3 carry 1 as above
            res += to_string(sum % 2); //%2 isliye ki agar sum 0 to string 0
            //agar sum 1 toh stirng mein q agar sum2 to stirng mein 0 aur agr sum 3 to stirng
            // mein 1(string = res stirng)
        }
        if (carry) //agar jaate jaate carry bach gayi to append kardo use
            res += to_string(carry);
        reverse(res.begin(), res.end()); //reverse ke lie
        return res;
    }
};