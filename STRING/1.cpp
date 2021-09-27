//Defanging an IP Address
/*Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"*/
#include <bits/stdc++.h>
using namespace std;

string defangIP(string address)
{
    string toReturn = "";
    for (int i = 0; i < address.size(); i++)
    {
        if (address[i] == '.')
            toReturn += "[']";
        else
            toReturn += address[i];
    }
    return toReturn;
}

int main()
{
    string str;
    getline(cin, str);
    cout << defangIP(str) << endl;
}