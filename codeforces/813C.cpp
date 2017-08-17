#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[200005];
int bob[200005];
int ali[200005];

int main() {
	int n, x, y, z;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &y, &z);
		v[z].pb(y);
		v[y].pb(z);
	}

	queue <int> q;
	q.push(1);
	ali[1] = 1;
	while (!q.empty()) {
		int f = q.front();
		for (auto a : v[f]) {
			if (!ali[a]) {
				ali[a] = ali[f]+1;
				q.push(a);
			}
		}
		q.pop();
	}

	q.push(x);
	bob[x] = 1;
	while (!q.empty()) {
		int f = q.front();
		for (auto a : v[f]) {
			if (!bob[a]) {
				bob[a] = bob[f]+1;
				q.push(a);
			}
		}
		q.pop();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bob[i]--;
		ali[i]--;
		if (ali[i] <= bob[i]) continue;
		ans = max(ans, ali[i]*2);
	}

	printf("%d\n", ans);
	return 0;
}