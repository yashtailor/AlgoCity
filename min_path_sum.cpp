#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=m-2;i>=0;i--){
            grid[n-1][i] = grid[n-1][i]+grid[n-1][i+1];
        }
        for(int i=n-2;i>=0;i--){
            grid[i][m-1] = grid[i][m-1] + grid[i+1][m-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                grid[i][j] = grid[i][j] + min(grid[i][j+1],grid[i+1][j]);
            }
        }
        return grid[0][0];
    }
};
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>v(n,vector<int>(m));
for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
Solution s;
cout<<s.minPathSum(v)<<endl;
}

/*
TC - O(M*N)
SC - O(1)
*/
