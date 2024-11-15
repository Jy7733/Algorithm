#include <bits/stdc++.h>
using namespace std;

int total; 
int n,m;
int arr[25][25];
int answer=0;


void check(){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]){
                return;
            }
        }
    }

    answer++;
}

void func(int k){

    if(k == total){
        check();
        return;
    }

    int x = k / m;
    int y = k % m;
    arr[x][y] = 1;
    func(k+1);
    arr[x][y] = 0;
    func(k+1);

}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;

    total = n*m;

    func(0);
    cout<<answer;
}
