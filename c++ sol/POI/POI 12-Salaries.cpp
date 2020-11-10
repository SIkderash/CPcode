/*
  Maintain a list of not used vertices and try adding them to the subtrees that are not yet filled. Attempt to put them in subtrees
of increasing order by value of the last filled vertex. If the list size is the same as the subtree size, you can keep putting vertices
from the unused list while there is exactly one child. Otherwise, subtract from list size the size of the subtree and replace all 
remaining values with 0s, since now there is no necessary values that should go in that subtree and in a different one. Using a stack,
this takes only O(n).
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

const int mxn = 1000001;
int n, k;
int a[mxn], b[mxn], f[mxn], sz[mxn];
vector<int> g[mxn];
stack<int> stk;

void dfs(int c, int p){
	for(int i : g[c]) if(i != p){
		dfs(i, c);
		if(!a[i]){
			sz[c] += sz[i] + 1;
			f[c] = !f[c] ? i : -1;
		}
	} 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int p;
		cin >> p >> a[i];
		if(p == i) b[a[k = i] = n] = i;
		else g[p].push_back(i);
		b[a[i]] = i;
	}
	
	dfs(k, 0);
	
	for(int i = 1; i <= n; i++){
		int x = b[i];
		if(!x){
			stk.push(i);
		}else if(sz[x]){
			if(sz[x] < stk.size()){
				x = stk.size() - sz[x];
				while(!stk.empty()) stk.pop();
				while(x--) stk.push(0);
			}else{
				while(f[x] > 0) a[x = f[x]] = stk.top(), stk.pop();
				while(!stk.empty()) stk.pop();
			}	
		} 
	}
	
	for(int i = 1; i <= n; i++) cout << a[i] << endl;

	return 0;
}
