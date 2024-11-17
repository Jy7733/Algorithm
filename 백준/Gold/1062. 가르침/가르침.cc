#include <bits/stdc++.h>
using namespace std;

vector<string> words;
bool taught[26]; //가르친 글자 

int n, k;

int result;

int check(){
    int cnt =0;


    for(int i=0; i<n; i++){
        for(int j=0; j<words[i].size(); j++){
            //안 배운 글자가 있다면 break 
            if(taught[words[i][j] - 97] == false) {
                cnt-=1;
                break;   
            }
        }

        //전부 배운 글자였다면 
        cnt+=1;
    }
    return cnt;
}


void func(int idx, int x){

    if(x == k-5){
        result = max(result, check());
        return;
    }

    for(int i=idx; i<26; i++){
        
        if(taught[i] == true) continue; //이미 가르친 글자라면 넘어감 

        taught[i] = true;
        func(i+1,x+1);
        taught[i] = false;
    
    }

}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
 
    for(int i=0; i<n; i++){
        string input = "";
        cin>>input;
        words.push_back(input);
    }   

    // anta, tica 는 항상 들어가므로 taught 배열 세팅 
    taught['a' - 97] = true;
    taught['n' - 97] = true;
    taught['t' - 97] = true;
    taught['i' - 97] = true;
    taught['c' - 97] = true; 

    if(k < 5){
        cout<<0;
        return 0;
    }

    func(0,0);

    cout<<result;
}   