#include <iostream>
#include <vector>
#include "testlib.h"
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int maxbbit = 0;

struct TC{
    int B, N;
    set<string> Lbit;
    set<string> Hbit;
    vector<string> Nbit;
};

TC make_tc(int max_b, int max_n, int max_lhbit, int max_nbit){
    TC cur;
    cur.B = max_b;   // B 
    cur.N = max_n;  //  N

    while (cur.Lbit.size() < cur.B)
    {
        int cur_len = max_lhbit;
        string Lbit = rnd.next("[01]{%d}",cur_len);
        cur.Lbit.insert(Lbit);
        if (cur_len > maxbbit) maxbbit = cur_len;
    }

    while (cur.Hbit.size() < cur.B)
    {
        int cur_len = max_lhbit;
        string Hbit = rnd.next("[01]{%d}",cur_len);
        if (find(cur.Lbit.begin(), cur.Lbit.end(), Hbit) == cur.Lbit.end())
        {
            cur.Hbit.insert(Hbit);
            if(cur_len > maxbbit) maxbbit = cur_len;
        }
        
    }
    

    for (int i = 0; i < cur.N; ++i) {
        int cur_len = max_nbit;
        cur.Nbit.push_back(rnd.next("[01]{%d}", cur_len));
    }

    return cur;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int max_b = atoi(argv[1]);
    int max_n = atoi(argv[2]);
    int max_lhbit = atoi(argv[3]);
    int max_nbit = atoi(argv[4]);

    TC cur = make_tc(max_b, max_n, max_lhbit, max_nbit);
    vector<string> Lbits (cur.Lbit.begin(), cur.Lbit.end());
    vector<string> Hbits (cur.Hbit.begin() , cur.Hbit.end());
    shuffle(Lbits.begin(), Lbits.end());
    shuffle(Hbits.begin(), Hbits.end());

    cout << cur.B << "\n";
    for (int i = 0; i < cur.B; ++i) {
        cout << Lbits[i] << "\n";
    }

    for (int i = 0; i < cur.B; ++i) {
        cout << Hbits[i] << "\n";
    }

    cout << cur.N << "\n";

    for (int i = 0; i < cur.N; ++i) {
        cout << cur.Nbit[i] << "\n";
    }

    return 0;
}