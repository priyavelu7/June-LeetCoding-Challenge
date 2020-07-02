/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
class TrieNode{
  public:
  TrieNode* children[26];
  bool isEnd;
  string word;
};
class Solution {
public:
TrieNode* getNode(){
  TrieNode *node=new TrieNode();
  node->isEnd=false;
  node->word="";
  for(int i=0;i<26;i++)
    node->children[i]=NULL;
  return node;
}
void buildTrie(TrieNode *root, vector<string> &words){
  for(string x:words){
    TrieNode* temp=root;
    for(int i=0;i<x.length();i++){
      int idx=x[i]-'a';
      if(temp->children[idx]==NULL)
        temp->children[idx]=getNode();
      temp=temp->children[idx];
    }
    temp->isEnd=true;
    temp->word=x;
  }
}
void dfs(vector<vector<char>> &board, int i, int j, TrieNode *root, set<string> &res){
  if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='.') return;
  char c=board[i][j];
  if(root->children[c-'a']==NULL) return;
  root=root->children[c-'a'];
  if(root->word!=""){ 
    res.insert(root->word);
    root->word="";
  }
  board[i][j]='.';
  dfs(board,i-1,j,root,res);
  dfs(board,i,j-1,root,res);
  dfs(board,i+1,j,root,res);
  dfs(board,i,j+1,root,res);
  board[i][j]=c;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  TrieNode *root=getNode();
  buildTrie(root,words);
  set<string> res;
  for(int i=0;i<board.size();i++)
  for(int j=0;j<board[0].size();j++)
    dfs(board,i,j,root,res);
  vector<string> resvec;
  for(auto x:res) resvec.push_back(x);
  return resvec;
}
};
