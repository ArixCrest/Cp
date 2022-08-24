vector<ll> tree,lazy,type;
int n; // size of array need to inc to next power of 2
// type 1 is for assignment and type 2 is for increment
// supports range increment and range assignment with sum queries.
void propagate(int cur,int sz){
	if(lazy[cur]!=0){
		if(type[cur]==1){
			tree[cur*2] = (sz/2)*lazy[cur];
			tree[cur*2+1] = (sz/2)*lazy[cur];
		}else{
			tree[cur*2] +=(sz/2)*lazy[cur];
			tree[cur*2+1] +=(sz/2)*lazy[cur];
		}
		if(sz>2){
			if(type[cur]==1){
				lazy[cur*2] = lazy[cur];
				lazy[cur*2+1] = lazy[cur];
				type[cur*2] = type[cur];
				type[cur*2+1] = type[cur];
			}else{
				if(type[cur*2]==2){
					lazy[cur*2]+=lazy[cur];
				}else{
					propagate(cur*2,sz/2);
					lazy[cur*2] += lazy[cur];
				}
				if(type[cur*2+1]==2){
					lazy[cur*2+1]+=lazy[cur];
				}else{
					propagate(cur*2,sz/2);
					lazy[cur*2+1] += lazy[cur];
				}
			}
		}
		lazy[cur] = 0;
		type[cur] = 0;
	}else{
		return;
	}
}
// cur node (1 for start) , left point of cur_node, right point of cur node, query left, query right
// basically for update do (update(1,0,n-1,ql,qr,....))
void update(int cur,int l,int r,int ql,int qr,ll value,int qtype){
	if(ql>r || qr<l) return;
	if(ql<=l && qr>=r){
		if(l!=r){
			propagate(cur,r-l+1);
			if(qtype==1){
				tree[cur] = (r-l+1)*value;
			}else{
				tree[cur] += (r-l+1)*value;
			}
			lazy[cur] = value;
			type[cur] = qtype;
		}else{
			if(qtype==1) tree[cur] = value;
			else tree[cur] += value;
		}
		return;
	}
	propagate(cur,r-l+1);
	int mid = (l+r)>>1;
	update(cur*2,l,mid,ql,qr,value,qtype);
	update(cur*2+1,mid+1,r,ql,qr,value,qtype);
	tree[cur] = (tree[cur*2]+tree[cur*2+1]);
}
// call query(1,0,n-1,qr,ql) for range sum.
ll query(int cur,int l,int r, int ql,int qr){
	if(ql>r || qr<l) return 0;
	if(ql<=l && qr>=r){
		if(l!=r){
			propagate(cur,r-l+1);
			return tree[cur];
		}else{
			return tree[cur];
		}
	}
	propagate(cur,r-l+1);
	int mid = (l+r)>>1;
	return query(cur*2,l,mid,ql,qr)+query(cur*2+1,mid+1,r,ql,qr);
}