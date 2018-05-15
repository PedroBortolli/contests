#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int x[2005], y[2005], mp[2000005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		mp[x[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &y[i]);
		mp[y[i]] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int z = x[i]^y[j];
			if (z <= 2000000 && mp[z]) ans++; 
		}
	}
	
	if (ans%2 == 0) printf("Karen\n");
	else printf("Koyomi\n");
	return 0;
}