#include <bits/stdc++.h>
#define INF (~0U >> 2)

typedef long long ll;

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> seq;

int main(void){
	int n,m;
	cin>>n>>m;

	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		seq.push({a,b});
	}

	ll semester[n+1]; 
	fill(semester, semester+n+1, INF);

	while(!seq.empty()){
		auto cur = seq.top();
		int pre = cur.first;
		int next = cur.second;
		seq.pop();

		if(semester[pre] == INF){
			semester[pre] = 1;
		}

		if(semester[next] == INF) semester[next] = semester[pre]+1;
		else semester[next] = max(semester[next],semester[pre] + 1);
	}


	for(int i=1; i<=n; i++){
		if(semester[i] == INF) cout<<"1 ";
		else cout<<semester[i]<<" ";
	}

}