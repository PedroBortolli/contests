#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

pair <int, pii> v[100005];
int t[200005], n, d;

void update(int id, int x) {
	id += d;
	t[id] += x;
	id /= 2;
	while (id > 0) {
		t[id] = t[2*id]+t[2*id+1];
		id /= 2;
	}
}

int query(int l, int r) {
	l += d;
	r += d+1;
	int ans = 0;
	while (l < r) {
		if (l%2) ans += t[l++];
		if (r%2) ans += t[--r];
		l /= 2;
		r /= 2;
	}
	return ans;
}


int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int di, ti, si;
		scanf("%d %d", &n, &d);
		set <int> s;
		set <int>::iterator it;
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= d; i++)
			s.insert(i);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &di, &ti, &si);
			v[i] = mp(si, mp(-ti, di));
		}
		sort(v, v+n);
		ll ans = 0;
		for (int i = n-1; i >= 0; i--) {
			si = v[i].first;
			ti = -v[i].second.first;
			di = v[i].second.second;
			int q = query(di, d);
			int aux = min(d-di+1-q, ti);
			int prev = di;
			while (aux--) {
				it = s.lower_bound(prev);
				update(*it, 1);
				s.erase(*it);
				ti--;
			}
			ans += ((ll)ti*(ll)si);
		}
		printf("%lld\n", ans);
	}	

	return 0;
}