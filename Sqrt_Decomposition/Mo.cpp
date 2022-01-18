#include <bits/stdc++.h>

using namespace std;
// only provies range sum, min or max and range add or update

//different comparator not needed since we are already doing blocks
// struct Query{
//     int l,r,ind;
//     bool operator <(Query other) const{
//         return make_pair(l/block_size,r)<make_pair(other.l/block_size,r);
//     }
// };
const int block_size= 314;
struct Query{
    int l,r,ind;
    bool operator <(const Query other) const{
        return r<other.r;
    }
};
//just copy this in which takes input of queries
// modify the Mo's code to what the question needs

    vector<vector<Query>> queries(n/block_size+2,vector<Query>());
    // m is size of queries
	rep(x,0,m){
		int l,r;
		cin>>l>>r;
        // this is considering zero indexing
        //if one indexing is used then r++ should be used
		l--;
		//r++;
		queries[l/block_size].push_back(Query{l,r,x});
 	}
	for(auto &q : queries){
		sort(q.begin(),q.end());
	}
	vector<ll> answers(m);
	for(int i = 0;i<queries.size();i++){
		int left,right;
		left = right = i*block_size;
		for(Query q : queries[i]){
			while(right<q.r){
                // add the element
				add()
				right++;
			}
			while(left<q.l){
                //del the element
				del();
				left++;
				
			}
			while(left>q.l){
                //add the elment
				left--;
				add();
				
			}
            //answer the query
			answers[q.ind] = //ans;
		}
		for(int j=left;j<right;j++){
			//make sure the changes from this block do not affect the next one
		}
	}
    for(auto x : answers){
		cout<<x<<'\n';
	}

