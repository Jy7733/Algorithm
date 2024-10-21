#include <bits/stdc++.h>

using namespace std;

long long dp[10];

int main(void){
    int n;
    cin>>n;

    //초기화 
    for(int i=1; i<10; i++){
        dp[i] = 1;
    }

    int x =1;

    while(true){
        if(x == n) break;

        long long tmp[10];

        for(int i=0; i<10; i++){
            int left = i-1;
            int right = i+1;

            if(left < 0){
                tmp[i] = dp[right];
            }

            else if(right > 9){
                tmp[i] = dp[left];
            }

            else if(left >= 0 && right <= 9){
                tmp[i] = dp[left] + dp[right];
            }
        }

        for(int i=0; i<10; i++){
            dp[i] = tmp[i] % 1000000000;
        }
        x+=1;
    }

    long long sum =0;

    for(int i=0; i<10; i++){
        sum+=dp[i];
    }

    cout<<sum%1000000000<<"\n";

}