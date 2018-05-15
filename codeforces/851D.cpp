#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[500005], nop[1000005];
ll n, x, y;

int main() {
	scanf("%lld %lld %lld", &n, &x, &y);	
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	
	for (int i = 2; i <= 1000000; i++) {
		for (int j = i+i; j <= 1000000; j += i)
			nop[j] = 1;
	}
	vector <int> pr;
	for (int i = 2; i <= 1000000; i++)
		if (!nop[i]) pr.pb(i);
	printf("%d\n", (int)pr.size());
	return 0;
}