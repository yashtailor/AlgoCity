#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll number_of_items,tot_weight;
    cin>>number_of_items>>tot_weight;
    ll a[number_of_items+1][tot_weight+1];
    ll w[number_of_items]; // weight of ith item
    ll val[number_of_items]; // val of ith item
    for(int i=1;i<=number_of_items;i++){
        cin>>w[i]>>val[i]; // entering the weight and val
    }
    for(int i=0;i<= tot_weight;i++){
        a[0][i] = 0; // with weight of 0, we have 0 value
    }
    for(int i=0;i<=number_of_items;i++){
        a[i][0] = 0; // for making value 0 , we take 0 item
    }
    for(int i=1;i<=number_of_items;i++){
        for(int j=1;j<=tot_weight;j++){
            if(w[i] > j){
                a[i][j] = a[i-1][j]; // weight lesser than current then taking the previous
                continue;
            }
            // else taking what max can be produced by taking the item 
            // and not taking the item
            a[i][j] = max(val[i] + a[i-1][j-w[i]] , a[i-1][j]);
        }
    }
    for(int i=0;i<=number_of_items;i++){
        for(int j=0;j<=tot_weight;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"max val:"<<a[number_of_items][tot_weight]<<endl;

    ll i=number_of_items,j=tot_weight;
    while(i!=0 || j!=0){
        if(a[i][j] != a[i-1][j]){
            cout<<w[i]<<" "<<val[i]<<endl;
            j-=w[i];
        }
        i-=1;
    }
}


/*  OUTPUT:

4 7
1 1
3 4
4 5
5 7
0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1
0 1 1 4 5 5 5 5
0 1 1 4 5 6 6 9
0 1 1 4 5 7 8 9
max val:9
4 5
3 4

*/