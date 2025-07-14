#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int n = enroll.size();
    map<string, string> adj;
    map<string, int> sum;
    
    for(int i=0; i<n; i++){
        adj[enroll[i]] = referral[i];
        sum[enroll[i]] = 0;
    }
    
    // amount 값 -> x100 으로 
    for(int i=0; i<amount.size(); i++){
        amount[i] *= 100;
    }
    
    for(int i=0; i<seller.size(); i++){
        string name = seller[i]; 
        int profit = amount[i]; 
        
        while(name != "-"){
            string next = adj[name];
            if(profit < 1){
                sum[name] += profit;
                break;
            }
            else{
                sum[name] += (profit - profit/10);
                profit = profit/10;
                name = next;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        answer.push_back(sum[enroll[i]]);
    }

    return answer;
}