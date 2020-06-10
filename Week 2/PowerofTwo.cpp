/*
Given an integer, write a function to determine if it is a power of two.

Example 1:
Input: 1
Output: true 
Explanation: 20 = 1
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(n>0 && (n&(n-1))==0)
        return true;
      return false;
    }
};
