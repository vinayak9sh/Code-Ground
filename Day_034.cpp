// Day_034

// Problem 01: Count Good Numbers
// https://leetcode.com/problems/count-good-numbers/
// Code:-

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evens = (n + 1) / 2;
        long long odds = n / 2;

        return (modPow(5, evens, MOD) * modPow(4, odds, MOD)) % MOD;
    }
};

// TC = O(LogN)
// SC = O(1)
// Approach: The function calculates the number of "good numbers" of length n by raising 5 to the power of even-position digits and 4 to the power of odd-position digits using fast modular exponentiation. The results are multiplied and taken modulo 1e9+7 to get the final count.

Problem 02: Sort a stack
https://www.geeksforgeeks.org/problems/sort-a-stack/1
Code:-

void insertElement(stack<int>&st, int ele){
    if(st.size()==0 || st.top()<=ele){
        st.push(ele);
        return;
    }
    else{
        int temp = st.top();
        st.pop();
        insertElement(st,ele);
        st.push(temp);
    }
}

void SortedStack :: sort()
{
   //Your code here
   if(s.size()==0) return;
   int temp = s.top();
   s.pop();
   sort();
   insertElement(s,temp);
}

// TC = O(N^2)
// SC = O(N)
// Approach: The sort() function recursively removes the top elements to reach the bottom of the stack. It then uses insertElement() to place each element back in sorted order by recursively finding its correct position.








