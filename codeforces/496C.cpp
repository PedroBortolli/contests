#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[105][105];
set <int> k;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", s[i]);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		char prev = s[0][i];
		int ok = 1;
		for (int j = 1; j < n; j++) {
			if (s[j][i] < prev && k.find(j) == k.end()) ok = 0;
			prev = s[j][i];
		}
		if (!ok) ans++;
		else {
			char prev = s[0][i];
			for (int j = 1; j < n; j++) {
				if (s[j][i] > prev) k.insert(j);
				prev = s[j][i];
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}