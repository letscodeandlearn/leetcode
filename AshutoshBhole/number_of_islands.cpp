/*
    URL: https://leetcode.com/problems/number-of-islands/
*/

#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>
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


void traverse(pair<int, int> current, queue<pair<int,int>> &q, unordered_map<pair<int,int>,int, pair_hash> &visited,vector<vector<char>>& grid,  int maxRow, int maxCol) {

    int currentX, currentY, x, y;
    currentX = current.first;
    currentY = current.second;

    // Move UP; x-1, y
    if(currentX-1 >= 0) {
        if(visited.find(make_pair(currentX-1, currentY)) == visited.end() && grid[currentX-1][currentY]=='1') {
            q.push(make_pair(currentX-1, currentY));
        }
        visited[make_pair(currentX-1, currentY)] = 1;

    }

    // Move DOWN; x+1, y
    if (currentX +1 < maxRow) {
        if(visited.find(make_pair(currentX+1, currentY)) == visited.end() && grid[currentX+1][currentY]=='1') {
            q.push(make_pair(currentX+1, currentY));
        }
        visited[make_pair(currentX+1, currentY)] = 1;
    }

    // Move LEFT; x, y-1
    if (currentY-1 >= 0) {
        if(visited.find(make_pair(currentX, currentY-1)) == visited.end() && grid[currentX][currentY-1]=='1') {
            q.push(make_pair(currentX, currentY-1));
        }
        visited[make_pair(currentX, currentY-1)] = 1;
    }

    // Move RIGHT; x, y+1
    if (currentY+1 < maxCol) {
        if(visited.find(make_pair(currentX, currentY+1)) == visited.end() && grid[currentX][currentY+1]=='1') {
            q.push(make_pair(currentX, currentY+1));
        }
        visited[make_pair(currentX, currentY+1)] = 1;
    }

}

int numIslands(vector<vector<char>>& grid) {

    unordered_map<pair<int,int>,int, pair_hash> visited;
    int row=0, col =0, op = 0;
    int maxRow, maxCol;
    maxRow = grid.size();
    maxCol = grid[0].size();

    while(row < maxRow) {
        while (col < maxCol) {
            auto itr = visited.find(make_pair(row, col));
            if (itr == visited.end() && grid[row][col] == '1') {
                queue<pair<int,int>> q;
                q.push(make_pair(row, col));
                visited[make_pair(row, col)]=1;

                while(!q.empty()) {
                    int nc = q.size();
                    while(nc > 0) {
                        pair<int,int> current = q.front();
                        visited[make_pair(current.first,current.second)]=1;
                        //cout << current.first << "-" << current.second << "\n";
                        q.pop();
                        traverse(current, q, visited,grid, maxRow, maxCol);
                        nc--;
                    }
                }
                op++;
            } else {
                visited[make_pair(row,col)]=1;
            }

            col++;
        }
        col=0;
        row++;
    }

    return op;
}


int main(){
    vector<vector<char>> ip;
    ip = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
  };
/*
    vector<char> row1, row2, row3, row4;
    row1.push_back('0');
    row1.push_back('1');
    row1.push_back('1');
    row1.push_back('0');
    row2.push_back('0');
    row2.push_back('0');
    row2.push_back('1');
    row2.push_back('1');
    row3.push_back('1');
    row3.push_back('0');
    row3.push_back('0');
    row3.push_back('1');
    row4.push_back('1');
    row4.push_back('0');
    row4.push_back('0');
    row4.push_back('1');

    ip.push_back(row1);
    ip.push_back(row2);
    ip.push_back(row3);
    ip.push_back(row4);
*/

    cout << numIslands(ip);

    return 0;
}
