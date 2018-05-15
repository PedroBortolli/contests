#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, k, t;
	scanf("%d %d %d", &n, &k, &t);
	if (t <= k) printf("%d\n", t);
	else if (t > k && t <= n) printf("%d\n", k);
	else printf("%d\n", k-(t-n));	
	return 0;
}