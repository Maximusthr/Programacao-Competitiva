#include <bits/stdc++.h>

using namespace std;

int fatorial(int x){
    if (x == 0) return 1;
    if (x == 1) return x;
    return x*fatorial(x-1);
}

int main(){
    int x; cin >> x;
    cout << fatorial(x) << '\n';
}