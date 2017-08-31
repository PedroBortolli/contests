#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, a, b, c;
int dp[4005];

int go(int left) {
	if (left < 0) return -100000000;
	if (left == 0) return 0;
	if (dp[left] != -1) return dp[left];
	int ans = -10000000;
	ans = max(ans, 1+go(left-a));
	ans = max(ans, 1+go(left-b));
	ans = max(ans, 1+go(left-c));
	return dp[left] = ans;
}

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &c);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n));
	return 0;
}