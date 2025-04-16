#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int i = 0, j = 0, k = 0;

    vector<int> c(n+m);

    while (i < a.size() || j < b.size()){
        if (j == b.size() || i < a.size() && a[i] < b[j]){
            c[k] = a[i];
            i++, k++;
        }
        else {
            c[k] = b[j];
            j++, k++;
        }
    }

    for (int i = 0; i < n+m; i++){
        cout << c[i] << " ";
    }

    cout << "\n";
}
