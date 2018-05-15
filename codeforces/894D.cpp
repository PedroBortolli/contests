#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll c[1000005][3];
int main() {
	ll n, m, l;
	int k = 1, p = 0;
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n-1; i++) {
		scanf("%lld", &l);
		c[k][p] = l;
		p++;
		if (p == 2) {
			k++;
			p = 0;
		}
	}

	


	return 0;
}