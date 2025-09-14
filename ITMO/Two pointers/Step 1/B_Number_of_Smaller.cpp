#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> c(m);

    int i = 0, j = 0, k = 0;
    int sum = 0;

    while(i < n || j < m){
        if (i < n && b[j] > a[i]){
           sum++;
           i++; 
        }
        else {
            if (j == m) break;
            c[k] = sum;
            k++;
            j++;
        }
    }

    for (int i = 0; i < m; i++) cout << c[i] << " ";

    cout << "\n";
}
