#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int l[5], s[5], r[5], p[5];
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &l[i], &s[i], &r[i], &p[i]);
	}

	for (int i = 0; i < 4; i++) {
		if (p[i]) {
			if (l[i] or r[i] or s[i]) {
				printf("YES\n");
				return 0;
			}
		}
	}

	if (p[0] && s[2]) {
		printf("YES\n");
		return 0;
	}

	if (p[1] && s[3]) {
		printf("YES\n");
		return 0;
	}

	if (p[2] && s[0]) {
		printf("YES\n");
		return 0;
	}

	if (p[3] && s[1]) {
		printf("YES\n");
		return 0;
	}

	int ok = 0;
	if (r[0] && p[1]) ok = 1;
	if (r[1] && p[2]) ok = 1;
	if (r[2] && p[3]) ok = 1;
	if (r[3] && p[0]) ok = 1;
	if (l[0] && p[3]) ok = 1;
	if (l[1] && p[0]) ok = 1;
	if (l[2] && p[1]) ok = 1;
	if (l[3] && p[2]) ok = 1;

	if (ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}