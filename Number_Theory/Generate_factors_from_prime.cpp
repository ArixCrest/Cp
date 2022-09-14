#warning "don't forget to generate sieve"
vector<int> sieve(mx);
vector<pair<int,int>> prime_factors;
multiset<int> divs;
void generate_factors(int index,int size,int vals){
    if(index>=size){
       return;
    }else{
        int a = 1;
        for(int i = 0;i<=prime_factors[index].second;i++){
            generate_factors(index+1,size,vals*a);
            a*=prime_factors[index].first;
        }
    }
}
void Prime_factor(int k){
    int count = 0;
    int prev = -1;
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
    generate_factors(0,prime_factors.size(),1);
}