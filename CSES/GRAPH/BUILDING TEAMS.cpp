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
	vector<int> color(n+1, -1); //to track the group
	for(int i=1; i<n; i++) {
		if(color[i]==-1) {
			queue<int> q;
			q.push(i);
			color[i]=0;
			while(!empty(q)) {
				int a=q.front();
				q.pop();
				for(auto &x: adj[a]) {
					if(color[x]==-1) {
						color[x]=1-color[a];
						q.push(x);
					}
					else if(color[a]^(1-color[x])) {
						cout<<"IMPOSSIBLE"<<endl;
						return;
					}
				}
			}
		}
	}
	for(int i=1; i<=n; i++)
		cout<<color[i]+1<<" ";
}	
 
signed main() {
    ios_base::sync_with_stdio(false);	
    cin.tie(NULL);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}