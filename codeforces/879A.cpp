#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, s, d, day = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &d);
		if (i == 0) day = s;
		else {
			while (s <= day) {
				s += d;
			}
			day = s;
		}
	}

	printf("%d\n", day);
	return 0;
}