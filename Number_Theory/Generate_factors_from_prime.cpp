#warning "don't forget to generate sieve"
multiset<ll> divs;
void generate_factors(vector<pair<int,int>> prime_factors,int index,ll vals){
    if(index>=prime_factors.size()){
       return;
    }else{
        ll a = 1;
        for(int i = 0;i<=prime_factors[index].second;i++){
            generate_factors(prime_factors,index+1,vals*a);
            a*=prime_factors[index].first;
        }
    }
}
void Prime_factor(int k){
    int count = 0;
    int prev = -1;
    vector<pair<int,int>> prime_factors;
    while(k>1){
        int a = sieve[k];
        if(prev!=a){
            if(count>0){
                prime_factors.push_back({prev,count});
            }
            prev = a;
            count = 1;
        }else{
            count++;
        }
        k = k/a;
    }
    if(count>0){
        prime_factors.push_back({prev,count});
    }
    generate_factors(prime_factors,0,1);
}