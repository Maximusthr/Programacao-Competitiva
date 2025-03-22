
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    // fib interativo
    int a = 0, b = 1;
    for (int i = 2; i < 10; i++){
        int c = a + b;
        a = b;
        b = c;
    }
}
