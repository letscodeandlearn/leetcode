/**
 * URL : https://leetcode.com/problems/word-search/
 * 79. Word Search
Medium

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

 

Constraints:

    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3

*/
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
#include<math.h>

using namespace std;

/****
 * Time limit exceeded. But logic wise correct.
 * Needs to optimize further
 * 
struct pair_hash{
    template <class T1, class T2>
    std::size_t operator() (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1^h2;
    }
};

int maxCol, maxRow;
vector<vector<pair<int,int>>> adlist(26);
vector<vector<pair<int,int>>> Adlist(26);

bool isNextNeighbour(pair<int,int> current, pair<int,int> next) {
    int x = abs(current.first - next.first);
    int y = abs(current.second - next.second);

    if ((x >= 1) && (y >= 1)) {
        return false;
    }
    else if ((x > 1) || (y > 1)) {
        return false;
    }

    return true;
}

vector<pair<int,int>> getNearstNeighbour(pair<int,int> current, string str, int pos,  unordered_map<pair<int,int>, int, pair_hash> visited){

    vector<pair<int,int>> op;
    if(str[pos] - 'A' > 26){
        vector<pair<int,int>> row = adlist[str[pos]-'a'];
        for(int i = 0; i < row.size(); i++) {
            if (visited.find(make_pair(row[i].first, row[i].second)) == visited.end() && isNextNeighbour(current, row[i])){
                op.push_back(make_pair(row[i].first, row[i].second));
            }
        }
    } else {
        vector<pair<int,int>> row = Adlist[str[pos]-'A'];
        for(int i = 0; i < row.size(); i++) {
            if (visited.find(make_pair(row[i].first, row[i].second)) == visited.end() && isNextNeighbour(current, row[i])){
                op.push_back(make_pair(row[i].first, row[i].second));
            }
        }
    }

    return op;
}


bool isPossible(pair<int,int> current, string str, int pos,  unordered_map<pair<int,int>, int, pair_hash> visited) {

    if (pos >= str.length()-1) {
        return true;
    }

    vector<pair<int,int>> nList = getNearstNeighbour(current, str, pos+1, visited);
    if (nList.size() == 0){
        return false;
    }

    for(int i = 0; i < nList.size(); i++){
        pair<int,int> nxt = nList[i];
        visited[make_pair(nxt.first, nxt.second)] = 1;
        bool val = isPossible(nxt, str, pos+1, visited);
        if (val == true) {
            return true;
        } else {
            visited.erase(make_pair(nxt.first, nxt.second));
        }
    }

    return false;
}



bool exist(vector<vector<char>>& board, string word) {
    maxRow = board.size();
    if(maxRow > 0){
        maxCol = board[0].size();
    }

    for(int row = 0; row < maxRow; row++ ) {
        for(int col = 0; col < maxCol; col++) {
            char ch = board[row][col];
            if (ch - 'A' > 26){
                adlist[ch-'a'].push_back(make_pair(row,col));
            } else {
                Adlist[ch-'A'].push_back(make_pair(row, col));
            }
        }
    }
    char ch = word[0];
    vector<pair<int,int>> row;
    if(ch-'A' > 26){
        row = adlist[ch-'a'];
    }else {
        row = Adlist[ch-'A'];
    }

    for(int i = 0; i < row.size(); i++) {
        unordered_map<pair<int,int>, int, pair_hash> visited;
        visited[make_pair(row[i].first, row[i].second)] = 1;
        bool val = isPossible(row[i], word, 0, visited);
        if (val == true) {
            return true;
        }
    }

    return false;
}



int main(){

    vector<vector<char>> ip =     {
                                    {'A','B','C','E'},
                                    {'S','F','E','S'},
                                    {'A','D','E','E'}
                                  };
    cout << exist(ip, "ABCESEEEFS");

    return 0;
}

/**
 * [["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","b"]]
"baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
*/

struct pair_hash{
    template <class T1, class T2>
    std::size_t operator() (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1^h2;
    }
};


int maxCol, maxRow;
unordered_map<pair<int,int>, int, pair_hash> visited;
vector<pair<int,int>> neighbours = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};


bool isValid(pair<int,int> current){
    if ((current.first >= 0  && current.first < maxRow) && (current.second >=0 && current.second < maxCol)) {
        return true;
    }
    return false;
}

bool backtrack(string word, int pos, pair<int,int> current, vector<vector<char>>& board){

    if(pos >= word.size()-1) {
        return true;
    }

    for(int i = 0; i < neighbours.size(); i++) {
        auto index = neighbours[i];
        auto next = make_pair(current.first+index.first, current.second+ index.second);
        if (isValid(next)){
            if((board[next.first][next.second] == word[pos+1]) && (visited.find(make_pair(next.first, next.second)) == visited.end())){
                visited[make_pair(next.first, next.second)] =1;
                bool val = backtrack(word, pos+1, next, board);
                if (val == false){
                    visited.erase(make_pair(next.first,next.second));
                } else {
                    return true;
                }
            }
        }
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    maxRow = board.size();
    if(maxRow > 0){
        maxCol = board[0].size();
    }

    queue<pair<int,int>> startLocs;
    for(int row = 0; row < maxRow; row++ ) {
        for(int col = 0; col < maxCol; col++) {
            if(board[row][col] == word[0]) {
                startLocs.push(make_pair(row,col));
            }
        }
    }

    while(!startLocs.empty()) {
        pair<int,int> current = startLocs.front();
        visited[make_pair(current.first, current.second)] = 1;
        startLocs.pop();
        int pos = 0;
        bool val = backtrack(word, pos, current, board);
        if (val == true){
            return true;
        } else {
            visited.erase(make_pair(current.first, current.second));
        }
    }

    return false;
}

int main(){

    vector<vector<char>> ip =     {
                                    {'A','B','C','E'},
                                    {'S','F','E','S'},
                                    {'A','D','E','E'}
                                  };
    auto val = exist(ip, "ABCESEEEFSADB");
    cout << val;
    return 0;
}