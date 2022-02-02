
struct TrieNode
{
	TrieNode *child[2];
	TrieNode() {
		child[0] = child[1] = NULL;
	}
};



void insertTrie(TrieNode *root, int N) {

	for (int i = 30; i >= 0; i--) {
		
		bool x = (N) & (1 << i);
		
		if(!root->child[x]) {
			root->child[x] = new TrieNode();
		}
		root= root->child[x];
	}
}
pair<int,int> max_xor(TrieNode* root,int a){
	int res = 0;
	int val = 0;
	for(int i = 30;i>=0;i--){
		bool x = a&(1<<i);
		if(root->child[1-x]){
			root = root->child[1-x];
			res = res|(1<<i);
			val = val|((1-x)<<i);
		}else{
			root = root->child[x];
			val = val|(x<<i);
		}
	}
	return {res,val};
}