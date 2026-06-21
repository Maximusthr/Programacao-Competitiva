#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, c; 
    while(cin >> n >> m >> c && (n || m || c)){
        cout << ((n - 7) * (m - 7) + c)/2 << "\n";
    }
}
