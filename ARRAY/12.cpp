/*1773. Count Items Matching a Rule
You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.

 

Example 1:

Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
Example 2:

Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int index ;
        if(ruleKey.compare("type")==0)
            index=0;
        else if(ruleKey.compare("color")==0)
            index =1;
        else if(ruleKey.compare("name")==0)
            index =2;
        for(int i=0;i<items.size();i++)
        {
            if(items[i][index].compare(ruleValue)==0)
                count++;
        }
        return count;
    }
};


class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int index ;
        if(ruleKey=="type")
            index=0;
        else if(ruleKey=="color")
            index =1;
        else if(ruleKey=="name")
            index =2;
        for(int i=0;i<items.size();i++)
        {
            if(items[i][index] == ruleValue)
                count++;
        }
        return count;
    }
};


































