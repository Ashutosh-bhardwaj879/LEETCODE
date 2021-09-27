/*1512. Number of Good Pairs
Given an array of integers nums.
A pair (i,j) is called good if nums[i] == nums[j] and i < j.
Return the number of good pairs.
Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:
Input: nums = [1,2,3]
Output: 0*/
//  1111 count[1] = 4 ans +=4
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int ans = 0;
        int count[101] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (count[nums[i]] > 0) //123113 1-3 2-1 3-2 pelhle 1 gaya matlab 3
            //2+1 =3 fir 2-1 gya 1-- 0 matlab 0 fir 3-2 gaya 2-- matlab 1
            //3+0+1 = 4
            {                          //1111 = 4
                count[nums[i]]--;      //ye hote hi 4 nahi rahegi freq 1 ho jayegi aur fir add hoga
                ans += count[nums[i]]; //3+2+1 = 6
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int goodPairs = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    goodPairs++;
                }
            }
        }
        return goodPairs;
    }
};

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        vector<int> all(101);
        for (int i = 0; i < nums.size(); i++)
        {
            all[nums[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < 101; i++)
        {
            if (all[i] > 0)
            {
                ans += (all[i] * (all[i] - 1)) / 2;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
            ++umap[nums[i]];
        int c = 0;
        for (auto x : umap) //map is key value pair

        {
            int n = x.second;     //se vo frequency vali value niklegi
                                  //cout<<n;
            c += n * (n - 1) / 2; //manle 1 hui to bhi c 0 ho jayega
        }
        return c;
    }
};