#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <pii> co, di;
pii coin[100005], diam[100005];
int main() {
	int n, c, d, b, p, bestc = -1, bestd = -1;
	char ch;
	scanf("%d %d %d", &n, &c, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %c", &b, &p, &ch);
		if (ch == 'C') {
			co.pb(mp(p, b));
			if (p <= c) bestc = max(bestc, b);
		}
		else {
			di.pb(mp(p, b));
			if (p <= d) bestd = max(bestd, b);
		}
	}

	sort(co.begin(), co.end());
	sort(di.begin(), di.end());

	int best = -1, id1 = -1, id2 = -1, best2 = -1, prev = 1;
	for (int a = 0; a < co.size(); a++) {
		int price = co[a].first;
		int bea = co[a].second;
		for (int i = prev; i <= price-1; i++)
			coin[i] = mp(id1, id2);
		prev = price;
		if (bea >= best) {
			best2 = best;
			id2 = id1;
			id1 = a;
			best = bea;
		}
		else if (bea >= best2) {
			best2 = bea;
			id2 = a;
		}
	}

	for (int i = prev; i <= 100000; i++)
		coin[i] = mp(id1, id2);

	best = -1, id1 = -1, id2 = -1, best2 = -1, prev = 1;
	for (int a = 0; a < di.size(); a++) {
		int price = di[a].first;
		int bea = di[a].second;
		for (int i = prev; i <= price-1; i++)
			diam[i] = mp(id1, id2);
		prev = price;
		if (bea >= best) {
			best2 = best;
			id2 = id1;
			id1 = a;
			best = bea;
		}
		else if (bea >= best2) {
			best2 = bea;
			id2 = a;
		}
	}

	for (int i = prev; i <= 100000; i++)
		diam[i] = mp(id1, id2);

	int ans = 0;
	for (int a = 0; a < co.size(); a++) {
		int ava = c-co[a].first;
		int from = 0;
		if (ava <= 0) continue;
		if (coin[ava].first == -1) continue;
		if (coin[ava].first == a) {
			if (coin[ava].second == -1) continue;
			else from = coin[ava].second;
		}
		else from = coin[ava].first;
		//printf("Atualizando ans = %d     para     ", ans);
		ans = max(ans, co[a].second+co[from].second);
		//printf("%d\n", ans);
	}

	for (int a = 0; a < di.size(); a++) {
		int ava = d-di[a].first;
		//printf("\nStill available = %d\n", ava);
		int from = 0;
		if (ava <= 0) continue;
		if (diam[ava].first == -1) continue;
		if (diam[ava].first == a) {
			if (diam[ava].second == -1) continue;
			else from = diam[ava].second;
		}
		else from = diam[ava].first;
		//printf("Pegando ids %d e %d           -  Atualizando ans = %d     para     ", a, from, ans);
		ans = max(ans, di[a].second+di[from].second);
		//printf("%d\n", ans);
	}

	if (bestc != -1 and bestd != -1)
		ans = max(ans, bestc+bestd);

	printf("%d\n", ans);
	return 0;
}