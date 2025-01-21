#include <bits/stdc++.h>

using namespace std;
vector<int> home;

//유클리드 호제를 이용한 최대공약수 구하기 
int gdb(int a, int b){
    if(b ==0){
        return a;
    }
    return gdb(b, a%b);
}

//선택 구간의 최대공약수 구하기 
int findGdb(int start, int end){

    int val = 0;

    for(int i=start; i<=end; i++){
        val = gcd(val, home[i]);
    }

    return val;
}

int divide(int start, int end){

    if(start == end) return home[start]; // 원소가 하나인 경우 그대로 반환 

    int mid = (start + end - 1)/2;
    
    int selectLeft = findGdb(start, mid) + divide(mid+1, end); //왼쪽을 선택했을 때 최대 공약수 구하기 + 나머지 부분 재귀로 다시 나누기 
    int selectRight = divide(start, mid) + findGdb(mid+1, end); //오른쪽 선택했을 때 최대 공약수 구하기 + 나머지 부분 재귀로 다시 나누기

    return max(selectLeft, selectRight); //최대공약수의 최대합
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        home.push_back(x);
    }

    cout<<divide(0,n-1);
}