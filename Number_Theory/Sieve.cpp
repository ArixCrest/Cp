const int mx = 1e6+1;
vector<int> sieve(mx,0);
//0 value for primes
void Sieve(){
	for(int x = 2;x<=mx;x++){
		if(sieve[x]!=0) continue;
		else{
			int j = x;
			while(j<mx){
				sieve[j] = x;
				j+=x;
			}
		}
	}
}
