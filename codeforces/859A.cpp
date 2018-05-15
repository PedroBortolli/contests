#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int k, x, mx = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		mx = max(mx, x);
	}

	printf("%d\n", max(0, mx-25));
	return 0;
}