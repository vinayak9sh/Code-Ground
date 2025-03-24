// Day_020

// Problem 01: Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Code:-

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for (int i=0;i<s.size();++i){
            if (s[i]=='('){
                st.push(s[i]);
            } else{
                char l=(st.size()==0)? ' ' : st.top();
                if (l=='('){
                    st.pop();
                } else{
                    st.push(s[i]);
                }
            }

        }
        int c=st.size();
        return c;
    }
};

// TC = O(N)
// SC = O(N)
// Approach: The code uses a stack to track unmatched parentheses in the given string. It pushes opening brackets `(` onto the stack and removes them when a matching `)` is found; otherwise, it pushes `)` onto the stack. The final stack size represents the minimum number of insertions needed to make the string valid.


// Problem 02 : Sum of Beauty of All Substrings
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Code:-

class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        
        for (int i = 0; i < s.size(); i++) {
            map<char, int> mpp;
            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;
                if (j - i >= 2) {
                    int maxfreq = INT_MIN;
                    int minfreq = INT_MAX;
                    
                    for (auto it : mpp) {
                        maxfreq = max(maxfreq, it.second);
                        minfreq = min(minfreq, it.second);
                    }
                    
                    totalBeauty += (maxfreq - minfreq);
                }
            }
        }
        
        return totalBeauty;
    }
};

// TC = O(N^2)
// SC = O(1)
// Approach: Use an outer loop to fix the starting character and an inner loop to extend substrings while maintaining a frequency map. Once the substring length is at least 3, compute beauty as `maxfreq - minfreq` and add it to the total. Repeat for all substrings and return the total sum.
