#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[100005];
int seen[100005], dist[100005];
double ans = 0;
void dfs(int x, double p) {
	seen[x] = 1;
	double prob = 0;
	for (auto a : v[x]) {
		if (!seen[a]) prob++;
	}
	if (prob == 0) {
		ans += (double)dist[x]*p;
		return;
	}
	prob = p/prob;
	for (auto a : v[x]) {
		if (!seen[a])
			dfs(a, prob);
	}
}

int main() {
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	queue <int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		seen[x] = 1;
		for (auto a : v[x]) {
			if (!seen[a]) {
				dist[a] = dist[x]+1;
				q.push(a);
			}
		}
		q.pop();
	}
	memset(seen, 0, sizeof(seen));
	dfs(1, 1.0);
	printf("%.15lf\n", ans);
	return 0;
}