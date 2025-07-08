#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    ll maxTime = *max_element(times.begin(), times.end());
    ll left = 0;
    ll right = maxTime * n;
    
    while(left <= right){
        ll people = 0;
        
        ll mid = (left + right)/2;
        for(auto time : times){
            people += (mid / time);
        }
        
        if(people >= n){
            answer = mid;
            right = mid-1;
        }
        else if(people < n){
            left = mid + 1;
        }
    }
    return answer;
}