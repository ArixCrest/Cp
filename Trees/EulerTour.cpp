vector<vector<int>> graph;
vector<int> tin,tout;
int timer;
void dfs(int cur,int par){
    tin[cur] = timer++;
    for(auto x : graph[cur]){
        if(x!=par){
            dfs(x,cur);
        }
    }
    tout[cur] = timer-1;
}
// [tin[i],tout[i]] corresponds to the range of the subtree
// tin[i] corersponds to the positions of node i in the array.
// the range [tin[i],tout[i]] contains the range [tin[j],tout[j]]
// if j is in the subtree rooted at i.
//Basically method to flatten a rooted tree into an array.
