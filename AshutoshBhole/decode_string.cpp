/**
 * URL: https://leetcode.com/problems/decode-string/
 * Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

 * 
*/

#include<iostream>
#include<stack>
#include<stdio.h>

using namespace std;

struct multival {
    int count;
    int len;
};

multival getCount(string s, int startId) {
    string t = "";
    struct multival op;
    while(startId >=0) {
        if((s[startId]-'0' < 10) && (s[startId]-'0' >= 0)) {
            t += s[startId];
        }else {
            break;
        }
        startId--;
    }
    if (t.length() == 1) {
        op.count= (t[0]-'0');
        op.len=1;
        return op;
    } else {
        // 12 would be like : 21 in t
        int n=0;
        for(int i=t.length()-1; i>= 0; i--){
            int num = t[i] - '0';
            n = (n * 10) + (num);
        }
        op.count = n;
        op.len = t.length();
        return op;
    }
}

string decodeString(string s) {
    int i=0;
    stack<int> sp;

    while(i < s.length()) {
        if (s[i] == '[') {
            sp.push(i);
        } else if (s[i] == ']') {
            int startId = sp.top();
            sp.pop();
            //int count = s[startId-1] - '0';
            struct multival count = getCount(s, startId-1);
            string tmp = s.substr(startId+1,(i-startId-1));
            string post = s.substr(i+1, s.length()-i+1);
            s = s.substr(0, startId- count.len);
            cout << tmp << " " << post << " " << count.count <<"\n";
            while(count.count > 0) {
                s = s.append(tmp);
                count.count --;
            }
            //cout << s << "\n";
            s = s.append(post);

            //cout << s << "\n";
            i = startId-count.len;
        }
        i++;
        //cout << s << "\n";
    }
    return s;
}


int main() {
    string ip = "abc3[cd]xyz"; //working
    ip = "2[abc]3[cd]ef"; //working
    ip = "3[a2[c]]"; //working
    ip =  "3[a]2[bc]"; //working
    ip = "9[a]";  //similar = "a12[a]", 2[a]21[b]= aa21[b]
    cout << decodeString(ip);
    return 0;
}