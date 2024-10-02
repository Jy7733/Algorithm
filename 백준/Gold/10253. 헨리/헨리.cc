#include <bits/stdc++.h>
#define ll long long

using namespace std;

void henryAlgorithm(int a,int b){

    ll na = a;
    ll nb = b;
    ll result = 0;

    if(a == 1){
        result = b;
        cout<<result<<"\n";
        return;
    }

    while(true){
        ll x = (nb/na) + 1; // (a/b) >= (1/x) 를 만족하는 x 중 가장 큰 수 
        na = (na * x) - nb; //(a/b) - (1/x) 결과의 분자
        nb = (x * nb); //(a/b) - (1/x) 결과의 분모

        //마지막 단위분수인 경우 
        if((nb % na) == 0){
            nb = nb/na;
            result = nb;
            break;
        }
    }

    cout<<result<<"\n";
    return;
}

int main(void){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int a,b;
        cin>>a>>b;

        henryAlgorithm(a,b);
    }

}