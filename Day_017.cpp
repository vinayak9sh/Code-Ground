// Day_017

// Problem 01 : Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/
// Code:-

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i;
        int hash1[256] = {0};
        int hash2[256] = {0};
        for(i = 0; i < s.size(); i++){
            if(hash1[s[i]] == 0 && hash2[t[i]] == 0){
                hash1[s[i]] = t[i];
                hash2[t[i]] = s[i];
            } 
            else{
                if(hash1[s[i]] != t[i] || hash2[t[i]] != s[i]){return false;}
            }
        }
        return true;
    }
};

// TC = O(N)
// SC = O(1)
// Approach : By starting with both strings simultaneously, we stored the ith letter of 't' string to ith index of hash1(hash table) corresponding to ith letter of 's' string and vice versa.
//            if this mapping is found to be violated in further iterations, then the strings would not result into isomorphic strings, so returned false in that condition and if this mapping is not
//            violated anywhere then returned true.

// Problem 02 : Remove outermost parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/description/
// Code:-

class Solution {
public:
    string removeOuterParentheses(string s) {
        string st = "";
        int i, counter = -1;
        for(i = 0; i < s.size(); i++){
            if(s[i] == '('){counter++;}
            if(counter > 0){
                st.push_back(s[i]);
            }
            if(s[i] == ')'){counter--;}
        }
        return st;
    }
};

// TC = O(N)
// SC = O(1)
// Approach : I observed the open parentheses(keeping in mind outer parentheses), if there are inner parentheses then, we pushed only inner parentheses into the empty string 'st' leaving outerloops..
