#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
string s;
cin>>s;
int n = s.size();
int a[n][n]={0};
for(int i=0;i<n;i++)a[i][i]=1;
for(int i=1;i<n;i++){
    for(int j=0;j<n-i;j++){
        if(s[j] == s[j+i]){
            if(i==1)a[j][j+i]=2;
            else a[j][j+i]=2+a[j+1][j+i-1];
        }else{
            a[j][j+i]=max(a[j+1][j+i],a[j][j+i-1]);
        }
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)cout<<a[i][j]<<" ";
    cout<<endl;
}
//MAKING LPS
string fstring="";
int i=0,j=n-1;
bool mid = false;
while(i<=n/2 || j>=n/2){
    if(a[i][j] != a[i+1][j] && a[i][j] != a[i][j-1]){
        fstring += s[i];
        if(i==j)mid = true;
        i +=1;
        j -=1;
    }else if(a[i][j] == a[i+1][j]){
        i += 1;
    }else{
        j -= 1;
    }
}
i = fstring.size()-2;
if(!mid){
    fstring += fstring[fstring.size()-1];
}
for(;i>=0;i--){
    fstring += fstring[i];
}
cout<<"LENGTH:"<<a[0][n-1]<<endl;
cout<<"SUBSEQUENCE:"<<fstring<<endl;
}

/*
N - length of string

TC - O(N^2)
SC - O(N^2)

OUTPUT-
agbdba
1 1 1 1 3 5 
0 1 1 1 3 3 
0 0 1 1 3 3 
0 0 0 1 1 1 
0 0 0 0 1 1 
0 0 0 0 0 1 
LENGTH:5
SUBSEQUENCE:abdba

*/