/**
 * URL: https://leetcode.com/problems/course-schedule/
 * 

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

 

Constraints:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    1 <= numCourses <= 10^5

*/
/**
 * Approach:
 * 1. Create the unordered multimap of in-vertex table
 * 2. Create the priority queue for the prerequisites
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    vector<int> inVertex(numCourses,0);

    for(int i = 0; i < prerequisites.size(); i++) {
        vector<int>row = prerequisites[i];
        adj[row[0]].push_back(row[1]);
        inVertex[row[1]]++;

    }

    queue<int> que;
    int cnt = 0;

    for(int i = 0; i < inVertex.size();i++) {
        if(inVertex[i]==0){
            que.push(i);
        }
    }

    while(!que.empty()) {
        int u = que.front();
        que.pop();

        auto itr = adj[u];
        for(int i = 0; i < itr.size(); i++){
            inVertex[itr[i]]--;
            if(inVertex[itr[i]] == 0) {
                que.push(itr[i]);
            }
        }

        cnt++;
    }


    if(cnt != numCourses) {
        return false;
    }

    return true;
}

int main(){
    int numCourses = 4;
//    vector<vector<int>> ip = {{0,1}, {0,3}, {1,3}, {1,2}, {2,5}};
    //vector<vector<int>> ip = {{0,1}, {1,0}};
    vector<vector<int>> ip = {{3,0},{0,1}};

    cout << canFinish(numCourses, ip);

    return 0;
}

