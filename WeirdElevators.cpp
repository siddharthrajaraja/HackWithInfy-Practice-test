#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX pow(10,6)+1
#define REP(i,a,b) for(ll i=a;i<b;i++)

vector<int>primes(MAX,1);
vector<ll>allPrimes;

void sieve(){
    primes[0]=0;
    primes[1]=0;
    
    ll i;
    REP(i,2,MAX){
        if(primes[i]==1){
            allPrimes.push_back(i);
            ll j;
            while(i*j<MAX){
                primes[i*j]=false;
                j++;
            }
        }
    }
}


ll euclidGCD(ll a,ll b){
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

ll getCount(ll ele,ll m){
    ll i=0;
    ll count=0;
    while(ele!=1  && i<allPrimes.size()){
        if(allPrimes[i]>=m && ele%allPrimes[i]==0)return -1;
        if(ele%allPrimes[i]!=0){
            i++;
        }
        else{
            ele=ele/allPrimes[i];
            count++;
        }   
            
    }
    return count;

}

int main(){
    ll t;cin>>t;
    sieve();

    while(t--){
        ll a,b,m;cin>>a>>b>>m;
        ll gcd=euclidGCD(a,b);
        //cout<<"GCD is: "<<gcd<<"\n";
            ll firstNo=a/gcd;
            ll secondNo=b/gcd;
            int countFirst=getCount(firstNo,m);
            int countSecond=getCount(secondNo,m);

            if(countFirst==-1 || countSecond==-1){
                cout<<"-1\n";
            }
            else{
                cout<<countFirst+countSecond<<" "<<gcd<<"\n";
            }

        
    }

    return 0;
}
