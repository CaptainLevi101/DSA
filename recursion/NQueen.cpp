// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9
#include <bits/stdc++.h>
class Solution {
private:
 unordered_set<int>cols; //for columns
 unordered_set<int>negDig; //for negative diagonals  R-C
 unordered_set<int>posDig; //for positive dig;  R+C
void backTrack(int n,int row,vector<vector<string>>&res,vector<string>&board){
    if(row==n){
        res.push_back(board);
        return ;
    }
    for(int col=0;col<n;col++){
        if(cols.find(col)!=cols.end() or negDig.find(row-col)!=negDig.end() or posDig.find(row+col)!=posDig.end()){
            continue;
        }
        cols.insert(col);
        negDig.insert(row-col);
        posDig.insert(row+col);
        board[row][col]='Q';
        backTrack(n,row+1,res,board);
        cols.erase(col);
        negDig.erase(row-col);
        posDig.erase(row+col);
        board[row][col]='.';
    }
}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        backTrack(n,0,res,board);
        return res;
    }
};