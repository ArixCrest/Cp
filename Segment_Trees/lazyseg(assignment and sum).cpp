// Assignment in range [l,r-1] && sum query in range [l,r-1]
// there may be a way to directly get range [l,r] need review.
template<class T> struct LazySeg {
    const T ID = 0; T comb(T a, T b) { return a+b; }
    int n,h; vector<T> seg,d;
    void init(int _n){ // if memory issues use int and change both the parts inside.
        n = _n; h = sizeof(long long)*8-__builtin_clzll(n);
        seg.assign(2*n,ID); d.assign(n,0);}
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void calc(int p,int k){
        if(d[p]==0) pull(p);
        else seg[p] = d[p]*k;
    }
    void apply(int p,T val,int k){ 
        seg[p] = (val*k);if(p<n) d[p] = val;}
    void build(int l,int r){ //if min max is used the d[p] stays but if add then you gotta add the size of interval
        int k = 2;
        for(l += n,r += n-1;l > 1;k <<= 1){
            l /= 2, r /= 2;
            for(int i = r; i>=l; --i) calc(i,k);
        } }
    void push(int l,int r){
        l += n,r += n-1;
        for(int s = h, k = (1<<(h-1)); s > 0; --s,k >>= 1){
            for(int i = l>>s;i <= (r>>s) ; ++i ){
                if(d[i]!=0) apply(2*i,d[i],k),apply(2*i+1,d[i],k),d[i] = 0;}
        }
    }
    void upd(int l,int r, T val){
        if(val == 0) return;
        push(l,l+1),push(r-1,r);
        int l0 = l,r0 = r,k = 1;
        for (l += n, r += n; l < r; l /= 2, r /= 2,k <<= 1) {
			if (l&1) apply(l++,val,k);
			if (r&1) apply(--r,val,k);
		}
        build(l0,l0+1),build(r0-1,r0);
    }
    T query(int l,int r){
        push(l,l+1),push(r-1,r);
        T ra = ID,rb = ID;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
        return comb(ra,rb);
    }
};
LazySeg<ll> lzy;