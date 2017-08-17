#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n;
	scanf("%d", &n);
	int a = 0, b = 1, cont = 0;
	for (int i = 0; i < n; i++) {
		if (!a) {
			printf("a");
			cont++;
		}
		else {
			printf("b");
			cont++;
		}
		if (cont == 2) {
			if (a == 0) {
				a = 1;
				b = 0;
			}
			else {
				a = 0;
				b = 1;
			}
			cont = 0;
		}
	}	

	printf("\n");
	return 0;
}