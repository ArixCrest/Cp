//similar to 1D
struct FenwichTree2D{
    vector<vector<int>> bit;
    int n,m;
    FenwichTree2D(int n , int m){
        this->n = n;
        this->m = m;
        bit.resize(n,vector<int>(m,0));
    }
    FenwichTree2D(vector<vector<int>> arr): FenwichTree2D(arr.size(),arr[0].size()){
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                add(i, j, arr[i][j]);
            }
        }
    }
    int sum(int x,int y){
        int s = 0;
        for(int i = x;i>=0;i=(i&(i+1))-1){
            for(int j = y ;j>=0; j = (j&(j+1))-1){
                s += bit[i][j];
            }
        }
        return s;
    }
    void add(int x , int y , int delta){
        for (int i = x; i < n; i = i | (i + 1)){
            for (int j = y; j < m; j = j | (j + 1)){
                bit[i][j] += delta;
            }
        }
    }

};