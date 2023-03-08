mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
class Polyhash{
	private:
		static const ll M = (1LL<<61)-1;
		static const ll B;
		static vector<ll> pow;
		vector<ll> p_hash;
		__int128 mul(ll a, ll b) { return (__int128)a * b; }
		ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
	public:
		Polyhash(int n){
			while(pow.size()<n){
				pow.push_back(mod_mul(pow.back(),B));
			}
		}
		ll add(ll a,ll b){ return (a+b)%M;}
		ll get_hash(ll val,ll idx){
			return mod_mul(val,pow[idx]);
		}
};
vector<ll> Polyhash::pow = {1};
const ll Polyhash::B = uniform_int_distribution<ll>(100, M - 1)(rng);