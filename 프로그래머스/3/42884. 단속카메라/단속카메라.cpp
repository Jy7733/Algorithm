#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer =0;

    sort(routes.begin(), routes.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1]; 
    });

    int camera = -30001;

    for(auto &route : routes){
        if(route[0] > camera){
            answer+=1;
            camera = route[1];
        }
    }

    return answer; 
}