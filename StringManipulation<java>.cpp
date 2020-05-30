#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;

        int dig=0;int alpha=0;

        for(auto ele:s){
            if(ele>='0' && ele<='9')dig=1;
            if(ele>='a' && ele<='z')alpha=1;
        }
        string ans="";
        if(dig==1 && alpha==1){
            ans="Its an AlphaNumeric";
        }
        else if(dig==1 && alpha==0){
            ans="Valid Format";
        }
        else ans="Its a String";
        cout<<ans<<"\n";
    }

    return 0;
}
