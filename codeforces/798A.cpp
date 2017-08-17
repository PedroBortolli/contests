#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[155];
int main() {
	scanf(" %s", s);
	int n = strlen(s);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			char c = 'a'+j;
			if (c == s[i]) continue;
			char hold = s[i];
			s[i] = c;
			int last = n-1;
			int ok = 1;
			for (int k = 0; k < n/2; k++) {
				if (s[k] != s[last]) ok = 0;
				last--;
			}
			if (ok) {
				printf("YES\n");
				return 0;
			}
			s[i] = hold;
		}
	}

	printf("NO\n");
	return 0;
}