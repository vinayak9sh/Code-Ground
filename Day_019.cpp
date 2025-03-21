// Day_019

// Problem 01 : Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
// Code:-

class Solution {
public:
    int maxDepth(string s) {
        int maxp = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){count++;}
            else if(s[i] == ')'){
                maxp = max(count, maxp);
                count--;
            }
        }
        return maxp;
    }
};

// TC = O(N)
// SC = O(1)
// Approach: count succeeded when opening parentheses appears and when closing parantheses appears maxp(defining maximum parentheses depth) is replaced with maximum of count and maxp and count preceeded as parentheses closes.. and then maxp was returned.

// Problem 02 : Roman to Integer
// https://leetcode.com/problems/roman-to-integer/description/
// Code:-

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romap= {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int val = 0;
        for(int i = 0; i < s.length(); i++){
            if(i < s.length() - 1 && romap[s[i]] < romap[s[i+1]]){
                val -= romap[s[i]];
            }
            else{val += romap[s[i]];}
        }
        return val;
    }
};

// TC = O(N)
// SC = O(1)
// Approach: mapped each roman character to its respective integer value and if next index is greater than the previous the integer value for present iteration roman no. is decremented from the ans.. else the value is added to the ans(val). 
