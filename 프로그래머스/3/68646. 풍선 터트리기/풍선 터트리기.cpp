#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int n = a.size();
    int left[n];
    int right[n];
    
    fill(left, left+n, 0);
    fill(right, right+n, 0);
    left[0] = a[0];
    right[n-1] = a[n-1];
    answer = 2;
    
    for(int i=1; i<n-1; i++){
        left[i] = min(a[i], left[i-1]);
    }
    for(int i=n-2; i>0; i--){
        right[i] = min(a[i], right[i+1]);
    }
    
    for(int i=1; i<n-1; i++){
        if(a[i] > left[i-1] && a[i] > right[i+1]) continue;
        answer++;
    }
    
    return answer;
}
