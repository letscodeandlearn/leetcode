/*
    URL : https://leetcode.com/problems/product-of-array-except-self/
    Status : Accepted
*/

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix, suffix;
    
    prefix.push_back(1);
    suffix.push_back(1);
    
    for(int i = 1; i < nums.size(); i++) {
        int prev = prefix[i-1];
        prefix.push_back(prev * nums[i-1]);
        suffix.push_back(1);
    }
    
    for(int i = nums.size()-2; i >= 0; i--) {
        int prev = suffix[i+1];
        suffix[i] = prev * nums[i+1];
    }
    
    vector<int> op;
    
    for(int i = 0; i < nums.size(); i++) {
        op.push_back(prefix[i] * suffix[i]);    
    }
    return op;
}

/*
int main(){
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    productExceptSelf(input);
    return 0;
}
*/