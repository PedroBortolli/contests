#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


int ans = 1;

void check(int x) {
	int a = 1, b = 1;
	for (int i = 1; i <= 12; i++) {
		a *= 2;
		b *= 2;
		if ((a-1)*(b/2) == x) {
			ans = max(ans, x);
			break;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i*i <= n; i++) {
		if (n%i) continue;
		check(i);
		check(n/i);
	}

	printf("%d\n", ans);
	return 0;
}