#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll a[100005], b[100005];
int main() {
	ll n, sum = 0;
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	sort(b, b+n);
	for (ll i = n-1; i >= n-2; i--) {
		sum -= b[i];
	}

	if (sum <= 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}