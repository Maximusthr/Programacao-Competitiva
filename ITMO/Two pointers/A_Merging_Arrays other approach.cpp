#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> a(n+1);
    vector<int> b(m+1);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    a[n] = INF;
    b[m] = INF;

    int i = 0, j = 0, k = 0;

    vector<int> c(n+m);

    while (i < a.size()-1 || j < b.size()-1){
        if (a[i] < b[j]){
            c[k] = a[i];
            i++, k++;
        }
        else {
            c[k] = b[j];
            j++, k++;
        }
    }

    for (int i = 0; i < n+m; i++) cout << c[i] << " ";

    cout << "\n";
}
