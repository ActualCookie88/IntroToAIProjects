#pragma once
#include <vector>

using std::vector;

int uniformHeuristic(const vector<vector<int>>& puzzle);
int misplacedHeuristic(const vector<vector<int>>& puzzle);
int manhattanHeuristic(const vector<vector<int>>& puzzle);