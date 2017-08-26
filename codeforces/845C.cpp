#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

multiset <pii> s;
int main() {
	int n, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l, &r);
		s.insert(mp(l,r));
	}

	int cont = 0, end1, end2;
	for (auto a : s) {
		cont++;
		if (cont == 1) {
			end1 = a.second;
		}
		else if (cont == 2) {
			end2 = a.second;
		}
		else {
			if (end1 < a.first) end1 = a.second;
			else if (end2 < a.first) end2 = a.second;
			else {
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("YES\n");
	return 0;
}