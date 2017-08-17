#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[100005];
int v[100005];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", s);
		int n = strlen(s);
		int inc;
		for (int i = 0; i < n; i++) {
			if (s[i] == '=') continue;
			if (s[i] == '>') {
				inc = 1;
				break;
			}
			else {
				inc = 0;
				break;
			}
		}
		int cur = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '=') continue;
			if (s[i] == '>') {
				if (inc) cur++;
				else {
					ans = max(ans, cur);
					cur = 1;
					inc = 1;
				}
			}
			else {
				if (!inc) cur++;
				else {
					ans = max(ans, cur);
					cur = 1;
					inc = 0;
				}
			}
		}

		printf("%d\n", max(ans,cur)+1);
	}	

	return 0;
}