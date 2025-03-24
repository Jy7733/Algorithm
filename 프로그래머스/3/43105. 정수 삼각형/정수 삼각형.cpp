#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int height = triangle.size(); //삼각형 높이 
    // vector<vector<int>> sum(height); //합을 기록할 배열 
    int sum[height][height];
    sum[0][0] = triangle[0][0];
    // sum[0].push_back(triangle[0][0]); //꼭대기 
    
    for(int i=1; i<height; i++){
        for(int j=0; j<triangle[i].size(); j++){
            //왼쪽 끝 칸인 경우 
            if(j == 0) 
                sum[i][j] = triangle[i][j] + sum[i-1][j];
            
            //오른쪽 끝 칸인 경우 
            else if(j == triangle[i].size()-1) 
                sum[i][j] = triangle[i][j] + sum[i-1][j-1];
            
            else
                sum[i][j] = max(triangle[i][j] + sum[i-1][j-1], triangle[i][j] + sum[i-1][j]);
        }
    }
    
    answer = *max_element(sum[height-1], sum[height-1] + height);
    
    return answer;
}