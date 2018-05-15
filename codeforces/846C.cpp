#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int to[5005];
ll dp[5005], sum[5005];
ll const inf = 1e15+5;

int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		sum[i] = sum[i-1]+x;
		dp[i] = -inf;
	}
	dp[n+1] = -inf;
	for (int i = 1; i <= n+1; i++) {
		for (int j = i; j <= n+1; j++) {
			ll gain = sum[j-1]-sum[i-1];
			gain -= (sum[n]-sum[j-1]);
			if (gain > dp[i]) {
				dp[i] = gain;
				to[i] = j;
			}
		}
	}
	ll ans = -inf;
	pair <pii, int> p;
	for (int i = 1; i <= n+1; i++) {
		for (int j = i; j <= n+1; j++) {
			ll gain = sum[i-1];
			gain -= (sum[j-1]-sum[i-1]);
			gain += dp[j];
			if (gain > ans) {
				ans = gain;
				p.first.first = i-1;
				p.first.second = j-1;
				p.second = to[j]-1;
			}
		}
	}
	printf("%d %d %d\n", p.first.first, p.first.second, p.second);
	return 0;
}