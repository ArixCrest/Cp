//supports range updates and point_queries(returns value in array not prefix sum) but not range queries
struct FenwichOnebasedIndex{
    vector<int> bit;  // binary indexed tree 
    int n;

    FenwichOnebasedIndex(int k) {
        this->n = k;
        bit.assign(k + 1, 0);
    }

    FenwichOnebasedIndex(vector<int> a): FenwichOnebasedIndex(a.size()) {
        for (int i = 0; i < a.size(); i++){
            point_update(i+1, a[i]);
        }
    }
    //return the value of index of array not Bit array 
    //since we are doing range update
    int point_query(int index) {
        int s = 0;
        for (; index > 0; index -= index&(-index)){
            s += bit[index];
        }
        return s;
    }
    void point_update(int index, int delta) {
        for (; index <= n; index += index&(-index)){
            bit[index] += delta;
        }
    }
    //all val to the range [l,r]
    void range_update(int l, int r, int val) {
        point_update(l, val);
        point_update(r+1 , -val);
    }
};