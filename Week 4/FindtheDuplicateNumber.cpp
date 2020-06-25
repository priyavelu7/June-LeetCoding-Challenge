/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
*/
class Solution {
public:
int findDuplicate(vector<int>& nums) {
  int slow=0,fast=0;
  while(fast<nums.size()&&nums[fast]<nums.size()){
    slow=nums[slow];
    fast=nums[nums[fast]];
    if(slow==fast)  break;
  }
  slow=0;
  while(slow!=fast){
    slow=nums[slow];
    fast=nums[fast];
  }
  return fast;
}
};
