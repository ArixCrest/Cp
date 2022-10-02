// LCP largest common prefix of the suffixes
// lets say we have queires of the form lcp(i,j) and we want to calculate
// LCP of suffixes starting at index i and j we can take the min of range [i,j] in the lcp array
// the lcp array calculates only the lcp of the adjacent elemnts.
void counting_sort(vector<int> &idx,vector<int> &c){
	int n = idx.size();
	vector<int> cnt(n);
	for(auto x : c){
		cnt[x]++;
	}
	vector<int> idx_new(n);
	vector<int> pos(n);
	pos[0] = 0;
	for(int i  = 1;i<n;i++){
		pos[i] = pos[i-1]+cnt[i-1];
	}
	for(auto x : idx){
		int i  = c[x];
		idx_new[pos[i]] = x;
		pos[i]++;
	}
	idx = idx_new;
}
vector<int> lcp_arr(string s){
    s+='$';
    int n = s.length();
    vector<int> idx(n),c(n);
	{
		vector<pair<char,int>> a(n);
		for(int i = 0;i<n;i++){
			a[i] = {s[i],i};
		}
		sort(a.begin(),a.end());
		for(int i = 0;i<n;i++) idx[i] = a[i].second;
		c[idx[0]] = 0;
		for(int i = 1;i<n;i++){
			if(a[i].first==a[i-1].first){
				c[idx[i]] = c[idx[i-1]];
			}else{
				c[idx[i]] = c[idx[i-1]]+1;
			}
		}
	}
    int k = 0;
    while((1<<k)<n){

		for(int i = 0;i<n;i++){
			idx[i] = (idx[i]-(1<<k)+n)%n;
		}
        // sort(a.begin(),a.end()); can use radix sort for linear time
		counting_sort(idx,c); // can change radix to counting.
		vector<int> c_new(n);
        c[idx[0]] = 0;
        for(int i = 1;i<n;i++){
			pair<int,int> prev = {c[idx[i-1]],c[(idx[i-1]+(1<<k))%n]};
			pair<int,int> now = {c[idx[i]],c[(idx[i]+(1<<k))%n]};
            if(prev==now){
                c_new[idx[i]] = c_new[idx[i-1]];
            }else{
                c_new[idx[i]] = c_new[idx[i-1]]+1;
            }
        }
        k++;
		c = c_new;
    }
	vector<int> lcp(n);
	k = 0;
	for(int i = 0;i<n-1;i++){
		int loc = c[i]; //c[i] has the inverse permutation of idx[i]; basically pos of idx[i];
		int j = idx[loc-1];
		// lcp of suffix starting at idx i and j
		while(s[i+k]==s[j+k]) k++;
		lcp[loc] = k;
		k = max(k-1,0); 
	}
	return lcp;

}