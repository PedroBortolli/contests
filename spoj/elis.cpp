#include <bits/stdc++.h>
using namespace std;

int v[15], dp[15], n, anss = 1;
int go(int id) {
	if (id == n+1) return 0;
	if (dp[id] != -1) return dp[id];
	int ans = 1;
	for (int i = id+1; i <= n; i++)
		if (v[i] > v[id]) ans = max(ans, 1+go(i));
	return dp[id] = ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0)-1);
	return 0;
}