/**
 * URL: https://leetcode.com/problems/rotting-oranges/
 * 
 * In a given grid, each cell can have one of three values:

    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

 

Note:

    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] is only 0, 1, or 2.

*/
#include<vector>
#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

struct pair_hash{
    template <class T1, class T2>
    std::size_t operator() (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1^h2;
    }
};

unordered_map<pair<int,int>, int, pair_hash> fresh;
//unordered_map<pair<int,int>, int, pair_hash> visited;
queue<pair<int,int>> rotten;

int maxRow=0;
int maxCol=0;

void insertValidNeighbours(pair<int,int> current){

    //Move up
    if(fresh.find(make_pair(current.first-1, current.second)) != fresh.end()){
        rotten.push(make_pair(current.first-1, current.second));
        fresh.erase(make_pair(current.first-1, current.second));
    }
    //Move down
    if(fresh.find(make_pair(current.first+1, current.second)) != fresh.end()){
        rotten.push(make_pair(current.first+1, current.second));
        fresh.erase(make_pair(current.first+1, current.second));
    }
    //Move right
    if(fresh.find(make_pair(current.first, current.second+1)) != fresh.end()){
        rotten.push(make_pair(current.first, current.second+1));
        fresh.erase(make_pair(current.first, current.second+1));
    }
    //Move left
    if(fresh.find(make_pair(current.first, current.second-1)) != fresh.end()){
        rotten.push(make_pair(current.first, current.second-1));
        fresh.erase(make_pair(current.first, current.second-1));
    }
}

int orangesRotting(vector<vector<int>>& grid) {
    maxRow = grid.size();
    if(maxRow>0) {
        maxCol=grid[0].size();
    }else {
        return -1;
    }

    for(int row = 0 ; row < maxRow; row++) {
        for(int col = 0; col < maxCol; col++) {
            if(grid[row][col] == 0) {
                //visited.insert(row,col);
            } else if (grid[row][col] == 1) {
                //fresh.insert(row,col);
                fresh[make_pair(row,col)]=1;
            } else {
                rotten.push(make_pair(row,col));
            }
        }
    }

    int op=0;
    while(!rotten.empty()) {
        int count = rotten.size();
        while(count > 0) {
            auto current = rotten.front();
            rotten.pop();
            insertValidNeighbours(current);
            count--;
        }
        op++;
    }

    if(fresh.size() != 0){
        return -1;
    }
    return op;
}