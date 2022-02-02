#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<ll> tree;
ll sum_query(int cur,int l,int r, int ql,int qr){
    if(ql<=l && qr>=r){
        return tree[cur];
    }
    if(ql>r || qr<l){
        return 0;
    }
    int left_high = (l+r)/2;
    return sum_query(2*cur,l,left_high,ql,qr)+sum_query(2*cur+1,left_high+1,r,ql,qr);
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
    tree[cur] = tree[cur*2]+tree[cur*2+1];
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
    tree.resize(2*n);
    for(int i = 0;i<n;i++){
        tree[i+n] = arr[i];
    }
    for(int i = n-1;i>=1;i--){
        tree[i] = tree[2*i]+tree[2*i+1];
    }
    // for(int i = 1;i<2*n;i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<'\n';
    while(q-->0){
        int t;
        cin>>t;
        if(t==1){
            int x,v;
            cin>>x>>v;
            x--;
            update(1,x,0,n-1,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<sum_query(1,0,n-1,l,r)<<"\n";
        }
    }



}