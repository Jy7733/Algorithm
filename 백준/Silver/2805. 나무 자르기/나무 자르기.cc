#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll m, min, max, sum, result;
	ll trees[1000001];

	cin>>n>>m;

	for(int i=0; i<n; i++){
		cin>>trees[i];
	}

	sort(trees, trees+n);
	max = trees[n-1];
	min = 0;

	while(min <= max){
		ll h = (min + max)/2;
		sum = 0;

		for(int i=0; i<n; i++) if(trees[i] - h > 0) sum += (trees[i] - h);

		if(sum >= m){
			result = h;
			min = h + 1;
		}
		else{
			max = h-1;
		}
	}

	cout<<result<<"\n";

}