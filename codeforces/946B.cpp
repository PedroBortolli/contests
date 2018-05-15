#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll get(ll a, ll b) {
	ll div = (a-2*b)/(2*b);
	return div + 1;
}

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	while (1) {
		if (a == 0 or b == 0) break;
		if (a >= 2*b) a -= (get(a,b)*2*b);
		else if (b >= 2*a) b -= (get(b,a)*2*a);
		else break;
	}
	printf("%lld %lld\n", a, b);
	return 0;
}