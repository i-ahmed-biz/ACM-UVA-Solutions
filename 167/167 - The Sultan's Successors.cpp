#include <iostream>
#include <iomanip>

using namespace std;

const int COLS = 8;
const int ROWS = 8;

int sum = 0;

int calSum(int board[][COLS], int weight[][COLS]) {
    int totSum = 0;
    for(int i = 0; i < ROWS; i++) {
        for( int j = 0; j < COLS; j++) {
            if(board[i][j]) {
                totSum += weight[i][j];
            }
        }
    }

    return totSum;
}

bool isSafe(int board[][COLS], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    for (i=row, j=col; j>=0 && i<ROWS; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueen(int board[][COLS], int weight[][COLS], int col) {
    if (col == COLS)
    {
        int calcualedSum = calSum(board, weight);
        if(sum < calcualedSum) {
            sum = calcualedSum;
        }
        return true;
    }

    bool res = false;

    for (int i = 0; i < ROWS; i++)
    {
        if ( isSafe(board, i, col) )
        {
            board[i][col] = 1;
            res = solveNQueen(board, weight, col + 1) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

int main() {
    int T, board[ROWS][COLS], weight[ROWS][COLS];
    cin >> T;
    while(T--) {
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                cin>>weight[i][j];
                board[i][j] = 0;
            }
        }
        sum = 0;
        solveNQueen(board, weight, 0);
        cout<<setw(5)<<setiosflags(ios::right)<<sum<<endl;
    }

    return 0;
}
