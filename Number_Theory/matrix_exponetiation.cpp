vector<vector<ll>> mat_mul(vector<vector<ll>> a,vector<vector<ll>> b,long long m){
	int n = a.size();
	vector<vector<ll>> res(n,vector<ll>(n,0));
	rep(x,0,n) rep(y,0,n){
		rep(z,0,n){
			res[x][y] = (res[x][y]+a[x][z]*b[z][y])%m;
		}
	}
	return res;

}
vector<vector<ll>> mat_exp(vector<vector<ll>> a,long long b,long long m){
	int n = a.size();
	vector<vector<ll>> res(n,vector<ll>(n,0));
	rep(x,0,n) res[x][x] = 1;
	if(b==0) return res;
	while(b>0){
		if(b&1){
			res = mat_mul(res,a,m);
		}
		b = b>>1;
		a = (mat_mul(a,a,m));
	}
	return res;
}