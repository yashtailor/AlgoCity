#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct job{
    int st,ft,profit;
};
bool comp(job j1,job j2){
    return j1.ft < j2.ft;
}
int main(){
    int n;
    cin>>n;
    job jf[n];
    for(int i=0;i<n;i++){
        cin>>jf[i].st>>jf[i].ft>>jf[i].profit;
    }
    sort(jf,jf+n,comp);
    int a[n];
    for(int i=0;i<n;i++){
        a[i] = jf[i].profit;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(jf[j].ft <= jf[i].st){
                a[i] = max(a[i],jf[j].profit+jf[i].profit);
            }
        }
    }
    int index = 0;
    for(int i=1;i<n;i++){
        if(a[i] > a[index]){
            index = i;
        }
    }
    cout<<"MAX PROFIT:"<<a[index]<<endl;
}

/*

TC: O(N^2)
SC: O(N)

OUTPUT:
6
1 3 5
2 5 6
4 6 5
6 7 4
5 8 11
7 9 2
MAX PROFIT:17

*/