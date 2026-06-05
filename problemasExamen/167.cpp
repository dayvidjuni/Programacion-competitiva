#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int board[8][8];
int max_score;
int queens[8];

bool is_safe(int col, int row) {
    for (int i = 0; i < col; i++) {
        if (queens[i] == row || abs(queens[i] - row) == abs(i - col)) return false;
    }
    return true;
}

void solve(int col, int current_score) {
    if (col == 8) {
        if (current_score > max_score) max_score = current_score;
        return;
    }
    for (int row = 0; row < 8; row++) {
        if (is_safe(col, row)) {
            queens[col] = row;
            solve(col + 1, current_score + board[row][col]);
        }
    }
}

int main() {
    int k;
    if (cin >> k) {
        vector<int> total_outputs;
        while (k--) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    cin >> board[i][j];
                }
            }
            max_score = 0;
            solve(0, 0);
            total_outputs.push_back(max_score);
        }
        for (size_t i = 0; i < total_outputs.size(); i++) {
            cout << setw(5) << total_outputs[i] << endl;
        }
    }
    system("pause");
    return 0;
}