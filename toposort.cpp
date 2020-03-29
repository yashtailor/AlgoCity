#include<bits/stdc++.h>
using namespace std;
void dfs_visit(int i,vector<int>a[],int n,stack<int>&s,bool b[]){
    for(int j=0;j<a[i].size();j++){
        if(!b[j]){
            dfs_visit(a[i][j],a,n,s,b);
        }
    }
    s.push(i);
    b[i]=1;
}
int main(){
    int n;
    cin>>n;
    vector<int>a[n];
    bool b[n]={0};
    int e;
    cin>>e;
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        a[u].push_back(v);
    }
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!b[i]){
            dfs_visit(i,a,n,s,b);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

/*
output:
7
7
0 2
1 2
2 4
1 3
3 5
4 5
5 6
1 3 0 2 4 5 6
TC- O(V+E)
SC- O(V+E)
*/
