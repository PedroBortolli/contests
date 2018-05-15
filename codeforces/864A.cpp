#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <int> s;
map <int, int> mp;
int main() {
	int x, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		s.insert(x);
		mp[x]++;
	}

	int b = 0, c = 0;
	if ((int)s.size() == 2) {
		int cont = 0;
		for (auto a : s) {
			if (cont == 0) b = mp[a];
			else c = mp[a];
			cont++;
		}
		if (b == c) {
			printf("YES\n");
			for (auto a : s)
				printf("%d ", a);
			printf("\n");
		}
		else printf("NO\n");
		return 0;
	}

	printf("NO\n");
	return 0;
}