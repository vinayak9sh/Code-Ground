// Day_035

// Problem 01: Subsets
// https://leetcode.com/problems/subsets/
// Code:-

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;        
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }    
};

// TC = O(N2^N)
// SC = O(N)
// Approach: The code uses recursion to explore all possible combinations of including or excluding each element from the current subset. When all elements have been considered, it adds the formed subset to the result list.

// Problem 02: Generate Parentheses
// https://leetcode.com/problems/subsets/
// Code:-

class Solution {
public:
    vector<string> res;
    string str;
    int N;

    vector<string> generateParenthesis(int n) {
        N = n;
        backtrack(0, 0);
        return res;
    }

    void backtrack(int open, int close) {
        if (open == N && close == N) {
            res.push_back(str);
            return;
        }

        if (open < N) {
            str.push_back('(');
            backtrack(open + 1, close);
            str.pop_back();
        }

        if (close < open) {
            str.push_back(')');
            backtrack(open, close + 1);
            str.pop_back();
        }
    }
};

// TC = O(2^N)
// SC = O(N)
// Approach: The code uses backtracking to generate all valid combinations by adding '(' and ')' only when it maintains the balance of parentheses. It adds a valid string to the result when both opening and closing counts reach n.
