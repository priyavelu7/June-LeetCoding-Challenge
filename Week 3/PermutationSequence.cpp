/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
*/
class Solution {
public:
string getPermutation(int n, int k) {
  int fact[10];
  fact[0]=fact[1]=1;
  for(int i=2;i<10;i++)
    fact[i]=i*fact[i-1];
  string res="",set="123456789";
  while(n>0){
    int p=(k-1)/fact[n-1];
    res+=set[p];
    set.erase(set.begin()+p);
    k=k-p*fact[n-1];
    n--;
  }
  return res;
}
};
