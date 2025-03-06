Q1:Distribute Money to Maximum Children
https://leetcode.com/problems/distribute-money-to-maximum-children/description/?envType=problem-list-v2&envId=math
class Solution {
public:
    int distMoney(int money, int children) {
        int count = 0; 
        if(money < children){
            return -1;
        }
        money -= children;
        while(money >= 7 && count < children) {
            money -= 7;
            count++;
        }
        if(money == 3 && count == children - 1){count--;}
        if(money > 0 && count == children){count--;}
        return count;
    }
};
T.C: O(1)
SC:O(1)
approach: 

