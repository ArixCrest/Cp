// different from the naive version only supports range min or max in in the form [0,R];
struct FenwichTree{
    vector<int> bit;
    int n;
    const int INF = 1e+9;
    FenwichTree(int n){
        this->n = n;
        bit.assign(n,INF);
    }
    FenwichTree(vector<int> arr): FenwichTree(arr.size()){
        for(int i = 0;i<n;i++){
            update(i,arr[i]);
        }
    }
    int getmin(int r) {
        int s = INF;
        for (; r >= 0; r = (r&(r+1))-1){
            //cout<<r<<" "<<bit[r]<<"\n";
            s = min(s, bit[r]); // change to max if needed
        }
        return s;
    }
    void update(int index, int delta){
        for(;index <n;index = index | (index+1)){
            bit[index]=min(bit[index],delta);
        }
    }
};
