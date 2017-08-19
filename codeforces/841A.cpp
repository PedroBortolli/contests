#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <char, int> cont;
char s[10005];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	scanf(" %s", s);
	for (int i = 0; i < n; i++) {
		cont[s[i]]++;
		if (cont[s[i]] > k) {
			printf("NO\n");
			return 0;
		}
	}	

	printf("YES\n");
	return 0;
}