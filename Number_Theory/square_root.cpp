// Calucaltes the floor of sqrt of a
// this is better than using sqrt function because it gives wrong ans for large numbers
ll find_sq(ll a){
    ll l = 1;
    ll r = 1e9;
    ll ans;
    while(l<=r){
        ll mid = (l+r)>>1;
        if(mid*mid<=a){
            l = mid+1;
			ans = mid;
        }else{
            r = mid-1;
        }
    }
    return ans;
}