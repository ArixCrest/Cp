vector<vector<int>> tree;
vector<vector<int>> marked;

void push(int index, int v) {
    if (marked[index][v]) {
        tree[index][v*2] = tree[index][v*2+1] = tree[index][v];
        marked[index][v*2] = marked[index][v*2+1] = true;
        marked[index][v] = false;
    }
}

void update(int index,int v,int tl, int tr, int l, int r , int new_val) {
    //if(v>=(1<<14)) return;
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[index][v] = new_val;
        marked[index][v] = true;
    } else {
        //cout<<v<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<'\n';
        push(index,v);
        int tm = (tl + tr) / 2;
        update(index, v*2, tl, tm, l, min(r, tm), new_val);
        update(index ,v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int index,int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return tree[index][v];
    }
    push(index,v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(index,v*2, tl, tm, pos);
    else
        return get(index,v*2+1, tm+1, tr, pos);
}