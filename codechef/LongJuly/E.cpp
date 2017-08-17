#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll no[1000005], no2[1000005];
ll mod = 1000000007;
ll mod2 = mod+2;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll gcdEx(ll a, ll b, ll *x, ll *y) {
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll g = gcdEx(b%a, a, &x1, &y1);
	*x = y1 - (b/a)*x1;
	*y = x1;
	return g;
}

ll modInverse(ll a, ll m) {
	ll x, y;
	ll g = gcdEx(a, m, &x, &y);
	return (x%m + m)%m;
}

int main() {
	ll tt, n;
	scanf("%lld", &tt);

	no[1] = 1;
	no[2] = 1;
	no[3] = 2;
	for (int i = 4; i < 1000005; i++) {
		no[i] = no[i-1]*2+1;
		no[i] %= mod;
	}
	no2[1] = 1;
	no2[2] = 1;
	no2[3] = 2;
	for (int i = 4; i < 1000005; i++) {
		no2[i] = no2[i-1]*2+1;
		no2[i] %= mod2;
	}
	while (tt--) {
		scanf("%lld", &n);
		ll p, q;
		if (n == 1) p = 0;
		else if (n == 2) p = 1;
		else if (n == 3) p = 2;
		else p = n+(n-2);
		q = no[n];

		ll z = gcd(p, q);
		//printf("p = %lld     q = %lld     z = %lld\n", p, q, z);
		p /= z;
		q /= z;
		z = modInverse(q, mod);
		//printf("p = %lld     q = %lld     z = %lld\n", p, q, z);
		printf("%lld ", (z*p)%mod);

		if (n == 1) p = 0;
		else if (n == 2) p = 1;
		else if (n == 3) p = 2;
		else p = n+(n-2);
		q = no2[n];

		z = gcd(p, q);
		//printf("p = %lld     q = %lld     z = %lld\n", p, q, z);
		p /= z;
		q /= z;
		z = modInverse(q, mod2);
		//printf("p = %lld     q = %lld     z = %lld\n", p, q, z);
		printf("%lld\n", (z*p)%mod2);
	}

	return 0;
}