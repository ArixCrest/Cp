ll find_divs(vector<ll> divs,ll num){
	int n = divs.size();
	ll ans = 0;
	for(int i = 1;i<(1<<n);i++){
		ll lc = 1;
		rep(y,0,n){
			if(i&(1<<y)) lc = lcm(divs[y],lc);
		}
		if(lc>num) continue;
		int p = __builtin_popcount(i);
		if(p%2==1){
			ans = ans+(num/lc);
		}else{
			ans = ans-(num/lc);
		}
	}
	return num-ans;

}