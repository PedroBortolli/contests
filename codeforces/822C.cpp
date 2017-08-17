#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 2e5+10;
const ll inf = 2111111111111;
int n, x;
ll t[2*N], t2[2*N];
set <pair <ll, pii> > dur[200060];

void build() {
	for (int i = N-1; i > 0; i--)
		t[i] = min(t[i*2], t[i*2+1]);
}

void update(int id, ll x) {
	id += N;
	t[id] = x;
	id /= 2;
	for (int i = id; i >= 1; i /= 2)
		t[i] = min(t[i*2], t[i*2+1]);
}

ll query(int l, int r) {
	ll ans = inf;
	l += N, r += N+1;
	while (l < r) {
		if (l%2 != 0) ans = min(ans, t[l++]);
		if (r%2 != 0) ans = min(ans, t[--r]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

void build2() {
	for (int i = N-1; i > 0; i--)
		t2[i] = min(t2[i*2], t2[i*2+1]);
}

void update2(int id, ll x) {
	id += N;
	t2[id] = x;
	id /= 2;
	for (int i = id; i >= 1; i /= 2)
		t2[i] = min(t2[i*2], t2[i*2+1]);
}

ll query2(int l, int r) {
	ll ans = inf;
	l += N, r += N+1;
	while (l < r) {
		if (l%2 != 0) ans = min(ans, t2[l++]);
		if (r%2 != 0) ans = min(ans, t2[--r]);
		l /= 2;
		r /= 2;
	}
	return ans;
}


int main() {
	int l, r;
	ll c, q;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %lld", &l, &r, &c);
		r--;
		l--;
		dur[r-l+1].insert(mp(c, mp(l, r)));
	}

	for (int i = 0; i <= 200002; i++) {
		t[i+N] = inf;
		t2[i+N] = inf;
	}

	build();
	build2();

	ll anss = inf;

	for (int i = 1; i <= x-1; i++) {
		for (auto a : dur[x-i]) {
			c = a.first;
			l = a.second.first;
			r = a.second.second;
			//printf("Dando update na pos %d da seg da esq com %lld\n", l, c);
			if (c < t[l+N]) update(l, c);
			//printf("Dando update na pos %d da seg da dir com %lld\n", r, c);
			if (c < t2[r+N]) update2(r, c);
		}

		
		/*
		for (int i = 0; i <= 4; i++) {
			printf("%lld ", t[i+N]);
		}
		printf("\n\n");

		for (int i = 0; i <= 4; i++) {
			printf("%lld ", t2[i+N]);
		}
		printf("\n\n");
		*/
		

		for (auto a : dur[i]) {
			c = a.first;
			l = a.second.first;
			r = a.second.second;
			//printf("\nAnalisando l = %d,   r = %d,   c = %lld\n", l, r, c);
			if (l-1 >= 0) {
				q = query2(0, l-1);
				//printf("	Potencial pegando esqerda => %lld\n", q);
				anss = min(anss, q+c);
			}
			if (r+1 <= 200002) {
				q = query(r+1, 200002);
				//printf("	Potencial pegando direita => %lld\n", q);
				anss = min(anss, q+c);
			}
		}
		for (auto a : dur[x-i]) {
			l = a.second.first;
			r = a.second.second;
			update(l, inf);
			update2(r, inf);
		}
	}

	if (anss == inf) anss = -1ll;
	printf("%lld\n", anss);
	return 0;
}