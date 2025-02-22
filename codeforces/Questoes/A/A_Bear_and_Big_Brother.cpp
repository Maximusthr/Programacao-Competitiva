#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int a, b; cin >> a >> b;

    int year = 0;
    while(a <= b){
        year++;
        a *= 3;
        b *= 2;
    }
    cout << year << "\n";
}
