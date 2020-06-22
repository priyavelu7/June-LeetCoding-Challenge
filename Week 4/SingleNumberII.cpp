/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/
class Solution {
public:
int singleNumber(vector<int>& nums) {
  int x1=0,x2=0,mask;
  for(int i=0;i<nums.size();i++){
    x2^=(x1&nums[i]);
    x1^=nums[i];
    mask=~(x1&x2);
    x1&=mask;
    x2&=mask;
  }
  return x1;
}
};
