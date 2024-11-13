#include <bits/stdc++.h>
using namespace std;

int used[12];

int s[12][12]; //포지션별 점수 배열 
vector<int> able[12]; //각 선수가 배치될 수 있는 포지션 표시 
int total;
int score;


void func(int k){

    if(k > 11){
        score = max(score, total);
        return;
    }


    for(int i=0; i<able[k].size(); i++){
        
        int position = able[k][i];

        // 사용하지 않은 & k 번 선수가 배치될 수 있는 위치인 경우 
        if(!used[position]){
            used[position] = 1;
            total += s[k][position];
            func(k+1);
            total -= s[k][position];
            used[position] = 0;
        }
    }

}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;

    for(int i=0; i<t; i++){

        //able 벡터 초기화 
        for(int z=1; z<=11; z++){
            able[z].clear();
        }

        for(int x=1; x<=11; x++){
            for(int y=1; y<=11; y++){
                cin>>s[x][y];

                //0이 아니라면 배치될 수 있는 포지션에 추가 
                if(s[x][y]!=0){
                    able[x].push_back(y);
                }
            }
        }

        score = 0;
        func(1);
        cout<<score<<"\n";
    }
    
}