#include "Puzzle.hpp"
#include <algorithm>

// helper
string puzzleToString(const vector<vector<int>>& p){
    string s;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            s += std::to_string(p[i][j]);
    return s;
}


// generate all possible states
vector<vector<vector<int>>> expand(const vector<vector<int>>& puzzle) {
    vector<vector<vector<int>>> children; // list of 2D puzzles 
    int emptyRow = -1;
    int emptyCol = -1;

    // coordinates for empty space
    for(int row = 0; row < 3; row++) { 
        for(int col = 0; col < 3; col++) {
            if(puzzle[row][col] == 0) {
                emptyRow = row;
                emptyCol = col;
                break;
            }
        }
        if(emptyRow != -1) break;
    }

    // directions = {up, left, down, right}
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};

    // check for possible moves
    for(int k = 0; k < 4; k++) {
        int row = emptyRow + delRow[k];
        int col = emptyCol + delCol[k];

        // within puzzle bounds
        if(row >= 0 && row < 3 && col >= 0 && col < 3) {
            vector<vector<int>> newPuzzle = puzzle;

            // move tile to blank (swap empty and adjacent tile)
            std::swap(newPuzzle[emptyRow][emptyCol], newPuzzle[row][col]);

            // append new state
            children.push_back(newPuzzle);
        }
    }

    return children;
}
