#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	if (m > n) {
		printf("-1\n");
		return 0;
	}

	int ans = n/2 + n%2;
	while (ans%m != 0) {
		ans++;
	}

	printf("%d\n", ans);
	return 0;
}