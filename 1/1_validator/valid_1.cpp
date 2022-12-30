#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    registerValidation(argc, argv);
    int n,m;
    n = inf.readInt(1, 1000, "n");
    inf.readEoln();
    for(int i = 0; i < n; i++){
        m = inf.readInt(1,100, "m");
        inf.readEoln();
        int K, D, A;
        for (int j = 0; j < m; j++)
        {
            K = inf.readInt(1, 50000000, "K");
            inf.readSpace();
            D = inf.readInt(1, 50000000, "D");
            inf.readSpace();
            A = inf.readInt(1, 50000000, "A");
            inf.readEoln();
        }
        int k,d,a;
        k = inf.readInt(0, 50, "k");
        inf.readSpace();
        d = inf.readInt(0, 50, "d");
        inf.readSpace();
        a = inf.readInt(0, 50, "a");
        inf.readEoln();
    }

    inf.readEof();
    
    return 0;
}