#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[100005], a[100005], dp1[100005], dp2[100005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	for (int i = 0; i < n-1; i++)
		v[i] = abs(a[i]-a[i+1]);

	ll sum = 0;
	for (int i = 0; i < n-1; i++) {
		if (i%2) sum -= v[i];
		else sum += v[i];
		if (sum < 0) sum = 0;
		dp1[i] = max(sum, v[i]);
	}

	sum = 0;
	for (int i = 0; i < n-1; i++) {
		if (i%2) sum += v[i];
		else sum -= v[i];
		if (sum < 0) sum = 0;
		dp2[i] = max(sum, v[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n-1; i++)
		ans = max(ans, max(dp1[i], dp2[i]));

	printf("%lld\n", ans);
	return 0;
}