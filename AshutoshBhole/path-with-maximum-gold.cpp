/**
 * https://leetcode.com/problems/path-with-maximum-gold/
 * 
 * 1219. Path with Maximum Gold
Medium

In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

    Every time you are located in a cell you will collect all the gold in that cell.
    From your position you can walk one step to the left, right, up or down.
    You can't visit the same cell more than once.
    Never visit a cell with 0 gold.
    You can start and stop collecting gold from any position in the grid that has some gold.
 *
 **/

#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

int maxRow, maxCol;
unordered_map<int,int> visited;
vector<pair<int,int>> neighbours = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int getUniqueKey(pair<int,int> current) {
    return current.first * (maxRow + maxCol) + current.second;
}

bool isValid(pair<int,int> current, vector<vector<int>> &grid){
    if ((current.first >= 0 &&  current.first < maxRow) && (current.second >= 0 && current.second < maxCol)){
        if(grid[current.first][current.second] != 0){
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int getMax(pair<int,int> current, int val, vector<vector<int>> &grid){
    int maxVal = val;
    for(int i = 0; i < neighbours.size(); i++) {
        auto nxt = neighbours[i];
        auto next = make_pair(nxt.first + current.first, nxt.second + current.second);
        if(isValid(next, grid) && visited.find(getUniqueKey(next)) == visited.end()) {
            visited[getUniqueKey(next)]=1;
            int sum = val + grid[next.first][next.second];
            int val = getMax(next, sum, grid);
            if (val > maxVal) {
                maxVal = val;
            }
            visited.erase(getUniqueKey(next));
        }
    }
    return maxVal;
}


int getMaximumGold(vector<vector<int>>& grid) {
    int maxVal = 0;

    maxRow = grid.size();
    if (maxRow > 0 ) {
        maxCol = grid[0].size();
    }

    for(int row = 0; row < maxRow; row++) {
        for(int col = 0; col < maxCol; col++) {
            if(grid[row][col] > 0) {
                auto current = make_pair(row,col);
                visited[getUniqueKey(current)] = 1;
                int val = getMax(current, grid[row][col], grid);
                if (val > maxVal){
                    maxVal = val;
                }
                visited.erase(getUniqueKey(current));
            }
        }
    }
    return maxVal;
}

int main(){
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    cout << getMaximumGold(grid);
    return 0;
}