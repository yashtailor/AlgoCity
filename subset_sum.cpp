#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    cout<<"Total number of numbers:";
    int n;
    cin>>n;
    int a[n+1];
    cout<<"Enter the numbers:";
    for(int i=1;i<=n;i++)cin>>a[i];
    int sum;
    cout<<"Enter the sum:";
    cin>>sum;
    int b[n+1][sum+1];
    for(int i=0;i<=sum;i++)b[0][i]=0;
    for(int i=0;i<=n;i++)b[i][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= a[i]) b[i][j] = b[i-1][j] || b[i-1][j-a[i]];
            else b[i][j] = b[i-1][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++)cout<<b[i][j]<<" ";
        cout<<endl;
    }
    if(b[n][sum])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<"One of the subset:"<<endl; // will give one
    int i=n,j=sum;
    while(i!=0 || j!=0){
        if(b[i][j] == 1 && b[i-1][j] != 1){
            cout<<a[i]<<" ";
            j -= a[i];
        }
        i -=1;
    }
}

/*

TIME COMPLEXITY - O(N*SUM)
SPACE COMPLEXITY - O(N*SUM)

OUTPUT-
Total number of numbers:5
Enter the numbers:3 5 7 9 10
Enter the sum:12
1 0 0 1 0 0 0 0 0 0 0 0 0 
1 0 0 1 0 1 0 0 1 0 0 0 0 
1 0 0 1 0 1 0 1 1 0 1 0 1 
1 0 0 1 0 1 0 1 1 1 1 0 1 
1 0 0 1 0 1 0 1 1 1 1 0 1 
YES
One of the subset:
7 5

*/