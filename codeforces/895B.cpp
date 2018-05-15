#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5 + 5;
map <ll, ll> from, to, mp;
ll a[N], seg[8*N];
set <ll> inp;


void update(ll id, ll x) {
	id += N;
	seg[id] += x;
	id /= 2;
	for (int i = id; i >= 1; i /= 2)
		seg[i] = seg[i*2]+seg[i*2+1];
}

ll query(ll l, ll r) {
	ll ans = 0;
	l += N, r += N+1;
	while (l < r) {
		if (l%2 != 0) ans += seg[l++];
		if (r%2 != 0) ans += seg[--r];
		l /= 2;
		r /= 2;
	}
	return ans;
}


int main() {
	ll n, x, k;
	scanf("%lld %lld %lld", &n, &x, &k);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		ll ratio = a[i]/x + (a[i]%x != 0);
		from[a[i]] = ratio*x + (k-1)*x;
		to[a[i]] =  from[a[i]] + x - 1;
		inp.insert(a[i]);
		inp.insert(from[a[i]]);
		inp.insert(to[a[i]]);
		inp.insert(ratio*x - 1);
	}
	sort(a, a+n);

	ll c = 1;
	for (auto a : inp) {
		mp[a] = c;
		c++;
	}
	for (ll i = 0; i < n; i++) {
		update(mp[a[i]], 1);
		//printf("Para  %lld         from  %lld    to %lld\n", a[i], from[a[i]], to[a[i]]);
	}


	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll f = from[a[i]];
		ll t = to[a[i]];
		if (t < to[a[i]]) continue;

		if (!k) {
			if (a[i]%x == 0) continue;
			ll ratio = a[i]/x + 1;
			//printf("Query de %lld ate %lld  (%lld => %lld)   =   ", a[i], ratio*x-1, mp[a[i]], mp[ratio*x-1]);
			//printf("%lld\n", query(mp[a[i]], mp[ratio*x-1]));
			ans += query(mp[a[i]], mp[ratio*x-1]);
		}

		else {
			//printf("Query de %lld ate %lld   (%lld => %lld)   =   ", f, t, mp[f], mp[t]);
			//printf("%lld\n", query(mp[f], mp[t]));
			ans += query(mp[f], mp[t]);
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}