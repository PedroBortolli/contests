#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <char, int> mp, val;
int main() {
	int n, v, cont = 1;
	char op;
	scanf("%d", &n);
	mp['^'] = -1;
	mp['&'] = -1;
	mp['|'] = -1;
	val['^'] = -1;
	val['&'] = -1;
	val['|'] = -1;
	for (int i = 0; i < n; i++) {
		scanf(" %c %d", &op, &v);
		if (mp[op] == -1) mp[op] = cont++;
		if (op == '&') {
			if (val[op] == -1) val[op] = v;
			else val[op] &= v;
		}
		else if (op == '^') {
			if (val[op] == -1) val[op] = v;
			else val[op] ^= v;
		}
		else {
			if (val[op] == -1) val[op] = v;
			else val[op] |= v;
		}
	}

	set <pair <char, int> > st;
	if (mp['|'] != -1) st.insert({mp['|'], '|'});
	if (mp['&'] != -1) st.insert({mp['&'], '&'});
	if (mp['^'] != -1) st.insert({mp['^'], '^'});

	vector <pair <char, int> > s;
	
	for (auto a : st) {
		s.push_back(make_pair(a.second, val[a.second]));
	}

	printf("%d\n", (int)s.size());
	for (auto a : s)
		printf("%c %d\n", a.first, a.second);

	return 0;
}