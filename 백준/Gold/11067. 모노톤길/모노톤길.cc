#include <bits/stdc++.h>

using namespace std;

vector<int> cafe[100001];
vector<pair<int, int>> num[100001];
vector<int> output; 

//x 기준으로 숫자 정렬을 위한 함수 
bool compare(int a, int b, int x){
    return abs(a - x) < abs(b-x); 
} 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    
    while(t--){
        int n; cin>>n; //카페 개수 

        //num, cafe 배열 초기화 
        for (int i = 0; i < 100001; i++) {
            cafe[i].clear();
            num[i].clear(); 
        }

        int dx = 0;
        for(int i=0; i<n; i++){
            int x,y;
            cin>>x>>y;
            cafe[x].push_back(y);

            dx = max(dx,x); //x 좌표가 어디까지 있는지 확인용 
        }

        
        int prev = 0; //이전 카페 위치의 y 좌표 
        // num[1].push_back({0,0});
        int j = 1;  //j번째 카페 

        for(int i=0; i<=dx; i++){

            if(cafe[i].size() == 0) continue; // x좌표가 i 인 카페가 없으면 패스 
            if(cafe[i].size() == 1){  //x 좌표가 i 인 카페가 한 개면 바로 num[j] 에 추가 
                num[j].push_back({i, cafe[i][0]});// ( i, y좌표 추가 )
                prev = cafe[i][0]; //이전 순서의 카페 y 좌표 업데이트 
                j+=1; //다음 순서로 업데이트 
            }

            // x 좌표가 i 개인 카페가 여러 개 있으면 
            else{
                //이전 순서의 카페 y좌표와 가까운 순서대로 정렬 
                sort(cafe[i].begin(), cafe[i].end(), [prev](int a, int b){
                    return compare(a,b,prev);
                });

                // 정렬된 순서대로 num 에 추가 
                for(int z = 0; z < cafe[i].size(); z++){
                    num[j].push_back({i, cafe[i][z]});
                    j+=1;
                    prev = cafe[i][z];
                }
            }

        }

        output.clear();

        int m;
        cin>>m;
        for(int i=0; i<m; i++){
            int k;
            cin>>k;
            output.push_back(k);
        }

        for (int i = 0; i < output.size(); i++) {
            int idx = output[i];
            for (const auto& p : num[idx]) {
                cout << p.first << " " << p.second<<"\n";
            }
        }

    }

}

