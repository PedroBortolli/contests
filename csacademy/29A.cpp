#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <int> s;
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		s.insert(x);
	}

	for (int i = 1; i <= 10000; i++) {
		if (s.find(i) == s.end()) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}