#include <bits/stdc++.h>

using namespace std;

int main(){
    // calcula a parte inteira da raiz de n
    int n, sq;
    cin >> n;
    for(sq = 1; sq*sq <= n; ++sq);
    --sq;
    cout << sq << "\n";
}