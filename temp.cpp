#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define SIGN_1_EXTENTION 0b11111111111111111111000000000000 
#define SIGN_1_EXTENTION_J 0b1111111111110000000000000000000000


int main(void){
    int temp;
    unsigned long temp2;
    cin >> temp;
    temp = 0 - temp;
    temp2 = (temp ^0b11111111111111111111111111111111);
    temp2 += 1;
    cout << temp2 << "\n";
    return 0;
}

//3726903779