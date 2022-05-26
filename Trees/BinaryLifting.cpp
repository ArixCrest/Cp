vector<vector<int>> graph;
// Note if you want to have some cases where the output 
//of parent of 1 should be zero then u gotta have to use dfs(1,0) instead of df(1,1)
// also the up stores 1,2,4,8... th ancestor
struct binlift{
    int n,l;
    int timer = 0;
    vector<int> tin,tout;
    vector<vector<int>> up;
    binlift(int n){
        tin.resize(n+1);
        tout.resize(n+1);
        l = ceil(log2(n));
        up.assign(n+1,vector<int>(l+1));
    }
    void dfs(int cur,int par){
        up[cur][0] = par;
        tin[cur] = timer++;
        for(int i = 1;i<=l;++i){
            up[cur][i] = up[up[cur][i-1]][i-1];
        }
        for(auto x : graph[cur]){
            if(x!=par){
                dfs(x,cur);
            }
        }
        tout[cur] = timer-1;
    }

    bool ancestor(int u,int v){
        return (tin[u]<=tin[v] && tout[u]>=tout[v]);
    }
    //ones_index
    int lca(int u,int v){
        if(ancestor(u,v)) return u;
        if(ancestor(v,u)) return v;
        for(int i = l;i>=0;--i){
            if(!ancestor(up[u][i],v)){
                u = up[u][i];
            }
        }
        return up[u][0];
    }
};
