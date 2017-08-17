#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll power[300005], v[300005], dif[300005];
const ll mod = 1000000007;
int main() {
	power[0] = 1ll;
	for (int i = 1; i <= 300002; i++) {
		power[i] = (power[i-1]*2ll)%mod;
	}

	int n;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &v[i]);

	sort(v, v+n);
	for (int i = 0; i < n; i++)
		ans = (ans%mod + ((v[i]%mod)*((power[i] - power[n-i-1])%mod))%mod)%mod;

	printf("%lld\n", ans%mod);
	return 0;
}