#include <bits/stdc++.h>

using namespace std;

int main(){
    double n, m, a; cin >> n >> m >> a;
    
    cout << fixed << setprecision(0) << ceil(m/a) * ceil(n/a) << "\n";
}
