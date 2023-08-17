#include <bits/stdc++.h>
#define int long long
using namespace std;
 
 
void solve() { 
	int n, m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	while(m--) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited(n+1);
	vector<int> parent(n+1);
	queue<array<int, 2>> q;
	q.push({1, 1});
	visited[1]=true;
	int dist=-1;
	while(!empty(q)) {
		auto[a, b]=q.front();
		q.pop();
		if(a==n) {
			dist=b;
			break;
		}
		for(auto &x: adj[a]) {
			if(!visited[x]) {
				parent[x]=a;
				visited[x]=true;
				q.push({x, b+1});
			}
		}
	}
	if(dist==-1) {
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	cout<<dist<<endl;
	vector<int> res;
	int start=n;
	while(start!=0) {
		res.push_back(start);
		start=parent[start];
	}
	reverse(res.begin(), res.end());
	for(auto &x: res)
		cout<<x<<" ";
	cout<<endl<<parent[5];
}	
 
signed main() {
    ios_base::sync_with_stdio(false);	
    cin.tie(NULL);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}