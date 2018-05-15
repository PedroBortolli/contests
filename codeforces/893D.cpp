#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int a[100005];
int main() {
	int n, d, tot = 0, ans = 0, ok = 1;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			if (tot < 0) {
				ans++;
				tot = 0;
			}
		}
		tot += a[i];
		if (tot > d) ok = 0;
	}

	if (ok) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}