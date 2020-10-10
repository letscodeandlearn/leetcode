/**
 * https://leetcode.com/problems/count-numbers-with-unique-digits/
 * 357. Count Numbers with Unique Digits
Medium

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:

Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
             excluding 11,22,33,44,55,66,77,88,99

 

Constraints:

    0 <= n <= 8

*/
#include<iostream>
#include<vector>

using namespace std;

int getCount(int num, int n, int pos, vector<int>visited){

    if (pos >= n){
        return 1;
    }
    int count = 0;
    for(int i = 0; i < 10; i++) {
        if(visited[i]!=1){
            visited[i]=1;
            count += getCount(i,n, pos+1,visited);
            visited[i]=0;
        }
    }
    return count;
}

int countNumbersWithUniqueDigits(int n) {
    vector<int> visited(10);
    int totCount = 0;

    if(n >= 2){
        totCount = 10;
    }
    for(int v = 2; v <=n; v++){
        for(int i = 1; i < 10; i++) {
            visited[i]=1;
            int val = getCount(i, v, 1, visited);
            visited[i]=0;
            totCount += val;
        }
    }

    return totCount;
}

int main(){
    int n = 8;
    cout << countNumbersWithUniqueDigits(n);
    return 0;
}