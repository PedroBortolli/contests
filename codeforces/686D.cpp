#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 3e5+5;
vector <int> v[N];
int sze[N], n, q, x, ans[N], nn = 1;
pii t[4*N];
pair <int, pii> qry[N];
vector <pii> vc;
vector <int> ids[N];
map <int, int> mp;

void update(int id, int x) {
	id += nn;
	t[id] = mp(x, mp[id-nn]);
	id /= 2;
	while (id > 0) {
		t[id] = max(t[2*id], t[2*id+1]);
		id /= 2;
	}
}

int query(int l, int r) {
	l += nn;
	r += nn+1;
	pii ans = mp(-10000000, 0);
	while (l < r) {
		if (l%2) ans = max(ans, t[l++]);
		if (r%2) ans = max(ans, t[--r]);
		l /= 2;
		r /= 2;
	}
	return ans.second;
}

int dfs(int x) {
	int cont = 1;
	for (auto a : v[x]) {
		mp[nn] = x;
		ids[x].pb(nn++);
		cont += dfs(a);
	}
	mp[nn] = x;
	ids[x].pb(nn++);
	return sze[x] = cont;
}

int main() {
	memset(t, -10000000, sizeof(t));
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		v[x].pb(i);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (auto a : v[i]) {
			mx = max(mx, sze[a]);
		}
		vc.pb(mp(mx, i));
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < q; i++) {
		scanf("%d", &x);
		qry[i] = mp(sze[x], mp(x, i));
	}

	sort(qry, qry+q);
	int k = 0;

	for (int i = 0; i < q; i++) {
		int sz = qry[i].first;
		int id = qry[i].second.first;
		int qq = qry[i].second.second;
		for (; k < vc.size(); k++) {
			if (vc[k].first > sz/2) break;
			for (auto a : ids[vc[k].second]) {
				//printf("Update pos %d  com %d\n", a, sze[vc[k].second]);
				update(a, sze[vc[k].second]);
			}
		}
		/*for (int i = 1; i <= nn; i++)
			printf("%d ", query(i,i));
		printf("\n\n");*/
		int start = ids[id][0];
		int end = ids[id][ids[id].size()-1];
		//printf("start = %d    end = %d\n", start, end);
		ans[qq] = query(start, end);
		//printf("	%d\n", ans[qq]);
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}