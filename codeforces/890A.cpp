#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[11], ok = 0;
void go(int id, int t1, int t2, int s1, int s2) {
	if (ok) return;
	if (id == 6) {
		if (s1 == s2) {
			ok = 1;
			return;
		}
	}
	if (t1 < 3) go(id+1, t1+1, t2, s1+v[id], s2);
	if (t2 < 3) go(id+1, t1, t2+1, s1, s2+v[id]);
}

int main() {
	for (int i = 0; i < 6; i++)
		scanf("%d", &v[i]);
	go(0, 0, 0, 0, 0);
	if (ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}