#include <iostream>
#include <vector>

using namespace std;

struct mission
{
    long long K,D,A;
};


int main(void){
    int n,m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vector<mission> missions(m);
        for (int j = 0; j < m; j++)
        {
            cin >> missions[j].K >> missions[j].D >> missions[j].A;
        }
        long long ans = 0;
        int k,d,a;
        cin >> k >> d >> a;
        for (int j = 0; j < m; j++)
        {
            long long total_k = k * missions[j].K, total_d = d * missions[j].D, total_a = a * missions[j].A;
          
            if ((total_k + total_a) > total_d)
            {
                ans += (total_k + total_a - total_d);
            }
            
        }
        cout << ans << "\n";
        
    }
    
    return 0;
}