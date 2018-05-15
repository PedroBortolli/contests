#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5;
int p[N], w[N];

int find(int a) {
	return (p[a] == a) ? a : p[a] = find(p[a]);
}

void join(int a, int b) {
	if ((a = find(a)) == (b=find(b))) return;
	if (w[b] > w[a]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}

map <pii, int> used;

int main() {
	int n, k, cost;
	scanf("%d %d", &n, &k);

	if (k == 0) {
		if (n == 1) printf("0\n");
		else if (n <= 3) printf("-1\n");
		else {
			printf("%d\n", (n-1)+(n-1));
			cost = 1;
			for (int i = 2; i < n; i++) {
				printf("1 %d %d\n", i, cost++);
			}
			printf("2 %d %d\n", n, cost++);
			printf("1 %d %d\n", n, cost++);
			for (int i = 3; i <= n; i++) {
				printf("%d %d %d\n", i-1, i, cost++);
			}
		}
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		p[i] = i;
		w[i] = 1;
	}

	cost = 1000000;

	vector <pair <pii, int> > ans;

	for (int i = 2; i <= k+1; i++) {
		join(1, i);
		used[{1, i}] = 1;
		used[{i, 1}] = 1;
		ans.pb(make_pair(make_pair(1, i), cost++));
	}

	cost = 1;
	for (int i = 2; i <= n; i++) {
		if (used[{1, i}]) continue;
		if (w[find(1)] == n) break;
		used[{1, i}] = 1;
		used[{i, 1}] = 1;
		join(1, i);
		ans.pb(make_pair(make_pair(1, i), cost++));	 
	}

	for (int i = 1; i <= n; i++) {
		p[i] = i;
		w[i] = 1;
	}

	for (int i = 2; i <= k+1; i++) {
		join(1, i);
	}

	cost = 100000000;
	for (int i = 1; i <= n; i++) {
		if (i == 2) continue;
		if (used[{2, i}]) continue;
		if (w[find(2)] == n) break;
		used[{2, i}] = 1;
		used[{i, 2}] = 1;
		join(2, i);
		ans.pb(make_pair(make_pair(2, i), cost++));
	}

	printf("%d\n", (int)ans.size());
	for (auto a : ans)
		printf("%d %d %d\n", a.first.first, a.first.second, a.second);
	return 0;
}