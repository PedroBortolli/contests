#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005], seen[100005];
vector <int> a[100005];
map <int, int> id;
vector <int> ans;
void dfs(int x) {
	seen[x] = 1;
	ans.pb(x);
	for (auto it : a[x]) {
		if (!seen[it])
			dfs(it);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		id[v[i]] = i;
	}


	sort(v+1, v+n+1);
	for (int i = 1; i <= n; i++) {
		int x = id[v[i]];
		a[i].pb(x);
		a[x].pb(i);
	}

	int cont = 0;
	for (int i = 1; i <= n; i++) {
		if (seen[i]) continue;
		cont++;
		dfs(i);
	}

	printf("%d\n", cont);
	memset(seen, 0, sizeof(seen));
	for (int i = 1; i <= n; i++) {
		if (seen[i]) continue;
		ans.clear();
		dfs(i);
		printf("%d ", (int)ans.size());
		for (auto it : ans)
			printf("%d ", it);
		printf("\n");
	}
	
	return 0;
}