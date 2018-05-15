#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[200005];
set <int> s;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		s.insert(v[i]);
	}

	for (int i = n-1; i >= 0; i--) {
		if ((int)s.size() == 1) {
			printf("%d\n", *s.begin());
			return 0;
		}
		if (s.find(v[i]) != s.end()) s.erase(s.find(v[i]));
	}

	return 0;
}