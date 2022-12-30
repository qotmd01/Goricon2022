#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]){
    registerValidation(argc, argv);
    string s1  = inf.readString("[A-Z]{1,10000}", "s1");
    string s2 = inf.readString("[A-Z]{1,10000}", "s2");
    int point = inf.readInt(0,100000 ,"point");
    inf.eoln();
    inf.readEof();
    return 0;
}