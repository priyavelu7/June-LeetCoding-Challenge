/*
Given a string s and a string t, check if s is subsequence of t.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
      int ind=0;
      for(int i=0;i<t.length();i++){
        if(t[i]==s[ind])
          ind++;
      }
      if(ind==s.length())
        return true;
      return false;
    }
};
