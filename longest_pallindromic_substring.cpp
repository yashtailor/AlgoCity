#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;
        int lindex = 0;
        int rindex = 0;
        for(int i=1;i<s.length();i++){
            int l=i-1,h=i+1;
            int oddc=0;
            while(l>=0 && h<s.size() && s[l]==s[h]){
                oddc+=2;
                l--;
                h++;
            }
            if(oddc+1 > max){
               max = oddc+1;
               lindex = l+1;
               rindex = h-1; 
            }
            //cout<<lindex<<rindex<<endl;
            h = i;
            l = i-1;
            int highc=0;
            while(l>=0 && h<s.size() && s[l]==s[h]){
                highc+=2;
                l--;
                h++;
            }
            if(highc > max){
               max = highc;
               lindex = l+1;
               rindex = h-1; 
            }
            //cout<<lindex<<rindex<<endl;
        }
        string f="";
        for(int i=lindex;i<=rindex;i++){
            f+=s[i];
        }
        return f;
    }
};
int main(){
    Solution s;
    string p;
    cin>>p;
    cout<<s.longestPalindrome(p)<<endl;
}

/*

TC - O(N^2)
SC - O(1)
OUTPUT-
formaniinamfor
maniinam
*/
