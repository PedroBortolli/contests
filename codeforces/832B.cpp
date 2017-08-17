#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

bool mp[111];
char s[100005];
char b[100005];
int main() {
	scanf(" %s", s);
	int n = strlen(s), q;
	for (int k = 0; k < n; k++) {
		mp[s[k]] = true;
	}

	scanf(" %s", s);
	n = strlen(s);
	scanf("%d", &q);

	while (q--) {
		scanf(" %s", b);
		int len = strlen(b);
		int j = 0;
		int i = 0;
		int ok = 1;
		
		for (i = 0; i < n && j < len; i++) {
			//printf("Comparando %c com %c\n", s[i], b[j]);
			if (s[i] >= 'a' && s[i] <= 'z' && s[i] != b[j]) {
				ok = 0;
				break;
			}
			else if (s[i] >= 'a' && s[i] <= 'z' && s[i] == b[j]) {
				j++;
				continue;
			}
			//printf("	entrando\n");
			if (s[i] == '?') {
				if (mp[b[j]] == false) {
					ok = 0;
					break;
				}
				j++;
			}
			else if (s[i] == '*') {
				for (; j < len; j++) {
					if (mp[b[j]] == true or len-j == n-i-1) break;
				}
			}
		}
		if (i < n) {
			if (s[i] == '*') i++;
		}
		if (ok && i == n && j == len) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}