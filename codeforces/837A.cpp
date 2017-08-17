#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[3333];
int main() {
	int n;
	scanf("%d", &n);
	scanf(" %[^\n]", s);
	int j = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ' or i == n-1) {
			if (i == n-1) i++;
			int cont = 0;
			for (; j < i; j++) {
				if (s[j] >= 'A' && s[j] <= 'Z') cont++;
			}
			ans = max(ans, cont);
			j = i+1;
		}
	}

	printf("%d\n", ans);
	return 0;
}