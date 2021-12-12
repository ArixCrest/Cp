struct dsu{
    vector<int> parent;
    dsu(int n){
        for(int i = 0;i<n;i++){
            parent.push_back(i);
        }
    }
    int find_parent(int a){
        return (parent[a]==a)? (a) : (parent[a] = find_parent(parent[a]));
    }
    bool make_union(int a, int b ){
        a = find_parent(a);
        b = find_parent(b);
        if(a==b) return false;
        if(a>b) swap(a,b);
        parent[b] = a;
        return true;
    }
    bool check(int a,int b){
        int u = find_parent(a);
        int v = find_parent(b);
        if(u==v) return false;
        else return true;
    }
    
};
