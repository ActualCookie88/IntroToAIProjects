#include "../header/Heuristics.hpp"
#include "../header/globals.hpp"
#include <cmath>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;

// h(n) = 0
int uniformHeuristic(const vector<vector<int>>& puzzle) {
    return 0;
}

// h(n) = # misplaced tiles
int misplacedHeuristic(const vector<vector<int>>& puzzle) {
    int count = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(puzzle[i][j] != solution[i][j] && puzzle[i][j] != 0) { // ignore empty
                count++;
            }
        }
    }
    return count;
}

// h(n) = sum of tile distances
int manhattanHeuristic(const vector<vector<int>>& puzzle) {
    int dist = 0;

    // loop thru each position
    for(int i = 0; i < 3; i++) { 
        for(int j = 0; j < 3; j++) {
            int position = puzzle[i][j];
            if(position != 0) { // ignore empty
                dist += abs(i - solPositions[position].first) + abs(j - solPositions[position].second);
            }
        }
    }

    return dist;
}