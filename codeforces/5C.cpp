#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int dp[1000005], f[1000005];
char s[1000005];
int main() {
	scanf(" %s", s);
	int n = strlen(s);
	int l = 0, r = 0;
	stack <int> q;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') q.push(i);
		else {
			if (q.empty()) continue;
			else {
				int x = q.top();
				dp[x] = 1;
				dp[i] = 1;
				q.pop();
			}
		}
	}
	int cont = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i]) cont++;
		else {
			f[cont]++;
			cont = 0;
		}
	}
	f[cont]++;
	f[0] = 1;
	for (int i = n; i >= 0; i--) {
		if (f[i]) {
			printf("%d %d\n", i, f[i]);
			break;
		}
	}
	return 0;
}