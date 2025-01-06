#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

// 팩토리얼 연산 
ll fact(int x){
    ll tmp = 1;
    for(int i = 1; i <= x; i++){
        tmp *= i;
        tmp %= MOD; // 항상 모듈러 연산 적용
    }
    return tmp;
}

// 거듭제곱 연산 (모듈러 역원 구하기)
ll power(ll a, ll b){
    if(b == 1) return a % MOD; // a^1 = a 이므로 return 
    
    ll tmp = power(a, b/2);

    if(b % 2){ // b가 홀수라면 
        return (tmp * tmp % MOD) * a % MOD; // a^b = (a^(b/2))^2 * a
    }
    else{ // b가 짝수라면 
        return tmp * tmp % MOD; // a^b = (a^(b/2))^2
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 1. N! 계산
    ll A = fact(n);

    // 2. K!(N-K)! 계산 
    ll Kfact = fact(k);
    ll B = (Kfact * fact(n - k)) % MOD; // 항상 모듈러 연산 적용

    // 3. 결과 계산: A / B (즉, A * B^(MOD-2) % MOD)
    ll result = A * power(B, MOD - 2) % MOD;

    cout << result << "\n";
}
