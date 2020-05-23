#include<bits/stdc++.h>

using namespace std;

void build(int *t, int *a, int pos, int low, int high){
	if(low == high){
		t[pos] = a[low];
	}else{
		int mid = (low + high) / 2;
		build(t,a, pos*2+1, low, mid);
		build(t,a, pos*2 + 2, mid+1, high);
		// t[pos] = min(t[pos*2+1], t[pos*2+2]); // min query
		//t[pos] = max(t[pos*2+1], t[pos*2+2]); // max query
		t[pos] = t[pos*2+1] + t[pos*2+2]; // sum query
	}
}

int minquery(int *t, int *a, int v, int tl, int tr, int ql, int qr){
	if(ql <= tl && qr >= tr){
		return t[v];
	}
	if(ql > tr || qr < tl)
		return INT_MAX;
	int tm = (tr+tl) / 2;
	
	return min(minquery(t,a,2*v+1,tl,tm,ql,qr), minquery(t,a,2*v+2,tm+1,tr,ql,qr));
}
int maxquery(int *t, int *a, int v, int tl, int tr, int ql, int qr){
	if(ql <= tl && qr >= tr){
		return t[v];
	}
	if(ql > tr || qr < tl)
		return INT_MIN;
	int tm = (tr+tl) / 2;
	
	return max(maxquery(t,a,2*v+1,tl,tm,ql,qr), maxquery(t,a,2*v+2,tm+1,tr,ql,qr));
}

int sumquery(int *t, int *a, int v, int tl, int tr, int ql, int qr){
	if(ql <= tl && qr >= tr){
		return t[v];
	}
	if(ql > tr || qr < tl)
		return 0;
	int tm = (tr+tl) / 2;
	
	return sumquery(t,a,2*v+1,tl,tm,ql,qr) + sumquery(t,a,2*v+2,tm+1,tr,ql,qr);
}

void update(int *t, int low, int high, int pos, int ipos ,int val){
	if(low == high){
		t[pos] = val;
	}else{
		mid = (low+high) / 2;
		if(ipos <= mid){
			update(t,low,mid,2*i+1,ipos,val);
		}else{
			update(t,mid+1,high,2*i+2,ipos,val);
		}
		t[pos] = t[2*pos+1] + t[2*pos+2]; // for sum query
	}
}

int main(){
	int n = 7;
	int arr[] = {3,2,0,6,5,-1,2};
	int stree[4*n];
	build(stree, arr, 0, 0,n-1);
	cout << endl;
	cout << sumquery(stree,arr,0,0,n-1,0,6);
}
