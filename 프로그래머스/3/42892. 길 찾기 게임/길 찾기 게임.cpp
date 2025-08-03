#include <bits/stdc++.h>

using namespace std;

vector<int> preorderResult; 
vector<int> postorderResult; 

struct Node {
    int num; 
    int x;
    int y;
    Node *left;
    Node *right; 
};
vector<Node> nodeList; 

bool cmp(Node n1, Node n2){
    if(n1.y > n2.y){
        return true;
    }
    else if(n1.y == n2.y){
        if(n1.x < n2.x) return true;
        else return false;
    }
    else return false;
}

void makeTree(Node *root, Node *child){
    if(root->x > child->x){
        if(root->left == NULL){
            root->left = child; 
            return;
        }
        else{
            makeTree(root->left, child);
        }
    }
    else{
        if(root->right == NULL){
            root->right = child;
            return;
        }
        else{
            makeTree(root->right, child);
        }
    }
}

void preorder(Node *root){
    if(root == NULL) return;
    preorderResult.push_back(root->num);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    postorderResult.push_back(root->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    for(int i=0; i<nodeinfo.size(); i++){
        nodeList.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    sort(nodeList.begin(), nodeList.end(), cmp);
    
    // 1. 트리 생성 
    Node *root = &nodeList[0]; 
    for(int i=1; i<nodeList.size(); i++) makeTree(root, &nodeList[i]); 
    
    preorder(root);
    postorder(root);
    
    answer.push_back(preorderResult);
    answer.push_back(postorderResult); 
    
    return answer;
}



