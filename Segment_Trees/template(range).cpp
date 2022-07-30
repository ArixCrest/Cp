//ID is the initialization values can be changed depending on the type of query
// range update point query
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return a+b; }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void push() {
        for(int i = 1;i<n;++i){
            seg[i<<1] = comb(seg[i<<1],seg[i]);
            seg[i<<1] = comb(seg[i<<1],seg[i]);
            seg[i] = 0;
        }
    }
	void upd(int l, int r,T val) {	// upd on interval [l, r]
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) seg[l++] += val;
			if (r&1) seg[--r] += val;
		}
	}
    T query(int p) { // val at position p
        T res = ID;
		for (p += n; p; p /= 2) res = comb(res,seg[p]);
		return res;}
};
Seg<ll> st;