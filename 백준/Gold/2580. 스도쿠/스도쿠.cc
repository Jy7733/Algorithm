#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
vector< pair<int, int> > zero; //빈 칸 좌표 배열 
int done = 0;

bool check(int curX, int curY){

    //가로줄 체크 
    for(int i=0; i<9; i++){
        if(i != curY && arr[curX][curY] == arr[curX][i]) return false;
    }

    //세로줄 체크
    for(int i=0; i<9; i++){
        if(i != curX && arr[curX][curY] == arr[i][curY]) return false;
    }

    //사각형 체크 
    int x = (curX / 3) * 3;
    int y = (curY / 3) * 3;

    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            if((i != curX || j != curY) && arr[curX][curY] == arr[i][j]) return false;
        }
    }

    return true;
}

void func(int k){

    if(k== zero.size()){
        done = 1;
        return;
    }

    for(int i=1; i<10; i++){
        int curX = zero[k].first;
        int curY = zero[k].second;

        arr[curX][curY] = i;
        if(check(curX,curY) == true){
            func(k+1);
            if(done == 1) return;
        }
        arr[curX][curY] = 0;
        
    }

}

int main(void){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 0) zero.push_back({i,j}); 
        }
    }

    func(0);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<arr[i][j]<<" ";
        }

        cout<<"\n";
    }


}