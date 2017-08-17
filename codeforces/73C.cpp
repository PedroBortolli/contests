#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, k, len, dp[111][111][29];
char s[111];
map <pair <char, char>, int> mp;

int go(int id, int left, int prev) {
	if (id == len) return 0;
	if (dp[id][left][prev-'a'] != -1) return dp[id][left][prev-'a'];
	int ans = -100000000;
	for (char i = 'a'; i <= 'z'; i++) {
		int cont = 0, add = mp[mp(prev,i)];
		if (i != s[id]) cont = 1;
		if (cont <= left) ans = max(ans, add+go(id+1, left-cont, i));
	}
	return dp[id][left][prev-'a'] = ans;
}

int main() {
	char x, y;
	int z;
	scanf(" %s", s);
	len = strlen(s);
	scanf("%d", &k);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %d", &x, &y, &z);
		mp[mp(x,y)] = z;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, k, 'z'+1));
	return 0;
}