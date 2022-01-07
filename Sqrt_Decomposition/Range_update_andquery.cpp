#include <bits/stdc++.h>
using namespace std;

struct sqrt_decompositon{
    vector<int> arr,b;
    int n,len;
    const int INF = 1e9+9;
    //initializing
    sqrt_decompositon(int k){
        this->n = k;
        len = (int)sqrt(n)+1;
        arr.resize(n,0);
        b.resize(len,0);
    }
    sqrt_decompositon(vector<int> a): sqrt_decompositon(a.size()){
        for(int i = 0;i<n;i++){
            arr[i] = a[i];
        }
    }
    // increments the value delta at index
    void add(int index,int delta){
        arr[index]+=delta;
    }
    // adds the value of delta to the range [L,R]
    void range_update(int l,int r,int delta){
        int left = l/len,right = r/len;
        if(left==right){
            for(int i = l;i<=r;i++){
                arr[i]+=delta;
            }
            return;
        }
        for(int i = l,end = (left+1)*len-1;i<=end;i++){
            arr[i]+=delta;
        }
        for(int i = left+1;i<=right-1;i++){
            b[i]+=delta;
        }
        for(int i =right*len;i<=r;i++){
            arr[i]+=delta;
        }
        return;
    }
    long long point_query(int index){
        return arr[index]+b[index/len];
    }
    // return the sum in range [L,R]
    long long range_query(int l, int r){
        long long s = 0;
        int left = l/len,right = r/len;
        if(left==right){
            for(int i = l;i<=r;i++){
                s+=arr[i]+b[left];//can be left or right
            }
            return s;
        }
        for(int i = l,end = (left+1)*len-1;i<=end;i++){
            s+=(arr[i]+b[left]);
        }
        for(int i = left+1;i<=right-1;i++){
            s+= (b[i]*len);
        }
        for(int i =right*len;i<=r;i++){
            s+=(arr[i]+b[right]);
        }
        return s;
    }
};
int main(){
    int n;
    cin>>n;
    // vector<int> arr(n);
    // for(int i = 0;i<n;i++){
    //     cin>>arr[i];
    // }
    sqrt_decompositon sq(n);
    sq.range_update(0,4,1);
    sq.range_update(1,4,5);
    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<sq.range_query(l-1,r-1)<<"\n";
    }
}