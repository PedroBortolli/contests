#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

#define int long long

char v[505][505];
int n, m, k, last[505], start[505], first[505], cnt[505], nxt[505][505], dp[505][505], prv[505][505];

int go(int id, int left) {
	if (id >= n) return 0;
	if (dp[id][left] != -1) return dp[id][left];
	if (!cnt[id]) return go(id+1, left);
	int skip = 0, ans = last[id]-start[id]+1 + go(id+1, left);
	for (int i = 0; i < last[id]; i++) {
		if (v[id][i] == '1' && skip+1 <= left) {
			skip++;
			ans = min(ans, last[id]-nxt[id][i]+1 + go(id+1, left-skip));
		}
	}
	skip = 0;
	for (int i = m-1; i > start[id]; i--) {
		if (v[id][i] == '1' && skip+1 <= left) {
			skip++;
			ans = min(ans, prv[id][i]-start[id]+1 + go(id+1, left-skip));
		}
	}
	if (cnt[id] <= left) ans = min(ans, go(id+1, left-cnt[id]));
	return dp[id][left] = ans;
}

main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	memset(start, -1, sizeof(start));
	for (int i = 0; i < n; i++) {
		int cont = 0;
		for (int j = 0; j < m; j++) {
			scanf(" %c", &v[i][j]);
			if (v[i][j] == '1') {
				if (start[i] == -1) start[i] = j; 
				cont++;
			}
		}
		cnt[i] = cont;
	}

	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >= 0; j--) {
			if (v[i][j] == '1') {
				last[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '1') {
				for (int l = j+1; l < m; l++) {
					if (v[i][l] == '1') {
						nxt[i][j] = l;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >= 0; j--) {
			if (v[i][j] == '1') {
				for (int l = j-1; l >= 0; l--) {
					if (v[i][l] == '1') {
						prv[i][j] = l;
						break;
					}
				}
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0,k));
	return 0;
}