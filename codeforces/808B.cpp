#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll sum[200005];
int main() {
	ll n, k, x;
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		sum[i] = x + sum[i-1];
	}

	ll ans = 0;
	for (int i = 1; i <= n-k+1; i++) {
		ans += (sum[i+k-1]-sum[i-1]);
	}

	printf("%.10lf\n", (double)ans/(double)(n-k+1));
	return 0;
}