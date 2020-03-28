#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[n+1][m+1];
        for(int i=1;i<=n;i++){
            a[i][m]=1;
        }
        for(int i=1;i<=m;i++){
            a[n][i]=1;
        }
        for(int i=n-1;i>=1;i--){
            for(int j=m-1;j>=1;j--){
                a[i][j] = a[i][j+1] + a[i+1][j];
            }
        }
        return a[1][1];
    }
    // exponential solution
    // int uniquePathsUtil(int m,int n,int c,int r){
    //     if(c==m && r==n)return 1;
    //     if(c>m || r>n)return 0;
    //     return uniquePathsUtil(m,n,c+1,r)+uniquePathsUtil(m,n,c,r+1);
    // }
};
int main(){
    int m,n;
    cin>>m>>n;
    Solution s;
    cout<<s.uniquePaths(m,n)<<endl;
}

/*

7 3
28

TC-O(N*M)
SC-O(N*M)
*/
