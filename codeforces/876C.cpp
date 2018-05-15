#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


int count(string aux) {
	int sze = (int)aux.length(), ret = 0;
	for (int i = 0; i < sze; i++) {
		ret += (aux[i]-'0');
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	string str = "";
	set <int> s;
	for (int i = max(0, n-10000); i <= n; i++) {
		str = to_string(i);
		int x = count(str);
		if (x + i == n) {
			s.insert(i);
		}
	}

	printf("%d\n", (int)s.size());
	for (auto a : s)
		printf("%d\n", a);
	return 0;
}