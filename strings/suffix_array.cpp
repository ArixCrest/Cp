
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
vector<int> suffi_arr(string s){
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
	// for(auto v  :idx){
	// 	cout<<v<<" ";
	// }cout<<"\n";
    return idx;
}