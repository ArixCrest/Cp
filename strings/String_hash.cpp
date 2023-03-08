class HashedString{
	private:
		static const ll M = (1LL<<61)-1;
		static const ll B;
		static vector<ll> pow;
		vector<ll> p_hash;
		__int128 mul(ll a, ll b) { return (__int128)a * b; }
		ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
	public:
		
		HashedString(const string &s): p_hash(s.size()+1){
			while(pow.size()<s.size()){
				pow.push_back(mod_mul(pow.back(),B));
			}
			p_hash[0] = 0;
			for(int i = 0;i<s.size();i++) p_hash[i+1] = (mul(p_hash[i],B) + s[i])%M;
		}
		//gives a hash of substring [end,start] <-zero index
		ll getHash(int start,int end){
			ll val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
			return (val+M)%M;
		}
};
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(100, M - 1)(rng);