// only provies range sum, min or max and range add or update
struct sqrt_decompositon{
    vector<int> arr,b,bmin;
    int n,len;
    const int INF = 1e9+9;
    //initializing
    sqrt_decompositon(int k){
		this->n = k;
		len = (int)sqrt(n)+1;
		arr.resize(n,0);
		b.resize(len,0);
		bmin.resize(len,INF);
	} 
    sqrt_decompositon(vector<int> a): sqrt_decompositon(a.size()) {
        for(int i = 0;i<n;i++){
            b[i/len] += a[i];
            bmin[i/len] = min(a[i],bmin[i/len]);
            arr[i] = a[i];
        }
    }
    // increments the value delta at index
    void add(int index,int delta){
        b[index/len]+=delta;
        arr[index]+=delta;
    }
    // changes the value at index to delta
    void update(int index, int delta){
        int diff = delta-arr[index];
        b[index/len]+=diff;
        arr[index] = delta;
    }
    //find the min of in range [L,R]
    // switch min with max for max in a range
    int min_query(int l , int r){
        int minim = INF;
        int left = l/len,right = r/len;
        if(left==right){
            for(int i = l;i<=r;i++){
                minim = min(minim,arr[i]);
            }
            return minim;
        }
        for(int i = l,end = (left+1)*len-1;i<=end;i++){
            minim = min(minim,arr[i]);
        }
        for(int i = left+1;i<=right-1;i++){
            minim = min(minim,bmin[i]);
        }
        for(int i =right*len;i<=r;i++){
            minim = min(minim,arr[i]);
        }
        return minim;
    }
    // return the sum in range [L,R]
    long long sum_query(int l, int r){
        long long s = 0;
        int left = l/len,right = r/len;
        if(left==right){
            for(int i = l;i<=r;i++){
                s+=arr[i];
            }
            return s;
        }
        for(int i = l,end = (left+1)*len-1;i<=end;i++){
            s+=arr[i];
        }
        for(int i = left+1;i<=right-1;i++){
            s+= b[i];
        }
        for(int i =right*len;i<=r;i++){
            s+=arr[i];
        }
        return s;
    }
};