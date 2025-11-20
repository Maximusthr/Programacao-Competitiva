// (codigo refatorado)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n+1), b(n+1);
    // xor de todo mundo e vai tentando modificar até achar o melhor

    vector<int> bits_A(31), bits_B(31); // talvez?
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        for (int j = 0; j < 31; j++){
            int v = (1 << j);
            bool valor = (a[i] & (1 << j));
            if (a[i] & (1 << j)){
                bits_A[j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cin >> b[i];
        for (int j = 30; j >= 0; j--){
            if (b[i] & (1 << j)){
                bits_B[j]++;
            }
        }
    }

    auto add = [&](ll &A, ll &B, vector<int> tipo_a, vector<int> tipo_b) -> void {
        for (int i = 30; i >= 0; i--){
            if (tipo_a[i] % 2){
                A += (1 << i);
            }
            if (tipo_b[i] % 2){
                B += (1 << i);
            }
        }
    };

    auto change_bits = [&](vector<int> &A, vector<int> &B, int tipo, int elem_A, int elem_B) -> void {
        if (tipo == 1){
            for (int j = 30; j >= 0; j--){
                if (elem_A & (1 << j)){
                    A[j]--;
                    B[j]++;
                }
                if (elem_B & (1 << j)){
                    A[j]++;
                    B[j]--;
                }
            }
        }
        else {
            for (int j = 30; j >= 0; j--){
                if (elem_A & (1 << j)){
                    A[j]++;
                    B[j]--;
                }
                if (elem_B & (1 << j)){
                    A[j]--;
                    B[j]++;
                }
            }
        }
    };

    ll cur_A = 0, cur_B = 0;
    add(cur_A, cur_B, bits_A, bits_B);

    // par = mai
    // impar = ajirai
    for (int i = 1; i <= n; i++){
        if (i % 2){
            ll atual_a = 0, atual_b = 0;

            change_bits(bits_A, bits_B, 1, a[i], b[i]);
            add(atual_a, atual_b, bits_A, bits_B);

            if (atual_a > atual_b){
                cur_A = atual_a;
                cur_B = atual_b;
            }
            else {
                // voltamos atras
                change_bits(bits_A, bits_B, 2, a[i], b[i]);
            }
        }
        else {
            ll atual_a = 0, atual_b = 0;

            change_bits(bits_A, bits_B, 1, a[i], b[i]);
            add(atual_a, atual_b, bits_A, bits_B);

            if (atual_a < atual_b){
                cur_A = atual_a;
                cur_B = atual_b;
            }
            else {
                // voltamos atras
                change_bits(bits_A, bits_B, 2, a[i], b[i]);

            }
        }
    }

    if (cur_A > cur_B) cout << "Ajisai" << "\n";
    else if (cur_A < cur_B) cout << "Mai" << "\n";
    else cout << "Tie" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}