#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end(),greater<int>());
    sort(B.begin(), B.end(),greater<int>());

    int j = 0;
    int answer = 0;

    for(int i=0; i<A.size(); i++){
        if(A[i] < B[j]){
            answer+=1;
            j+=1;
        }
    }
    return answer;
}
