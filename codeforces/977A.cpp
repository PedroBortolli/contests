#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {	
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		if (n%10 == 0) n /= 10;
		else n--;
	}
	printf("%d\n", n);
	return 0;
}