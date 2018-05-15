#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll sl[100005], a[100005], b[100005], aux[100005];
ll n, tot = 0, s, piz;
set <pll> st;
pll v[100005];

void go() {
	for (ll i = 0; i < n; i++)
		aux[i] = sl[i];
}

ll f(ll m) {
	ll ans = 0;
	ll mm = piz-m;
	printf("m = %lld    mm = %lld\n", m, mm);

	for (int i = 0; i < n; i++) {
		while (1) {
			if (mm == 0 or aux[i] == 0) break;
			mm--;
			aux[i]--;
			ans += b[i];
		}
	}
	

	for (int i = n-1; i >= 0; i--) {
		while (1) {
			if (mm == 0 or aux[i] == 0) break;
			mm--;
			aux[i]--;
			ans += a[i];
		}
	}
	
	
	printf("apos pegar = %lld    (m = %lld    mm = %lld)\n", ans, m, mm);
	return ans;
}

int main() {
	ll need = 0;
	scanf("%lld %lld", &n, &s);
	for (ll i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &sl[i], &a[i], &b[i]);
		st.insert({a[i]-b[i], i});
		v[i] = {a[i], b[i]};
		tot += (sl[i]*a[i] + sl[i]*b[i]);
		need += sl[i];
	}

	sort(v, v+n);

	
	ll l = 0, r = need/s + (need%s != 0) - 1, m, ans = 0;
	piz = need;
	printf("l = %lld    r = %lld\n", l, r);

	if (r == 0) {
		ll aa = 0, bb = 0;
		for (ll i = 0; i < n; i++) {
			aa += sl[i]*a[i];
			bb += sl[i]*b[i];
		}
		printf("%lld\n", max(aa, bb));
		return 0;
	}

	while (l <= r) {
		m = (l+r)/2;
		printf("Testando m = %lld\n", m);
		ll pri = 2;
		if (piz-m )
		go();
		ll x = f(m*s);
		go();
		ll y = f((m+1)*s);
		if (y > x) {
			ans = max(ans, y);
			printf("	ans agora = %lld\n", ans);
			l = m+1;
		}
		else {
			ans = max(ans, x);
			printf("	ans agora = %lld\n", ans);
			r = m-1;
		}
	}

	printf("%lld\n", ans);
	return 0;
}