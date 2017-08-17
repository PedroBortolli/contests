#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


const int N = 1e6+5;
int sze = 0, root = 1;
char s[N];

struct node {
	int to[26];
	int freq;
	int end;
};

node trie[N];

int insert(char s[], int p = 0, int &nd = root) {
	if (sze == 0) nd = 0;
	if (nd == 0) nd = ++sze;
	trie[nd].freq++;
	if (s[p] == 0) {
		trie[nd].end++;
		return 1;
	}
	insert(s, p+1, trie[nd].to[s[p]-'a']);
}

int countpref(char s[], int p = 0, int nd = 1) {
	if (nd == 0) return 0;
	if (s[p] == 0) return trie[nd].freq;
	countpref(s, p+1, trie[nd].to[s[p]-'a']);
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	while (n--) {
		scanf(" %s", s);
		root = insert(s);
	}
	while (q--) {
		scanf(" %s", s);
		printf("%d\n", countpref(s));
	}
	return 0;
}
