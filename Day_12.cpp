// Day_12

// Problem 01 : Binary Search
// https://leetcode.com/problems/binary-search/submissions/1572684962/
// Code:-

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){return mid;}
            else if(nums[mid] > target){high = mid - 1;}
            else{low = mid + 1;}
        }
        return -1;
    }
};

// TC = O(LogN)
// SC = O(1)
// Approach : Divide & Conquer

// Problem 02 : Find First & Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Code:-

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vecna;
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){low = mid + 1;}
            else{high = mid - 1;}
        }
        vecna.emplace_back(first);

        low = 0;
        high = nums.size() - 1;
        int last = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){low = mid + 1;}
            else{high = mid - 1;}
        }
        vecna.emplace_back(last);
        return vecna;
    }
};

// TC = O(LogN)
// SC = O(1)
// Approach : Binary search is applied two times(first it found its occurence of the element by shifting high = mid - 1 while second searches for its last occurence by shifting low to mid + 1..

// Problem 03 : Search Insert Position
// https://leetcode.com/problems/search-insert-position/
// Code:-

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int soln = nums.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                soln = mid;
                high = mid - 1;
            }
            else{low = mid + 1;}
        }
        return soln;
    }
};

// TC = O(LogN)
// SC = O(1)
// Approach : Binary search + lower bound wrt target is the desired index..
