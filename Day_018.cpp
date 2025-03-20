// Day_018

// Problem 01 : Valid Anagram
// https://leetcode.com/problems/valid-anagram/
// Code:-

class Solution {
public:
    bool isAnagram(string s, string t) {
       int mpp1[256] = {0};  
       int mpp2[256] = {0}; 
       int i;
       if(s.size() != t.size()){return false;}
       for(i = 0; i < s.size(); i++){
        mpp1[s[i]]++;
        mpp2[t[i]]++;
       } 
        for(i = 0; i < s.size(); i++){
            if(mpp1[s[i]] != mpp2[s[i]]){return false;}
        }
        return true;
    }
};

// TC = O(N)
// TC = O(1)
// Approach: created two maps to store key(string characters) and its values(as their respective occurrences) for both strings.. then presence of each character of string 's' is matched with string 't'
//           if it does not match in both strings false is returned(also when strings are of different length).. otherwise true is returned.

// Problem 02 : Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// Code:-

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){return "";}
        int i;
        string s = strs[0];
        int slen = s.length();
        for(i = 1; i < strs.size(); i++){
            while(slen > strs[i].length() || s != strs[i].substr(0, slen)){
                slen--;
                if(slen == 0){return "";}
                s = s.substr(0, slen);
            }
        }
        return s;
    }
};

// TC = O(M X N) where m is the no. of strings and n is the length of first string
// TC = O(1)
// Approach: we started with the first string assuming it as longest prefix.. then compared it with further strings to get the longest common prefix.. else returned empty string(when strs is empty or not common prefix is found)  and to find common prefix we introduced a while() loop which is reducing the string acccording to the conditions
