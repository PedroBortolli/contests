#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int f[1000005];
int main() {
	int n, m, k, x, y;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		f[x] = 1;
	}

	int bone = 1;
	if (f[bone]) {
		printf("%d\n", bone);
		return 0;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		if (bone == x) bone = y;
		else if (bone == y) bone = x;
		if (f[bone]) break;
	}

	printf("%d\n", bone);

	return 0;
}