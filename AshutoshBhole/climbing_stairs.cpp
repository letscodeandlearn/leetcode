/*
    URL: https://leetcode.com/problems/climbing-stairs/
*/

class Solution {
public:
    
    /*
    int traverse(int source, int destination){
        if(source == destination) {
            return 1;
        }else if (source > destination) {
            return 0;
        }
        
        int path = 0;
        path = traverse(source+2, destination);
        path += traverse(source+1, destination);
        return path;
    }
    */
    
    int climbStairs(int n) {
        
        if(n==1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        else{
            int source=3, op=0;
            int first = 1, second = 2;
            while(source <= n) {
                op = first+second;
                first = second;
                second = op;
                source++;
            }
            return op;
        }
        
    }
};