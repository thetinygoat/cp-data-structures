#include<bits/stdc++.h>
using namespace std;
int getnext(int idx){
	return idx + (idx & -idx);
}
int parent(int idx){
	return idx - (idx & -idx);
}
void update(vector<int> &tree, int idx, int val){
	while(idx < tree.size()){
		tree[idx] += val;
		idx = getnext(idx);
	}
}

void build(vector<int> &tree, vector<int> &input){
	for(int i = 1; i <= input.size(); i++){
		update(tree,i, input[i-1]);
	}
}

int sum(int idx, vector<int> &tree){
	idx = idx + 1;
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx = parent(idx);
	}
	return sum;
}

int main(){
	vector<int> input = {1,2,3,4,5,6,7};
	vector<int> tree(input.size() + 1);
	build(tree,input);
	cout << sum(4, tree);
	return 0;
}
