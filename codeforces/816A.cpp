#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[11];
int main() {
	int idk = 1198;
	while (idk--) {
		scanf(" %s", s);
		int h1 = s[0]-'0';
		int h2 = s[1]-'0';
		int m1 = s[3]-'0';
		int m2 = s[4]-'0';

		int ans = 0;
		while (1) {
			if (h1 == m2 && h2 == m1) break;
			ans++;
			m2++;
			if (m2 == 10) {
				m2 = 0;
				m1++;
			}
			if (m1 == 6) {
				m1 = 0;
				m2 = 0;
				h2++;
			}
			if (h2 == 10) {
				h2 = 0;
				h1++;
			}
			if (h1 == 2 && h2 == 4) {
				break;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}