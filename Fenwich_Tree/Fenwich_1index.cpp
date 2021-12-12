struct FenwichOnebasedIndex{
    vector<int> bit1;
    vector<int> bit2;
    int n;
    FenwichOnebasedIndex(int k) {
        this->n = k;
        bit1.assign(k + 1, 0);
        bit2.assign(k+1,0);
    }
    int sum(vector<int> bit,int index) {
        int s = 0;
        for (; index > 0; index -= index&(-index)){
            //cout<<index<<" ";
            s += bit[index];
        }
        return s;
    }
    void point_update_b1(int index, int delta) {
        for (; index <= n; index += index&(-index)){
            bit1[index] += delta;
        }
    }
    void point_update_b2(int index, int delta) {
        for (; index <= n; index += index&(-index)){
            bit2[index] += delta;
        }
    }
    //all val to the range [l,r]
    void range_update(int l, int r, int val) {
        point_update_b1(l, val);
        point_update_b1(r+1 , -val);
        point_update_b2(l,val*(l-1));
        point_update_b2(r+1,(-val)*r);
    }
    int prefix_sum(int index){
        return sum(bit1,index)*index - sum(bit2,index);
    }
    int range_sum(int l ,int r){
        return prefix_sum(r) - prefix_sum(l-1);
    }
};