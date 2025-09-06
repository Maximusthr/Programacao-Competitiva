/**
* @file i.cpp
*
* Created on 2025-09-06 at 10:30:42
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX_V 1000100

int crivo[MAX_V];
int ingredientes[MAX_V]; // ingredientes[i] : numero de comidas que possuem o ingrediente i
int qtd_comidas;
int comidas[MAX_V];
int aux;

const int MOD = 1e9 + 7;

ll pw(ll a, ll b) {
    ll x = 1;
    while (b > 0) {
        if (b&1) {
            x = x*a%MOD;
        }
        a = a*a%MOD;
        b >>= 1;
    }
    return x%MOD;
}

void pie(int i, vector<int> &vec, int curr, int sig) {
    if (i == vec.size()) {
        aux += sig * ingredientes[curr];
        return;
    }

    pie(i + 1, vec, curr * vec[i], sig * -1);
    pie(i + 1, vec, curr, sig);
}

void build(int i, vector<int> &vec, int curr) {
    if (i == vec.size()) {
        ingredientes[curr]++;
        return;
    }
 
    build(i + 1, vec, curr * vec[i]);
    build(i + 1, vec, curr);
}

int main() { _

    crivo[0] = crivo[1] = 1;
    for (int i = 2; i < MAX_V; i++) {
        if (crivo[i]) continue;
        crivo[i] = i;
        for (int j = i*2; j < MAX_V; j += i)
            crivo[j] = i;
    }

    cin >> qtd_comidas;
    for (int i = 0; i < qtd_comidas; i++) {
        cin >> comidas[i];

        int c = comidas[i];

        vector<int> fat;
        set<int> s;
        while (c != 1) {
            s.insert(crivo[c]);
            c /= crivo[c];
        }
        for (int p : s)
            fat.pb(p);
 
        build(0, fat, 1);
    }

    int q, alergia;
    cin >> q;
    while (q--) {
        cin >> alergia;
        if (alergia == 1) {
            cout << pw(2, qtd_comidas) << endl;
            continue;
        }
        
        vector<int> fat;
        
        set<int> s;
        while (alergia > 1) {
            s.insert(crivo[alergia]);
            alergia /= crivo[alergia];
        }

        for (int x : s)
            fat.pb(x);

        aux = 0;
        
        pie(0, fat, 1, 1);

        cout << pw(2, aux) << endl;
    }

    
    return 0;
}