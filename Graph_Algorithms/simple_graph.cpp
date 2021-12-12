struct graph{
    vector<vector<int>> edges;
    graph(int n ){
        edges.resize(n+1);
    }
    void add_undirected(int a , int b){
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    void add_directed(int a, int b){
        edges[a].push_back(b);
    }
    void print(){
        int i = 0;
        for(auto x : edges){
            cout<<i<<" : ";
            for(auto y : x){
                cout<<y<<" ";
            }
            cout<<"\n";
            i++;
        }
    }

};
