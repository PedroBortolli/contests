#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 505;
int t[2*N][N], mp[N];
const int inf = 2e9+5;

void update(int id, int tree, int x) {
	id += N;
	t[id][tree] = x;
	id /= 2;
	while (id > 0) {
		t[id][tree] = max(t[2*id][tree], t[2*id+1][tree]);
		id /= 2;
	}
} 

int query(int l, int r, int tree) {
	l += N;
	r += N+1;
	int ans = -INT_MAX;
	while (l < r) {
		if (l%2) ans = max(ans, t[l++][tree]);
		if (r%2) ans = max(ans, t[--r][tree]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

int main() {
	int n, m, k, q, x, y, tt;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < 2*N; i++) {
		for (int j = 0; j < N; j++) {
			t[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &x, &y, &tt);
		update(x, y, tt);
	}

	int ans = INT_MAX;
	for (int i = 1; i <= n-k+1; i++) {
		multiset <int> s;
		for (int j = 1; j <= m; j++) {
			if (j > k) s.erase(s.find(mp[j-k]));
			int mx = query(i, i+k-1, j);
			mp[j] = mx;
			s.insert(mx);
			if (j >= k) {
				auto it = *s.rbegin();
				if (it != INT_MAX) ans = min(ans, it);
			}
		}
	}

	if (ans == INT_MAX) ans = -1;
	printf("%d\n", ans);
	return 0;
}