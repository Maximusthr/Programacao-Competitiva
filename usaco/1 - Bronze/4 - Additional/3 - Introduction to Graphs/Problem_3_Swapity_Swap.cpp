#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    
    vector<int> arr(n+1);
    iota(arr.begin()+1, arr.end(), 1);

    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;

    vector<int> copy = arr;

    int ciclos = 0;
    while (true){
        reverse(copy.begin()+a, copy.end()+b-n);
        reverse(copy.begin()+c, copy.end()+d-n);
        ciclos++;
        if (copy == arr) break;
    }

    int qtd = k % ciclos;
    while(qtd--){
        reverse(arr.begin()+a, arr.end()+b-n);
        reverse(arr.begin()+c, arr.end()+d-n);
    }

    for (int i = 1; i <= n; i++){
        cout << arr[i] << "\n";
    }
}
