//supports point update and range queries
struct FenwichTree{
    vector<int> bit;
    int n;
    const int INF = 1e+9;
    FenwichTree(int n){
        this->n = n;
        bit.assign(n,0);
    }
    FenwichTree(vector<int> arr): FenwichTree(arr.size()){
        for(int i = 0;i<n;i++){
            add(i,arr[i]);
        }
    }
    int point_query(int r){
        int s = 0;
        for(;r>=0; r = (r&(r+1))-1){
            s+=bit[r];
        }
        return s;
    }
    int range_query(int l, int r){
        return point_query(r)-point_query(l-1);
    }
    int getmin(int r) {
        int s = INF;
        for (; r >= 0; r = (r&(r+1))-1){
            cout<<r<<" "<<bit[r]<<"\n";
            s = min(s, bit[r]);
        }
        return s;
    }
    void add(int index, int delta){
        for(;index <n;index = index | (index+1)){
            bit[index]+=delta;
        }
    }
    //binary search the prefix sum log(n)*log(n);
    int bin_search(int target){
		int l = 0;
		int r = n;
		while(l<=r){
			int mid = (l+r)/2;
			int sum = point_query(mid);
			if(sum==target){
				return mid;
			}
			else if(sum<target){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
	}
};

