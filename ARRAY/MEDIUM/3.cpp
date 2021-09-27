/*1395. Count Number of Teams
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 
Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.*/
//Brute force TLE aa jayega
// o(n3) 10^5 * 10^5 * 10^5 = 10^15
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        vector<int> ans;
        int n = rating.size();

        int count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (rating[i] < rating[j] and rating[j] < rating[k])
                    {
                        count++;
                        continue;
                    }
                    if (rating[i] > rating[j] and rating[j] > rating[k])
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
//brute force TLE aa jayega
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        vector<int> ans;
        int n = rating.size();

        int count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (rating[i] < rating[j] and rating[j] < rating[k])
                    {
                        ans.push_back(rating[i]);
                        ans.push_back(rating[j]);
                        ans.push_back(rating[k]);
                        continue;
                    }
                    if (rating[i] > rating[j] and rating[j] > rating[k])
                    {
                        ans.push_back(rating[i]);
                        ans.push_back(rating[j]);
                        ans.push_back(rating[k]);
                    }
                }
            }
        }
        return ans.size() / 3;
    }
};
//thoda ache se kiya try
class Solution
{
public:
    int count = 0;
    int numTeams(vector<int> &rating)
    {

        for (int i = 0; i < rating.size() - 2; i++)
        {
            for (int j = i + 1; j < rating.size() - 1; j++)
            {
                helper(rating, i, j);
            }
        }
        return count;
    }

    void helper(vector<int> &rating, int i, int j)
    {
        if (rating[i] > rating[j])
        {
            for (int k = j + 1; k < rating.size(); k++)
            {
                if (rating[j] > rating[k])
                {
                    count++;
                }
            }
        }
        else if (rating[i] < rating[j])
        {
            for (int k = j + 1; k < rating.size(); k++)
            {
                if (rating[j] < rating[k])
                {
                    count++;
                }
            }
        }
    }
};
//uppar vala tarika array banake
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int N = rating.size();
        vector<int> larger(N, 0);
        vector<int> smaller(N, 0);

        for (int j = 0; j < N - 1; j++)
            for (int k = j + 1; k < N; k++)
            {
                if (rating[j] > rating[k])
                    larger[j]++;
                else //if(rating[i]<rating[j]) ~~this is for understanding the logic
                    smaller[j]++;
            }

        int team = 0;

        for (int i = 0; i < N - 2; i++)
            for (int j = i + 1; j < N - 1; j++)
            {
                if (rating[i] > rating[j])
                    team += larger[j];
                else //if(rating[i]<rating[j]) ~~this is for understanding the logic
                    team += smaller[j];
            }

        return team;
    }
};
//most optimized solution
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int count = 0;
        int n = rating.size();
        for (int i = 1; i < n - 1; i++)
        {
            int lessLeft = 0;
            int greatLeft = 0;
            int greatRight = 0;
            int lessRight = 0;
            //for left  part
            for (int j = 0; j < i; j++)
            {
                if (rating[j] > rating[i])
                    greatLeft++;
                else
                    lessLeft++;
            }
            //for right  part
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] > rating[i])
                    greatRight++;
                else
                    lessRight++;
            }
            count += lessLeft * greatRight + lessRight * greatLeft;
        }
        return count;
    }
};