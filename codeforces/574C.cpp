#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];

int check(int x) {
	int ok = 1;
	while (x > 1) {
		if (x%2 == 0) x /= 2;
		else break;
	}
	while (x > 1) {
		if (x%3 == 0) x /= 3;
		else {
			ok = 0;
			break;
		}
	}
	return ok;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i < n; i++) {
		int g = __gcd(v[i], v[i-1]);
		int x = v[i]/g;
		int y = v[i-1]/g;
		int ok1 = check(x);
		int ok2 = check(y);
		if (!ok1 or !ok2) {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");
	return 0;
}