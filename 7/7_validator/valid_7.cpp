#include "testlib.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
    registerValidation(argc, argv);
    int b,n,max_b = 0;
    b = inf.readInt(1, 500, "b");
    inf.readEoln();
    set<string> Lset;
    set<string> Hset;

    for(int i = 0; i < b; i++){
        string lbit;
        lbit = inf.readString("[01]{3,50}", "lbit");
        if (find(Lset.begin(), Lset.end(),lbit) != Lset.end())
        {
            return -1;
        }
        else Lset.insert(lbit);
        if(lbit.size() > max_b) max_b = lbit.size();
    }

    for (int i = 0; i < b; i++)
    {
        string hbit;
        hbit = inf.readString("[01]{3,50}", "hbit");
        if((find(Lset.begin(), Lset.end(),hbit) != Lset.end()) && (find(Hset.begin(), Hset.end(), hbit) != Hset.end())){
            return -1;
        }
        else Hset.insert(hbit);
        if(hbit.size() > max_b) max_b = hbit.size();
    }

    n = inf.readInt(1, 1000, "n");
    inf.readEoln();

    for (int i = 0; i < n; i++)
    {
        string nbit;
        nbit = inf.readString("[01]{3,250}", "nbit");
        if(nbit.size() < max_b) return -1;
    }
    inf.readEof();
    return 0;

}