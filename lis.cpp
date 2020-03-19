#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
int b[n];
int last[n]={0};
for(int i=0;i<n;i++)b[i]=1;
for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[i] > a[j] && b[i] < b[j]+1){
            b[i] = 1+b[j];
            last[i] = j;
        }
    }
}
int max_index = 0;
for(int i=1;i<n;i++){
    if(b[i] > b[max_index])max_index = i;
}
int last_index = max_index;
cout<<"The elements of LIS:"<<endl;
// will be printed in reverse order
while(last_index!=0){
    cout<<a[last_index]<<" ";
    last_index = last[last_index];
}
cout<<endl;
cout<<"LENGTH OF LIS:"<<b[max_index]<<endl;
}

/*

TC: O(N^2)
SC: O(N)

OUTPUT:
10
9 3 5 2 1 7 4 8 6 10
The elements of LIS:
10 8 7 5 3 
LENGTH OF LIS:5

*/