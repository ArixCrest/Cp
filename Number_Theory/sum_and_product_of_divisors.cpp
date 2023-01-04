const long long modulo = 1e9+7;
const int mx = 1e6+1;
vector<ll> count(mx,0);
long long fast_exp(long long  a,long long b,long long m){
	long long res = 1;
	a = a%m;
	if(b==0) return 1;
	if(a==0) return a;
    //if(a==1) return 1;
	while(b>0){
		if(b&1){
			res = (res*a)%m;
		}
		b = b>>1;
		a = (a*a)%m;
	}
	return res;
}
long long sum_divs(){
    long long s = 1;
    rep(x,2,mx){
        if(count[x]==0) continue;
        ll k = 0;
        k+=fast_exp(x,count[x]+1,modulo);
        k--;
        k = (k*fast_exp(x-1,modulo-2,modulo))%modulo;
        s = (sum_divs*k)%modulo;
    }
    return s;
}

long long prod_divs(){
    long long  prod = 1;
    long long divs = 1;
    rep(x,2,mx){
        if(count[x]==0) continue;
        long long k = 0;
        long long val = (count[x])*(count[x]+1)/2;
        long long rem = val%(modulo-1);
        k =(fast_exp(x,rem,modulo));
        prod = (fast_exp(prod,count[x]+1,modulo)*fast_exp(k,divs,modulo))%modulo;
        divs=(divs*(count[x]+1))%(modulo-1); // acc to fermats modulo-1 not modulo
    }
}

