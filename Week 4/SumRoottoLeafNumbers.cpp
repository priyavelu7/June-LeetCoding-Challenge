/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void sumCalc(TreeNode* root,int curSum,int &sum){
  if(root==NULL) return;
  curSum=curSum*10+root->val;
  if(!root->left&&!root->right){
    sum+=curSum;
    return;
  }
  sumCalc(root->left,curSum,sum);
  sumCalc(root->right,curSum,sum);
}

int sumNumbers(TreeNode* root) {
  if(root==NULL) return 0;
  int curSum=0,sum=0;
  sumCalc(root,curSum,sum);
  return sum;
}
};
