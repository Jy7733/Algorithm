#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<ll> seq1; 
    vector<ll> seq2;
    int a = 1; 
    int b = -1;
    
    for(int i=0; i<sequence.size(); i++){
        a *= (-1);
        b *= (-1);
        seq1.push_back(sequence[i] * b);
        seq2.push_back(sequence[i] * a);
        
    }

    ll cur1 = seq1[0];
    ll max1 = seq1[0];
    ll cur2 = seq2[0];
    ll max2 = seq2[0];
    
    for(int i=1; i<sequence.size(); i++){
        cur1 = max(seq1[i], seq1[i] + cur1);
        max1 = max(max1, cur1);
        
        cur2 = max(seq2[i], seq2[i] + cur2);
        max2 = max(max2, cur2);
    }
    
    answer = max(max1, max2);
    
    return answer;
}