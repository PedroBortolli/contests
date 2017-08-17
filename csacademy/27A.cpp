#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int a, b, n, x;
	scanf("%d %d %d", &a, &b, &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (a > b && a >= x) {
			a -= x;
		}
		else if (a == b) {
			if (a >= x) {
				a -= x;
			}
			else if (b >= x) {
				b -= x;
			}
			else ans++;
		}
		else if (b > a && b >= x) {
			b -= x;
		}
		else ans++;
	}	

	printf("%d\n", ans);
	return 0;
}