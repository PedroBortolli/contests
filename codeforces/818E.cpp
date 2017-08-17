#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5;
ll t[2*N], v[N];
ll n, k;

void build() {
	for (int i = n-1; i > 0; i--)
		t[i] = ((t[i*2]%k)*(t[i*2+1]%k))%k;
}

void modify(int id, int x) {
	id += n;
	t[id] = x;
	id /= 2;
	for (int i = id; i >= 1; i /= 2)
		t[i] = ((t[i*2]%k)*(t[i*2+1]%k))%k;
}

ll query(int l, int r) {
	ll ans = 1;
	l += n, r += n+1;
	while (l < r) {
		if (l%2 != 0) ans = ((ans%k)*(t[l++]%k))%k;
		if (r%2 != 0) ans = ((ans%k)*(t[--r]%k))%k;
		l /= 2;
		r /= 2;
	}
	return ans;
}


int main() {
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		t[i+n] = v[i];
	}
	build();

	ll ans = 0;
	int j = 0;
	for (int i = 0; i < n && j < n; i++) {
		while (query(i, j)) {
			j++;
			if (j >= n) break;
		}
		ans += (n-j);
	}

	printf("%lld\n", ans);
	return 0;
}