/*890. Find and Replace Pattern
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.
Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.*/
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        int n = pattern.size();
        vector<int> v;
        int p[26] = {0};
        for (int i = 0; i < n; i++)
        {
            p[patterns[i] - 'a'] = i + 1;
        }
        for (auto word : words)
        {
            if (word.size() != n)
                continue;
            bool flag = true;
            int w[26] = {0};
            for (int i = 0; i < n; i++)
            {
                w[words[i] - 'a'] = i + 1;
            }
            for (int i = 0; i < n; i++)
            {
                if (w[word[i] - 'a'] != p[pattern[i] - 'a'])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                v.push_back(word);
            }
        }
        return v;
    }
};
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> v;
    for (int i = 0; i < words.size(); i++)
    {
        int hashmap1[256] = {0};
        int hashmap2[256] = {0};
        bool flag = true;
        for (int j = 0; j < pattern.length(); j++)
        {
            if (hashmap1[pattern[j]] != hashmap2[words[i][j]])
            {
                flag = false;
                break;
            }
            hashmap1[pattern[j]] = j + 1;
            hashmap2[words[i][j]] = j + 1;
        }
        if (flag)
            v.push_back(words[i]);
    }
    return v;
}
