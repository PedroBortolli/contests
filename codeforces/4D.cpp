#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int dp[5005], ch[5005], wi[5005], he[5005], n, W, H;

int go(int id, int ww, int hh) {
	if (dp[id] != -1) return dp[id];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (wi[i] > ww && he[i] > hh) {
			int aux = 1+go(i, wi[i], he[i]);
			if (aux > ans) {
				ans = aux;
				ch[id] = i;
			}
		}
	}
	return dp[id] = ans;
}

int main() {
	scanf("%d %d %d", &n, &W, &H);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &wi[i], &he[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, W, H));
	int id = 0;
	while (ch[id]) {
		printf("%d ", ch[id]);
		id = ch[id];
	}
	return 0;
}