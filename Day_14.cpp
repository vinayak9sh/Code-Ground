// Day_14

// Problem 01 : Square Root
// https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root
// Code:-

class Solution {
  public:
    int floorSqrt(int n) {
        int low = 1;
        int high = n;
        int soln;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid * mid <= n){
                soln = mid;
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }
        return soln;
    }
};

// TC = O(LogN)
// SC = O(1)
// Approach : Binary Search(mid element square should be less than or equal to the given number)

Problem 02 : Koko Eating Bananas
https://leetcode.com/problems/koko-eating-bananas/description/
Code:-

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int soln, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            long long reqTime = TimeTaken(piles, mid);
            if(reqTime <= h){
                soln = mid;
                high = mid - 1;
            }
            else{low = mid + 1;}
        }
        return soln;
    }
    long long TimeTaken(vector<int>& vecna, int m);
};

long long Solution :: TimeTaken(vector<int>& vecna, int m){
    long long totalTime = 0;
    for(int i = 0; i < vecna.size(); i++){
        totalTime += ceil(double(vecna[i]) / m);
        }
    return totalTime;
}

// TC = O(Log(Max(Piles))*Piles.Size()) 
// SC = O(1)
// Approach : Binary Search(time taken is calculated upto which h holds and that mid index is returned)

// Problem 03 : Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// Code:-

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int soln;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long thresh = 0;
            for(int t : nums){
                thresh += ceil(double(t) / mid);
            }
            if(thresh <= threshold){
                soln = mid;
                high = mid - 1;
            }
            else{low = mid + 1;}
        }
        return soln;
    }
};

// TC = O(Log(Max(Nums))*Nums.Size()) 
// SC = O(1)
// Approach : Binary Search(thresh is calculated by dividing each value by mid of low and maximum element of nums each time and taking its ceil.. and checked condition for threshold)
