/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
class Solution {
public:
    void check(vector<vector<char>>& board,int i,int j){
      int m=board.size();
      int n=board[0].size();
      if(i<0 || j<0 || i>=m || j>=n) return;
      if(board[i][j]=='O')
        board[i][j]='*';
      else return;        
      check(board,i+1,j);
      check(board,i-1,j);
      check(board,i,j+1);
      check(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
      int m=board.size();
      if(m==0) return;
      int n=board[0].size();
      for(int i=0;i<m;i++){
        if(board[i][0]=='O')
          check(board,i,0);
        if(board[i][n-1]=='O')
          check(board,i,n-1);
      }
      for(int i=0;i<n;i++){
        if(board[0][i]=='O')
          check(board,0,i);
        if(board[m-1][i]=='O')
          check(board,m-1,i);
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(board[i][j]=='O')
            board[i][j]='X';
          else if(board[i][j]=='*')
            board[i][j]='O';
      }  
    }
  }
};
