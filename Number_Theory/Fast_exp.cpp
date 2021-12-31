// calculates (a^b)%m in log(b) time
// if you are calculating a^(b^c)%p -> a^(q(p-1)+r)%p -> (a^(p-1)%p)^q(a^r)%m ->((1)^q)(a^r%p) <- ans
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