// Curso NOIC de Informática - Técnicas de Programação 03 - Somas de Prefixo
// Soma de intervalos em O(1)
// Escrito por Lúcio Figueiredo

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int v[maxn]; // vetor original

// vetor de soma de prefixos
// lembre-se de utilizar long long, pois as somas podem ultrapassar o limite do int
long long s[maxn];

int main(void)
{
	int n, q;
	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	// calculamos as somas de prefixo
	s[1] = v[1];
	for (int i = 2; i <= n; i++)
		s[i] = s[i-1] + 1ll*v[i];

	for (int i = 1; i <= q; i++)
	{
		int l, r; // query de soma [l, r]
		scanf("%d %d", &l, &r);

		// soma do intervalo [l, r]
		printf("%lld\n", s[r] - s[l-1]);
	}
}