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
	scanf(" %s", s);
	int n = strlen(s), ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'Q') {
			for (int j = i+1; j < n; j++) {
				if (s[j] == 'A') {
					for (int k = j+1; k < n; k++) {
						if (s[k] == 'Q') ans++;
					}
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}