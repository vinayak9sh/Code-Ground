// Day_024

// Problem 01: Push Dominoes
// https://leetcode.com/problems/push-dominoes/description/?envType=problem-list-v2&envId=string
// Code:-

string pushDominoes(string s) {
    int N = s.size(), right = -1;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'L') {
            if (right == -1) { 
                // Step 2
                for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                  s[j] = 'L';  
                } 
            } else {
                // Step 8
                for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                    s[j] = 'R';
                    s[k] = 'L';
                } 
                right = -1;
            }
        } else if (s[i] == 'R') {
            if (right != -1) {
                for (int j = right + 1; j < i; ++j) s[j] = 'R';
            }
            right = i;
        }
    }
    if (right != -1) {
        for (int j = right + 1; j < N; ++j) s[j] = 'R';
    }
    return s;
}

// TC = O(N)
// SC = O(1)
// Approach: This approach processes the dominoes in a single pass while making necessary updates based on 'L' and 'R'. When encountering 'L', it either fills leftward or balances with a previous 'R' using two pointers, and when encountering 'R', it ensures all intermediate '.' are converted to 'R'.

// Problem 02: Partition Labels
// https://leetcode.com/problems/partition-labels/description/?envType=problem-list-v2&envId=string
// Code:-

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;

        // Store the last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]] = i;
        }

        vector<int> res;
        int end = mp[s[0]], start = 0;

        for (int i = 1; i <= s.length(); i++) {
            if(i <= end) {
                if(mp[s[i]] > end) {
                    end = mp[s[i]];
                }
            } else {
                res.push_back(end - start + 1);
                start = i;
                end = mp[s[i]];
            }
        }

        return res;
    }
};

// TC = O(N)
// SC = O(1)
// Approach:The last index of each character is stored in an unordered map to determine the farthest boundary for partitions. The string is traversed while the partition's end is updated, and when this end is reached, the partition size is recorded, and a new one is started.
