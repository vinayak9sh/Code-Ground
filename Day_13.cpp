Day_13

Problem 01 : Ceil The Floor
https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM
Code:-

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int, int> flce;
	int mid;
	int low = 0;
	int high = a.size() - 1;
	int soln_f = -1;
	while(low <= high){
		mid = low + (high - low) / 2;
		if(a[mid] <= x){
			soln_f = a[mid];
			low = mid + 1;
		}
		else{high = mid - 1;}
	}

  low = 0;
	high = a.size() - 1;
	int soln_c = -1;
	while(low <= high){
		mid = low + (high - low) / 2;
		if(a[mid] >= x){
			soln_c = a[mid];
			high = mid - 1;
		}
		else{low = mid + 1;}
	}

	flce = make_pair(soln_f, soln_c);
	return flce;
}

TC = O(LogN)
SC = O(1)
Approach : Binary Search(conditions for floor and ceil)

Problem 02 : Find Minimum in Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
Code:-

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int soln = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid]){
                soln = min(soln, nums[low]);
                low = mid + 1;
            }
            else{
                soln = min(soln, nums[mid]);
                high = mid - 1;
            }
        }
        return soln;
    }
};

TC = O(LogN)
SC = O(1)
Approach : Binary Search

Problem 03 : Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/
Code:-

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){return mid;}
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{low = mid + 1;}
            }
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{high = mid - 1;}
            }
        }
        return -1;
    }
};

TC = O(LogN)
SC = O(1)
Approach : Binary Search
