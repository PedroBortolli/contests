#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


const int N = 2e5;
int n;
int t[2 * N], v[N];

void build() {
	for (int i = N-1; i > 0; i--)
		t[i] = min(t[i*2], t[i*2+1]);
}

void modify(int id, int x) {
	id += N;
	t[id] = x;
	id /= 2;
	for (int i = id; i >= 1; i /= 2)
		t[i] = min(t[i*2], t[i*2+1]);
}

int query(int l, int r) {
	int ans = 1000000000;
	l += N, r += N;
	while (l < r) {
		if (l%2 != 0) ans = min(ans, t[l++]);
		if (r%2 != 0) ans = min(ans, t[--r]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

vector <int> pos[N];

int main() {
	int n, mx = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		t[i+N] = v[i];
		pos[v[i]].pb(i);
		mx = max(mx, v[i]);
	}

	build();
	int x = 1, ans = 0;
	
	while (x <= mx) {
		if (pos[x].empty()) {
			x++;
			continue;
		}
		if ((int)pos[x].size() == 1) {
			x++;
			ans++;
			continue;
		}
		ans++;
		for (int i = 0; i < pos[x].size() - 1; i++) {
			int y = pos[x][i];
			int z = pos[x][i+1];
			int q = query(y, z+1);
			if (q < x) ans++;
		}
		x++;
	}
	printf("%d\n", ans);
}