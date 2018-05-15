#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[105];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+n);
	int tot = 0;
	for (int i = 0; i < k; i++) {
		tot += v[i];
	}

	int x = tot%100;
	if (x > 0) x = 1;
	printf("%d\n", tot/100 + x);
	return 0;
}