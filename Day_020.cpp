// Day_020

// Problem 01 : Sort Characters by Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/description/
// Code:-

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        string st = "";
        for(char c : s){mpp[c]++;}
        vector<pair<char, int>> chfreq(mpp.begin(), mpp.end());
        sort(chfreq.begin(), chfreq.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });
            
        for(const auto& item : chfreq){
            st.append(item.second, item.first);
        }
        return st;
    }
};

// TC = O(NLogN)
// SC = O(N)
// Approach: first of all stored the frequency of respective letters in a string.. then after storing it in a vector reverse sorted based on frequency, then appended to the string 'st' according to frequencies and returned the string.

