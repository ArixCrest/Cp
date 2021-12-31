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
// lcm using sieve
void lcm(vector<int> arr){
    vector<int> count(mx,0);
	rep(x,0,arr.size()){
		while(arr[x]!=1){
			int temp = 0;
			int prev = sieve[arr[x]];
			while(sieve[arr[x]]==prev && arr[x]!=1){
				temp++;
				arr[x] = arr[x]/sieve[arr[x]];
			}
			count[prev] = max(count[prev],temp);
		}
	}
}