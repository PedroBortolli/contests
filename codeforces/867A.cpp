#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[105];
int main() {
	int n;
	scanf("%d", &n);
	scanf(" %s", s);

	int f = 0, ss = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) continue;
		else {
			if (s[i] == 'F') f++;
			else ss++;
		}
	}

	if (f > ss) printf("YES\n");
	else printf("NO\n");
	return 0;
}