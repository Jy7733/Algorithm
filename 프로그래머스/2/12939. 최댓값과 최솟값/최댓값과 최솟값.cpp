#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    int num;
    int mn = INT_MAX; int mx = INT_MIN;
    
    while(ss >> num){
        mn = min(mn, num);
        mx = max(mx, num);
    }
    
    answer = to_string(mn) + " " + to_string(mx);
    return answer;
}