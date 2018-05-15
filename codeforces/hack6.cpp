#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, a, b, c;
int main() {
	scanf("%d %d %d %d", &n, &a, &b, &c);	
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	if (c < a && c < b) {
		printf("%d\n", min(a,b) + c*(n-2));
		return 0;
	}
	else {
		printf("%d\n", min(a,b)*(n-1));
		return 0;
	}
	return 0;
}