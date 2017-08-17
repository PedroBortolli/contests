#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	ll aux = n/k;
	if (aux%2 == 0) printf("NO\n");
	else printf("YES\n");
	return 0;
}