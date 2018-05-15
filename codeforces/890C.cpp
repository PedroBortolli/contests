#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

multiset <int> s;
int main() {
	int n, tme = 1, x;
	scanf("%d", &n);
	s.insert(0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (s.find(x) != s.end()) {
			s.erase(s.find(x));
		}
		s.insert(tme);
		tme++;
	}	

	printf("%d\n", (int)s.size());
	return 0;
}