#include <bits/stdc++.h>
using namespace std;
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


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) cin>>arr[i][j];
    }
    FenwichTree2D ft(arr);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) cout<<ft.bit[i][j]<<" ";
        cout<<"\n";
    }
    cout<<ft.sum(2,1)-ft.sum(0,0);

}