#include <bits/stdc++.h>

using namespace std;

string input = "";
string bomb = "";
string result = "";

void solve(){
    int length = bomb.size();

    for(int i=0; i<input.size(); i++){
        result.push_back(input[i]);

        //폭발 문자열 끝 부분과 같은 경우 검사 
        if(result.back() == bomb.back()){
            if(result.size()-length >= 0){
                int flag = 0;
                for(int j=0; j<length; j++){
                    if(result[result.size() - length + j] != bomb[j]){
                        flag = 1;
                        break;
                    }
                }
                //폭발 문자열과 동일할 경우 
                if(flag == 0){
                    for(int i=0; i<length; i++){
                        result.pop_back();
                    }
                }
            }
        }
    }

}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>input; 
    cin>>bomb;

    solve();
    if(result.empty()) cout<<"FRULA\n";
    else cout<<result<<"\n";
}