#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1555];
int dp[27][1555];
int main() {
	int n, m, q;
	char c;
	scanf("%d", &n);
	scanf(" %s", s);

	for (int l = 0; l < 26; l++) {
		c = l+'a';
		for (int k = 1; k <= n; k++) {
			int j = 0, cur = 0, ans = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] != c) cur++;
				if (cur > k) {
					ans = max(ans, i-j);
					for (; j <= i; j++) {
						if (s[j] != c) {
							cur--;
							break;
						}
					}
					j++;
				}
			}
			ans = max(ans, n-j);
			dp[l][k] = ans;
		}
	}

	scanf("%d", &q);
	while (q--) {
		scanf("%d %c", &m, &c);
		printf("%d\n", dp[c-'a'][m]);
	}
	return 0;
}