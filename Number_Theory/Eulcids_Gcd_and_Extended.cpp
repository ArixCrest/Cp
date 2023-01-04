#include <bits/stdc++.h>

using namespace std;
//Basic Gcd
long long gcd(long long a,long long b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}


int main(){
    map<int,int> a;
    cout<<a[22];
    
}