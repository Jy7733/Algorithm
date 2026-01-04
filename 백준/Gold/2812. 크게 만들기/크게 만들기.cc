#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k; cin>>n>>k; 

    string str; 
    cin>>str;

    int cnt=0; //삭제한 횟수
    deque<char> dq; 
    for(int i=0; i<str.size(); i++){
        while(!dq.empty() && cnt < k){
            if(dq.back() < str[i] && !dq.empty()){
                dq.pop_back();
                cnt++; 
            }
            else break; 
        }
        dq.push_back(str[i]); 
    }
    while (cnt < k){
        dq.pop_back();
        cnt++;
    }

    while(!dq.empty()){
        cout<<dq.front();
        dq.pop_front();
    }
}

