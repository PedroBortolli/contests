#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5+5;
const ll mod = 1e9+7;
pii v[N];
int bit[N];

void update(int id) {
	bit[id]++;
	while (id < N) {
		bit[id]++;
		id += id&-id;
	}
}

int query(int id) {
	int ans = 0;
	while (id > 0) {
		ans += bit[id];
		id -= id&-id;
	}
	return ans;
}

int main() {
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v[i] = {x, y};
	}

	sort(v, v+n);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int x = query(v[i].second);
		ans += (ll)x;
		ans %= mod;
		update(v[i].second);
	}

	printf("%lld\n", ans);
	return 0;
}