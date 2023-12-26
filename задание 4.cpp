#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    int i, j;
     
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
     
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}


bool solveNQueensUtil(int col, int n, vector<vector<int>>& board, vector<vector<vector<int>>>& result) {
    if (col == n) {
        result.push_back(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueensUtil(col + 1, n, board, result) || res;
            board[i][col] = 0; 
        }
    }
    return res;
}


vector<vector<vector<int>>> solveNQueens(int n) {
    vector<vector<vector<int>>> result;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueensUtil(0, n, board, result);
    return result;
}


int main() {
    string choice;
    do {
        int n = 4; 
        vector<vector<vector<int>>> solutions = solveNQueens(n);
        cout << "Solutions for " << n << " queens on the board " << n << "x" << n << ":\n";
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                for (int val : row) {
                    cout << val << " ";
                }
                cout << endl;
            }
            cout << "-----------------\n";
        }
        cout << "Run again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");
    return 0;
}