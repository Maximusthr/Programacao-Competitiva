#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int a, b, c; cin >> a >> b >> c;

    int medium = min(max(a, b), max(b, c));

    cout << abs(medium - max(max(a, b), max(b, c))) + abs(medium - min(min(a, b), min(b, c))) << "\n";
}
