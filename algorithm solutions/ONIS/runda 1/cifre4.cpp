#include <fstream>
 
using namespace std;
 
ifstream f("cifre4.in");
ofstream g("cifre4.out");
 
long long N, P;
 
bool isOkay (long long n) {
    while (n) {
        int c = n % 10;
        if (c != 2 && c != 3 && c != 5 && c != 7)
            return 0;
        n /= 10;
    }
     
    return 1;
}
 
int main() {
    int Teste;
     
    f >> Teste;
    while (Teste--) {
        int crt = 0, ok = 0;
        int nr = 1;
         
        long long ans = -1;
         
        f >> N >> P;
        long long tmp = P;
         
        while (tmp) {
            crt++;
            tmp /= 10;
        }
         
        while (crt--)
            nr *= 10;
         
        for (int i = 0; i <= nr && !ok; i++) {
            long long tmp = 1LL * i * P + N;
            if (isOkay (tmp)) {
                ok = 1;
                ans = tmp;
            }
        }
         
        g << ans << '\n';
    }
     
    return 0;
}