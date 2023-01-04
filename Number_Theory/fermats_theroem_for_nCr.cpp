//fermats theorem for fast_exp calculation
// a^(mod-2)%mod = a^-1%mod <- only when mod is prime
// when mod is not prime but a & mod are "coprime" then use euclids extended alogrithm
long long fast_exp(long long  a,long long b,long long m){
	long long res = 1;
	a = a%m;
	if(b==0) return 1;
	if(a==0) return a;
	while(b>0){
		if(b&1){
			res = (res*a)%m;
		}
		b = b>>1;
		a = (a*a)%m;
	}
	return res;
}
long long fermat(long long n, long long r, long long m){
	if(r<0) return 0;
	if(n==0 && r>0) return 0;
    if(n<r){
        return 0;
    }
    if(r==0){
        return 1;
    }
    return (factorial[n]*fast_exp(factorial[r],m-2,m) % m *fast_exp(factorial[n-r],m-2,m)%m)%m;
}

