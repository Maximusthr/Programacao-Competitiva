#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int a, b; cin >> a >> b;

    cout << min(a, b) << " " << abs(a-b)/2 << "\n";

}
