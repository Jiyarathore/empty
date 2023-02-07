#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binexp(int a, int b,int m){
    int result =1;
    while(b>0){
        if(b&1){
            result = (result* 1LL * a)%m;
        }
        a = (a*1LL *a)%m;
        b>>=1;
    }
    return result;
}

int main(){
    // formula of modular multiplicative invrse is A power m-2 modula m
    // so here is invrerse of 2
    cout<<binexp(2,M-2,M); //500000004
}

// lets solce a question
// there are N children and K toffees, K<N
// Count the no. of ways to distribute toffee 
// among N students such that each students get
// 1 toffee only --> nCk % M, M= 1e9+7
// N<1e6, K<N<1e6
// Q<1e5
// n ! / ((n-r) ! * r!) we can do n ! * inverse of den

const int N = 1e6+10;
int fact[N];
int main(){
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1] * 1LL * i)%M;
    }
int q;
cin>>q;
while(q--){
    int n,k;
    cin>>n>>k;
    int ans= fact[n];
    int den = (fact[n-k] * 1LL * fact[k])%M;
    ans=ans * binexp(den,M-2,M);
    cout<<ans<<endl;
}

}