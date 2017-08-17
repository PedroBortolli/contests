#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, dp[5005][5005], ans[5005];
bool pali[5005][5005], same[5005][5005];
char s[5005];
const int inf = 1123456;

int go(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];
	if (a == b) return 1;
	if (a+1 == b) {
		if (s[a] != s[b]) return -inf;
		else return 2;
	}
	int sze = b-a+1;
	sze /= 2;
	if (!pali[a][a+sze-1]) return 1;
	int k = go(a, a+sze-1);
	return dp[a][b] = 1+k;
}

int calc(int a, int b) {
	if (!pali[a][b]) return dp[a][b] = -inf;
	ans[1]++;
	if (a == b) dp[a][b] = 1;
	else if (a+1 == b) {
		if (s[a] == s[b]) {
			dp[a][b] = 2;
		}
		else dp[a][b] = -inf;
	}
	else go(a,b);
	//printf("%d %d eh tambem %d\n", a, b, x);
}

void checkPali(int x) {
	pali[x][x] = true;
	int a = x-1;
	int b = x+1;
	while (a >= 0 && b < n) {
		if (s[a] == s[b]) pali[a][b] = true;
		else break;
		a--;
		b++;
	}
	a = x;
	b = x+1;
	while (a >= 0 && b < n) {
		if (s[a] == s[b]) pali[a][b] = true;
		else break;
		a--;
		b++;
	}
	a = x-1;
	b = x;
	while (a >= 0 && b < n) {
		if (s[a] == s[b]) pali[a][b] = true;
		else break;
		a--;
		b++;
	}
}


int main() {
	scanf(" %s", s);
	n = strlen(s);
	memset(pali, false, sizeof(pali));
	memset(same, false, sizeof(same));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		checkPali(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			calc(i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//printf("Dp de %d, %d  =>  %d\n", i, j, dp[i][j]);
			if (dp[i][j] > 1) ans[dp[i][j]]++;
		}
	}

	for (int i = n; i >= 3; i--) {
		int x = ans[i];
		ans[i-1] += x;
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}