#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[11], dp[11][100005], len;

int go(int id, int left) {
	if (dp[id][left] != -1) return dp[id][left];
	if (id == len) {
		if (left == 0) return 1;
		else return 0;
	}
	int a = go(id+1, left), b = 0;
	if (left >= v[id]) b = go(id, left-v[id]);
	return dp[id][left] = a+b;
}

int main() {
	int n;
	scanf("%d %d", &n, &len);
	for (int i = 0; i < len; i++) {
		scanf("%d", &v[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, n));

	return 0;
}