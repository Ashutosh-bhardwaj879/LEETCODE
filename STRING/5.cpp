#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <string>
using namespace std;

int main()
{
    string cad1;

    char vowels[] = {'A', 'O', 'E', 'U', 'I', 'a', 'o', 'e', 'u', 'i'};
    int size = sizeof(vowels) / sizeof(vowels[0]);
    getline(cin, cad1);
    for (int i = 0; cad1[i] != '\0'; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (cad1[i] == vowels[j])
            {
                //this will erase vowels at ith index ie in original string
                // .begin() means 0 index 
                cad1.erase(cad1.begin() + i);
            }
        }
        //convert string to lowercase
        cad1[i] = tolower(cad1[i]);
    }
    //string
    //*s*t*r*n*g
    //* is at every even position
    for (int k = 0; cad1[k] != '\0'; k++)
    {
        if (k % 2 == 0)
        {
            //k = even pos
            //1 means only 1 element to insert
            //* means star
            cad1.insert(k, 1, '*');
        }
    }

    cout << cad1 << endl;
}