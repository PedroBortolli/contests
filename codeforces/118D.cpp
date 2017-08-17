#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll n1, n2, k1, k2, dp[105][105][15][15], mod = 100000000;

ll go(int left1, int left2, int cont1, int cont2, int sze) {
	if (dp[left1][left2][cont1][cont2] != -1) return dp[left1][left2][cont1][cont2];
	if (sze == n1+n2) {
		if (left1 == 0 && left2 == 0) return 1ll;
		else return 0ll;
	}
	ll ans = 0;
	if (cont1 < k1 && left1 > 0) ans = (ans+go(left1-1, left2, cont1+1, 0, sze+1))%mod;
	if (cont2 < k2 && left2 > 0) ans = (ans+go(left1, left2-1, 0, cont2+1, sze+1))%mod;
	return dp[left1][left2][cont1][cont2] = ans%mod;
}

int main() {
	scanf("%lld %lld %lld %lld", &n1, &n2, &k1, &k2);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(n1, n2, 0, 0, 0));
	return 0;
}