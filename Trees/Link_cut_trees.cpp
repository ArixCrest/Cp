#include <bits/stdc++.h>
using namespace std;
// not very sure about the implementation
// link is not working properly
struct Link_cut_tree{
    vector<vector<int>> c;
    vector<int> fa;
    vector<int> size;
    Link_cut_tree(int n){
        c.resize(n,vector<int>(2));
        fa.resize(n);
        size.resize(n,0);
    }
	inline void pushup(int x)
	{
		size[x]=size[c[x][0]]+size[c[x][1]]+1;
	}
	inline bool isroot(int x)
	{
		return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
	}
	inline void rotate(int x)
	{
		int y=fa[x],z=fa[y],l,r;
		if(c[y][0]==x){
			l=0;
        }
		else{
			l=1;
        }
		r=l^1;
		if(!isroot(y)){
			if(c[z][0]==y){
				c[z][0]=x;
            }
			else{
				c[z][1]=x;
            }
        }
		fa[x]=z;
		fa[y]=x;
		fa[c[x][r]]=y;
		c[y][l]=c[x][r];
		c[x][r]=y;
		pushup(y);
		pushup(x);
	}
	inline void splay(int x)
	{
		while(!isroot(x))
		{
			int y=fa[x],z=fa[y];
			if(!isroot(y)){
				if((c[y][0]==x)^(c[z][0]==y)){
					rotate(x);
                }
				else{
					rotate(y);
                }
            }
			rotate(x);
		}
	}
	inline void access(int x)
	{
		for(int t=0;x;t=x,x=fa[x])
		{
			splay(x);
			c[x][1]=t;
			pushup(x);
		}
	}
	inline int find(int x)
	{
        if(fa[x]==x){
            return x;
        }
		access(x);
		splay(x);
		while(c[x][0]){
			x=c[x][0];
        }
		return x;
	}
	inline void cut(int x)
	{
		access(x);
		splay(x);
		fa[c[x][0]]=0;
		c[x][0]=0;
		pushup(x);
	}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    Link_cut_tree Tree(n+1);
    while(m--){
        string s;
        cin>>s;
        if(s=="conn"){
            int a,b;
            cin>>a>>b;
            a = Tree.find(a);
            b = Tree.find(b);
            //cout<<a<<" "<<b<<"\n";
            if(a==b && a!=0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
        else if(s=="add"){
            int a,b;
            cin>>a>>b;
            if(a>b){
                swap(a,b);
            }
            Tree.fa[a] = b;
            Tree.access(a);
            Tree.access(b);
            
        }else{
            int a,b;
            cin>>a>>b;
            if(a>b){
                swap(a,b);
            }
            Tree.cut(a);
        }
    }
}