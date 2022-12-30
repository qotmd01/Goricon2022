#include "testlib.h"

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int n = inf.readInt(1,200, "n");
    inf.readSpace();
    int m = inf.readInt(1,200, "m");
    inf.readSpace();
    int k = inf.readInt(0,30,"k");
    inf.readEoln();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int mapp = inf.readInt(0,2,"map");
            if( j == m-1) inf.readEoln();
            else inf.readSpace();
            
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; i++)
        {
            int pattern = inf.readInt(0,1,"pattern");
            if( j == 4) inf.readEoln();
            else inf.readSpace();
        }
        
    }
    inf.read

    inf.readEof();

    return 0;
    
}