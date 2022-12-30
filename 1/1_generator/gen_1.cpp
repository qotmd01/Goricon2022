#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

struct mission
{
    int K,D,A;
};


struct TC{
    int m, k, d, a; 
    vector<mission> missions;
};

TC make_TC(int max_m, int max_money, int max_kda){
    TC res;
    res.m = rnd.next(1, max_m);
    for (int i = 0; i < res.m; i++)
    {
        mission cur;
        cur.K = rnd.next(1000, max_money);
        cur.D = rnd.next(1000, max_money);
        cur.A = rnd.next(1000, max_money);
        res.missions.push_back(cur);
    }
    res.k = rnd.next(0,max_kda);
    res.d = rnd.next(0,max_kda);
    res.a = rnd.next(0,max_kda);
    
    return res;
}

int main(int argc, char *argv[]){
    registerGen(argc, argv,1);
    int max_n = atoi(argv[1]);
    int max_m = atoi(argv[2]);
    int max_money = atoi(argv[3]);
    int max_kda = atoi(argv[4]);

    int n = rnd.next(1,max_n);
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        TC ret = make_TC(max_m, max_money, max_kda);
        cout << ret.m << "\n";
        for (int j = 0; j < ret.m; j++)
        {
            cout << ret.missions[j].K << " " << ret.missions[j].D << " " << ret.missions[j].A << "\n";
        }
        cout << ret.k << " " << ret.d << " " << ret.a << "\n";
        
    }
    
    return 0;
}