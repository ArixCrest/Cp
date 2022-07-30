// add values in range [l,r] && query of max in range [l,r]
// Note: sum won't work.
template<class T> struct LazySeg {
    const T ID = -INF; T comb(T a, T b) { return a>b?a:b; }
    int n,h; vector<T> seg,d;
    void init(int _n){ // if memory issues use int and change both the parts inside.
        n = _n; h = sizeof(long long)*8-__builtin_clzll(n);
        seg.assign(2*n,ID); d.assign(n,0);}
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void apply(int p,T val){ 
        seg[p]+=val;if(p<n) d[p]+=val;}
    void build(int p){ //if min max is used the d[p] stays but if add then you gotta add the size of interval
        for(p /= 2;p > 1; p /=2) pull(p),seg[p] += d[p]; }
    void push(int p){
        for(int s = h; s > 0; --s){
            int i = p>>s;
            if(d[i]!=0) apply(2*i,d[i]),apply(2*i+1,d[i]),d[i] = 0;
        }
    }
    void upd(int l,int r, T val){
        int l0 = l+n,r0 = r+n+1;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) apply(l++,val);
			if (r&1) apply(--r,val);
		}
        build(l0),build(r0-1);
    }
    T query(int l,int r){
        l += n,r += n+1;T ra = ID, rb = ID;
        push(l),push(r-1);
        for (; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
        return comb(ra,rb);
    }
};
LazySeg<ll> lzy;