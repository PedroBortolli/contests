#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const ll mod = 998244353;
map <pair <ll, pair <ll, ll> >, ll > mp;

ll fat(ll x) {
	ll ans = 1;
	for (ll i = 1; i <= x; i++) {
		ans = (ans*i)%mod;
	}
	return ans;
}

ll calc(ll x, ll y, ll z) {
	if (mp[{x, {y, z}}]) return 0;
	mp[{x, {y, z}}] = 1;
	if (x == 0 && y == 0 && z == 0) return 0;
	ll ans = 1;
	ans = (ans * fat(x))%mod;
	ans = (ans * fat(y))%mod;
	ans = (ans * fat(z))%mod;
	//printf("Para  %lld  %lld  %lld   =   %lld\n", x, y, z, ans);
	return ans;
}

int main() {
	ll a, b, c, aa, bb, cc, cont, ans = 1;
	scanf("%lld %lld %lld", &a, &b, &c);

	//comecando com b
	aa = a, bb = b, cc = c, cont = 0;
	while (1) {
		if (cont%3 == 0) {
			if (!aa) break;
			aa--;
		}
		else if (cont%3 == 1) {
			if (!bb) break;
			bb--;
		}
		else {
			if (!cc) break;
			cc--;
		}
		cont++;
		ans = (ans + calc(a-aa, b-bb, c-cc))%mod;
	}


	aa = a, bb = b, cc = c, cont = 0;
	while (1) {
		if (cont%3 == 0) {
			if (!aa) break;
			aa--;
		}
		else if (cont%3 == 1) {
			if (!cc) break;
			cc--;
		}
		else {
			if (!bb) break;
			bb--;
		}
		cont++;
		ans = (ans + calc(a-aa, b-bb, c-cc))%mod;
	}


	aa = a, bb = b, cc = c, cont = 0;
	while (1) {
		if (cont%3 == 0) {
			if (!bb) break;
			bb--;
		}
		else if (cont%3 == 1) {
			if (!aa) break;
			aa--;
		}
		else {
			if (!cc) break;
			cc--;
		}
		cont++;
		ans = (ans + calc(a-aa, b-bb, c-cc))%mod;
	}


	aa = a, bb = b, cc = c, cont = 0;
	while (1) {
		if (cont%3 == 0) {
			if (!bb) break;
			bb--;
		}
		else if (cont%3 == 1) {
			if (!cc) break;
			cc--;
		}
		else {
			if (!aa) break;
			aa--;
		}
		cont++;
		ans = (ans + calc(a-aa, b-bb, c-cc))%mod;
	}


	aa = a, bb = b, cc = c, cont = 0;
	while (1) {
		if (cont%3 == 0) {
			if (!cc) break;
			cc--;
		}
		else if (cont%3 == 1) {
			if (!aa) break;
			aa--;
		}
		else {
			if (!bb) break;
			bb--;
		}
		cont++;
		ans = (ans + calc(a-aa, b-bb, c-cc))%mod;
	}

	aa = a, bb = b, cc = c, cont = 0;
	while (1) {
		if (cont%3 == 0) {
			if (!cc) break;
			cc--;
		}
		else if (cont%3 == 1) {
			if (!bb) break;
			bb--;
		}
		else {
			if (!aa) break;
			aa--;
		}
		cont++;
		ans = (ans + calc(a-aa, b-bb, c-cc))%mod;
	}


	printf("%lld\n", ans);
	return 0;
}