
//builds the suffix array in n(log(n)^2) time.
vector<int> suffi_arr(string s){
    s+='$';
    int n = s.length();
    vector<int> idx(n),c(n);
    {
        vector<pair<char,int>> a(n);
        for(int i = 0;i<n;i++){
            a[i] = {s[i],i};
        }
        sort(a.begin(),a.end());
        for(int i = 0;i<n;i++) idx[i] = a[i].second;
        c[idx[0]] = 0;
        for(int i = 0;i<n;i++){
            if(a[i].first==a[i-1].first){
                c[idx[i]] = c[idx[i-1]];
            }else{
                c[idx[i]] = c[idx[i-1]]+1;
            }
        }
    }
    int k = 0;
    while((1<<k)<n){
        vector<pair<pair<int,int>,int>> a(n);
        for(int i = 0;i<n;i++){
            a[i] = {{c[i],c[(i+(1<<k))%n]},i};
        }
        sort(a.begin(),a.end());
        for(int i = 0;i<n;i++) idx[i] = a[i].second;
        c[idx[0]] = 0;
        for(int i = 0;i<n;i++){
            if(a[i].first==a[i-1].first){
                c[idx[i]] = c[idx[i-1]];
            }else{
                c[idx[i]] = c[idx[i-1]]+1;
            }
        }
        k++;
    }
    for(int i = 0;i<n;i++){
        cout<<idx[i]<<" "<<s.substr(idx[i],n-idx[i])<<"\n";
    }
    return idx;
}
