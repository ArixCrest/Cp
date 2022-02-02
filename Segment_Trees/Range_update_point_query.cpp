#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int,int> 
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
const int INF = 1e9+5;
const int mx = 2e5+1;
vector<ll> tree;

ll point_query(int cur){
    if(cur==1){
        return tree[cur];
    }
    return tree[cur]+point_query(cur/2);
}
void update(int cur,int l,int r,int ql,int qr,int v){
    if(ql<=l && qr>=r){
        tree[cur] += v;
        return;
    }
    if(ql>r || qr<l){
        return;
    }
    int left_high = (l+r)/2;
    update(cur*2l,l,left_high,ql,qr,v);
    update(cur*2+1,left_high+1,r,ql,qr,v);
    //tree[cur] = (tree[cur*2]^tree[cur*2+1]);
    return;
}

int main(){
	int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int x= 0 ;x<n;x++) cin>>arr[x];
    while(__builtin_popcount(n)!=1){
        arr.push_back(0);
        n++;
    }
    //building
    tree.resize(2*n);
    for(int i = 0;i<n;i++){
        tree[i+n] = arr[i];
    }
    // for(int i = n-1;i>=1;i--){
    //     tree[i] = tree[2*i]^tree[2*i+1];
    // }
    // for(int i = 1;i<2*n
   
	

}

