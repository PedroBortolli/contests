#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}

int main() {
	ll n, k, x = 1;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < k; i++) {
		x *= 10;
	}
	printf("%lld\n", lcm(n, x));
	return 0;
}