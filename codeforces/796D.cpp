#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int p[300005], seen[300005], dist[300005];
vector <int> v[300005];
vector <pii> road;
set <int> ans;
multiset <pii> need;
int main() {
	int n, k, d, x, y;
	multiset <pair<pii, int>> q;
	scanf("%d %d %d", &n, &k, &d);
	memset(dist, 1000000007, sizeof(dist));
	for (int i = 0; i < k; i++) {
		scanf("%d", &p[i]);
		dist[p[i]] = 0;
		q.insert(mp(mp(0, p[i]), -1));
	}

	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &x, &y);
		road.pb(mp(x,y));
		v[x].pb(y);
		v[y].pb(x);
	}

	while (!q.empty()) {
		pair <pii, int> f = *(q.begin());
		x = f.first.second;
		seen[x] = 1;
		dist[x] = y;
		y = f.first.first+1;
		int prev = f.second;
		for (auto a : v[x]) {
			if (!seen[a]) {
				q.insert(mp(mp(y, a), x));
				seen[a] = 1;
				if (dist[a] > d) {
					need.insert(mp(x,a));
					need.insert(mp(a,x));
				}
			}
		}
		q.erase(q.find(f));
	}

	int cont = 0;
	for (auto a : road) {
		cont++;
		if (need.find(a) == need.end()) ans.insert(cont);
	}

	printf("%d\n", (int)ans.size());
	for (auto a : ans)
		printf("%d ", a);
	printf("\n");
	return 0;
}