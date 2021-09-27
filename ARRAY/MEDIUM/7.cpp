//https://www.youtube.com/watch?v=AFtXLUn_TZg
//https://www.geeksforgeeks.org/stddistance-in-c/
/*969. Pancake Sorting
Medium
Given an array of integers arr, sort the array by performing a series of pancake flips.

In one pancake flip we do the following steps:

Choose an integer k where 1 <= k <= arr.length.
Reverse the sub-array arr[0...k-1] (0-indexed).
For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.

Example 1:

Input: arr = [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: arr = [3, 2, 4, 1]
After 1st flip (k = 4): arr = [1, 4, 2, 3]
After 2nd flip (k = 2): arr = [4, 1, 2, 3]
After 3rd flip (k = 4): arr = [3, 2, 1, 4]
After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
Example 2:

Input: arr = [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.*/
/*Let`s take an example:
  
    5  6  3  4  1  2
	
	Algorithms follows like this:
	In each loop , We will try to place max element in the correct position.
	Run i from N-1 to 0
	1. Find position of max element 'j' and reverse upto 'j' . For example 6, so j=1(0th indexed) is max here, Now reverse array till j=1;
	    6  5  3  4  1   2
	2.Now reverse till the 	i'th index
	   2  1  4   3  5  6
	   Next loop, i=N-2.....repeat 1 and 2
	Note: If the max element already in correct position just continue;
	Here 5 is in correct position, just continue,no need to do anything
	
	Next i becomes N-3=3
	find max element till index 3
	
	1. we have , 4 as max element, reverse upto that.
	
	 2  1  4   3  5  6
	 4  1  2   3  5  6
	 
	2. Reverse upto 'i'=3 (0th indexed)
    3  2   1   4  5   6
	
	Just repeat...Happy Solving!*/
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ans;
        int N = arr.size();
        for (int i = N - 1; i >= 0; i--)
        {
            int j = max_element(arr.begin(), arr.begin() + i + 1) - arr.begin();
            if (j == i)
                continue;
            ans.push_back(j + 1);
            reverse(arr.begin(), arr.begin() + j + 1);
            ans.push_back(i + 1);
            reverse(arr.begin(), arr.begin() + i + 1);
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> res;
        int N = arr.size();
        for (int i = N; i > 0; i--)
        {
            auto currMax = max_element(arr.begin(), arr.begin() + i);
            reverse(arr.begin(), arr.begin() + distance(arr.begin(), currMax) + 1);
            res.push_back(distance(arr.begin(), currMax) + 1);
            reverse(arr.begin(), arr.begin() + i);
            res.push_back(i);
        }
        return res;
    }
};
class Solution
{
public:
    void flip(vector<int> &arr, int k)
    {
        reverse(arr.begin(), arr.begin() + k);
    }
    int findmax(vector<int> &arr, int k)
    {
        int maxi = INT_MIN, index = 0;
        for (int i = 0; i <= k; i++)
        {
            if (arr[i] > maxi)
            {
                index = i;
                maxi = arr[i];
            }
        }
        return index;
    }
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> res;
        for (int i = arr.size() - 1; i > 0; i--)
        {
            int pos = findmax(arr, i);
            flip(arr, pos + 1);
            flip(arr, i + 1);
            res.push_back(pos + 1);
            res.push_back(i + 1);
        }
        return res;
    }
};