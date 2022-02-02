#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9+5;
const int mx = 2e5+1;
vector<int> tree;
ll min_query(int cur,int l,int r, int ql,int qr){
    if(ql<=l && qr>=r){
        return tree[cur];
    }
    if(ql>r || qr<l){
        return INF;
    }
    int left_high = (l+r)/2;
    return min(min_query(2*cur,l,left_high,ql,qr),min_query(2*cur+1,left_high+1,r,ql,qr));
}
void update(int cur,int x ,int l,int r,int v){
    if(x<=l && x>=r){
        tree[cur] = v;
        return;
    }
    if(x>r || x<l){
        return;
    }
    int left_high = (l+r)/2;
    update(cur*2,x,l,left_high,v);
    update(cur*2+1,x,left_high+1,r,v);
    tree[cur] = min(tree[cur*2],tree[cur*2+1]);
    return;
}

int main(){
	int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    //Building the tree
    for(int x= 0 ;x<n;x++) cin>>arr[x];
    while(__builtin_popcount(n)!=1){
        arr.push_back(0);
        n++;
    }
    tree.resize(2*n);
    for(int i = 0;i<n;i++){
        tree[i+n] = arr[i];
    }
    for(int i = n-1;i>=1;i--){
        tree[i] = min(tree[2*i],tree[2*i+1]);
    }
    //queries;


}


