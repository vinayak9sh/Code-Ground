// Day_015

// Problem 01 : K-th element of two Arrays
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array
// Code:-

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        vector<int>ans;
        while(i < n && j < m){
            if(a[i] < b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else{
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(a[i]);
            i++;
        }
        while(j<m){
            ans.push_back(b[j]);
            j++;
        }
        if(ans.size()<k) return -1;
        return ans[k-1];
    }
};

// TC = O(M+N)
// SC = O(M+N)
// Approach : This code merges two sorted arrays into a single sorted array using a two-pointer approach and returns the k-th smallest element.

// Problem 02 : Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/
// Code:-

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] == target){return true;}
            else if(matrix[row][col] < target){low = mid + 1;}
            else{high = mid - 1;}
        }
        return false;
    }
};

// TC = O(Log(M X N))
// SC = O(1)
// Approach : Algorithm treats the 2D matrix as a 1D array, applying binary search by converting midpoints into row and column indices, it locates the target.

// Problem 03 : Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/
// Code:-

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target){return true;}
            else if(matrix[row][col] < target){row++;}
            else{col--;}
        }
        return false;
    }
};

// TC = O(M+N)
// SC = O(1)
// Approach : 
// Approach : Algorithm starts from the top-right corner of the matrix and moves left if the current element is larger than the target or down if it is smaller, it eliminates one row
//            or column at each step until the target is found or the search space is exhausted.
