#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
string x,y;
cin>>x>>y;
int n=x.size(),m=y.size();
int a[n+1][m+1];
for(int i=0;i<=n;i++)a[i][0]=0;
for(int i=0;i<=m;i++)a[0][i]=0;
int b[n+1][m+1];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(x[i]==y[j]){
            a[i+1][j+1] = 1+a[i][j];
            b[i+1][j+1] = 2;
        }
        else if(a[i+1][j]> a[i][j+1]){
            a[i+1][j+1] = a[i+1][j];
            b[i+1][j+1] = 1;
        }else{
            a[i+1][j+1] = a[i][j+1];
            b[i+1][j+1] = 0;
        }
    }
}
cout<<"THE LENGTH OF LCS:"<<a[n][m]<<endl;
int i=n,j=m;
while(i!=0 || j!=0){
    if(b[i][j] == 2){
        cout<<x[i-1]<<" ";
        i-=1;
        j-=1;
    }
    else if(b[i][j]== 1)j-=1;
    else i-=1;
}
}