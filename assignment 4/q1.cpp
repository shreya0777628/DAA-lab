#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solveNQ(vector<int>& board, int row, int n) {
    if (row == n) return true;

    for (int col = 1; col <= n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if (solveNQ(board, row + 1, n))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<int> board(n);

    if (solveNQ(board, 0, n)) {
        for (int i = 0; i < n; i++)
            cout << board[i] << " ";
    }
    return 0;
}
