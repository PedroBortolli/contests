#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[99];
int main() {
	int n, ok = 1, cont = 0;
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n-1; i++) {
		if (s[i] == '1' && s[i+1] == '0') s[i+1] = '!';
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == '!') {
			printf("%d", cont);
			cont = 0;
		}
		else if (s[i] == '1') cont++;
		else {
			printf("0");
			cont = 0;
		}
	}
	printf("%d", cont);
	return 0;
}