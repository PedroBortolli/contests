#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[111];
int main() {
	scanf(" %s", s);	
	int n = strlen(s);

	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		if (s[i] == 'V' && s[i+1] == 'K') ans++;
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == 'V') s[i] = 'K';
		else if (s[i] == 'K') s[i] = 'V';
		int cur = 0;
		for (int j = 0; j < n-1; j++) {
			if (s[j] == 'V' && s[j+1] == 'K') cur++;
		}
		ans = max(ans, cur);
		if (s[i] == 'K') s[i] = 'V';
		else if (s[i] == 'V') s[i] = 'K';
	}

	printf("%d\n", ans);
	return 0;
}