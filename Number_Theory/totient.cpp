// n logn implementation
// there is another better nloglogn but this one is super simple.
// all pairs such that gcd(a,b) = d and a+b = n is phi(n/d)
// if gcd(a,b) = 1 and a+b = n then phi(n) basically the above is extension.
vector<int> phi(mx);
void phi(){
    phi[0] = 0;
    phi[1] = 1;
    rep(x,2,mx){
        phi[x] = x-1;
    }
    for(int i = 2;i<=n;i++){
        for(int j = 2*i;j<=n;j+=i){
            phi[j]-=phi[i];
        }
    }
}