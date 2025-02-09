#include <iostream>

using namespace std;


bool eh_primo(int x){
    int i, count = 0;
    for (i = 2; i <= x; i++){
        if ( x % i == 0 && i != x) {
            count++;
            // return true;
        }  
    }
    // return false;
    if (count != 0 || x == 1) return false;
    else return true;
}       

int main(){
    int x;
    cin >> x;

    if(eh_primo(x)){
        cout << "S" << "\n";
    } else {
        cout << "N" << "\n";
    }
}
