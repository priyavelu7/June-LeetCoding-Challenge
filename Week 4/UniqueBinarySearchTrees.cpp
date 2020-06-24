/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
*/
class Solution {
public:
int numTrees(int n) {
  int dp[n+1];
  dp[0]=1;
  for(int i=1;i<=n;i++){
    dp[i]=0;
    for(int j=1;j<=i;j++){
      dp[i]+=dp[j-1]*dp[i-j];
      cout<<dp[i];a
    }cout<<endl;
  }
  return dp[n];
}
};
