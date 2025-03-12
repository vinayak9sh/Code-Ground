// Day_11

// Problem 01 : Pascal's Triangle(leetcode 118)
// https://leetcode.com/problems/pascals-triangle/submissions/1571036958/
// Code:-

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vecna(numRows);
        int i, j;
        for(i = 0; i < numRows; i++){
            vecna[i].resize(i+1);
            vecna[i][0] = 1;
            vecna[i][i] = 1; 
            for(j = 1; j < i; j++){
                vecna[i][j] = vecna[i-1][j-1] + vecna[i-1][j];
            }
        }
        return vecna;
    }
};

// TC = O(N^2)
// SC = O(N^2)
// Approach : since column size is changing it is changed dynamically for each row and as the pattern is formed by the addition of two numbers from previous row.. the same logic is applied and 
//            the result is stored in the current row.

// Problem 02 : Rotate Image(leetcode 48)
// https://leetcode.com/problems/rotate-image/submissions/1571090378/
// Code:-

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j;
        for(i = 0; i < matrix.size()/2; i++){
            swap(matrix[i], matrix[matrix.size()-i-1]);
        }
        for(i = 0; i < matrix.size(); i++){
            for(j = i+1; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

// TC = O(N^2)
// SC = O(1)
// Approach : After analyzing change of image, the approach is that first I swapped the ith and (n-i-1)th element within matrix and transposed the matrix.

// Problem 03 : Spiral Matrix(leetcode 54)
// https://leetcode.com/problems/spiral-matrix/submissions/1571157547/
// Code:-

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vecna;
        if(matrix.empty() || matrix[0].empty()){return vecna;}
        int i, j;
        int top = 0;
        int left = 0;
        int bottom = matrix.size()-1;
        int right = matrix[0].size()-1;

        while(top <= bottom && left <= right){
            for(i = left; i <= right; i++){
                vecna.push_back(matrix[top][i]);
            }
            top++;

            for(i = top; i <= bottom; i++){
                vecna.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                for(i = right; i >= left; i--){
                    vecna.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){
                for(i = bottom; i >= top; i--){
                    vecna.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return vecna;
    }
};

// TC = O(M X N)
// SC = O(M X N)
 // where M, N are number of rows and columns of given matrix respectively.
// Approach : if matrix or matrix's column is empty, then empty vector is returned.. else.. conditions are applied based on spiral path and simultaneously pushing the elements while traversing 
//            the spiral path.. at last the vector is returned.
