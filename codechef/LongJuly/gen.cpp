#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	srand(time(NULL));
	printf("100\n");
	for (int i = 0; i < 100; i++) {
		int x = rand()%10000+1;
		int y = rand()%10000+1;
		x++;
		y++;
		printf("%d %d\n", x, y);
	}
	return 0;
}