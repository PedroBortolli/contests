#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if ((by-ay)*(cx-ax) == (bx-ax)*(cy-ay)) printf("No\n");
	else {
		if ((ax-bx)*(ax-bx) + (ay-by)*(ay-by) == (bx-cx)*(bx-cx) + (by-cy)*(by-cy))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}