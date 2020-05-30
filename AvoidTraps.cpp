#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX pow(10,6)+1
vector<ll>primes(MAX,1);
vector<ll>primeCount(MAX,1);
#define REP(i,a,b) for(ll i=a;i<b;i++)
void sieve(){
    primes[0]=0;
    primes[1]=0;
    primeCount[0]=0;
    primeCount[1]=0;
    ll i;
    ll count=1;
    REP(i,2,MAX+1){
        if(primes[i]==1){
            primeCount[i]=count;
            count++;
            ll j=2;
            while(i*j<=MAX){
                primes[i*j]=0;
                j++;
            }
        }

        else primeCount[i]=primeCount[i-1];
        
    }

}

int main(){
    ll t;cin>>t;
    sieve();
    
    while(t--){
        ll r1,r2;cin>>r1>>r2;
        double ratio=(double)r1/r2;
        ll size;cin>>size;
        string s;cin>>s;
        vector<ll>dp(size,INT_MAX);

        dp[0]=0;

        ll i=1;
        
        REP(i,0,size){
                ll index=i+1;
                if(s[i]=='#'){
                if(i+1<size){
                    if(s[i+1]=='#')
                    dp[i+1]=min(dp[i+1],1+dp[i]);
                }
                if(i+2<size){
                    if(s[i+2]=='#')
                    dp[i+2]=min(dp[i+2],1+dp[i]);
                }

                /*cout<<"Ratio is : "<<(double)primeCount[index]/index<<" "<<ratio<<"\n";*/
                if(((double)primeCount[index]/index)>ratio){
                    if((i+primeCount[index])<size)
                    if(s[i+primeCount[index]]=='#')
                    dp[i+primeCount[index]]=min(dp[i+primeCount[index]],dp[i]+1);

                }}
                
        }

        /*REP(i,0,size){
            cout<<dp[i]<<" ";
        }
        cout<<endl;*/
        if(dp[size-1]==INT_MAX){
            cout<<"No way!"<<"\n";
        }
        else{
            cout<<dp[size-1]<<"\n";
        }


    }
    
   
    
    

    return 0;
}
