#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[222];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2*n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+2*n);

	if (v[n] > v[n-1]) printf("YES\n");
	else printf("NO\n");

	return 0;
}