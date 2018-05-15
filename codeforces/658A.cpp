#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int p[1005], t[1005];
int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	int l = 0, r = 0, ac = 0;
	for (int i = 0; i < n; i++) {
		ac += t[i];
		l += max(0, p[i]-c*ac);
	}
	ac = 0;
	for (int i = n-1; i >= 0; i--) {
		ac += t[i];
		r += max(0, p[i]-c*ac);
	}

	if (l > r) printf("Limak\n");
	else if (l < r) printf("Radewoosh\n");
	else printf("Tie\n");
	return 0;
}