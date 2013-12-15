#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
ifstream f("easygraph.in");
ofstream g("easygraph.out");
 
const int MAX_N = 15005;
const long long INF = -10000000;
 
int n, m;
long long cost[MAX_N], cst[MAX_N], dp[MAX_N];
bool used[MAX_N];
 
vector <int> L[MAX_N];
 
void init() {
    for (int i = 0; i < MAX_N; i++) {
        L[i].clear();
        cst[i] = INF;
    }
     
    memset (dp, 0, sizeof(dp));
    memset (used, 0, sizeof(used));
}
 
void read() {
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> cost[i];
     
    for (int i = 1; i <= m; i++) {
        int a, b;
         
        f >> a >> b;
        L[a].push_back (b);
    }
}
 
void dfs (int nod) {
    used[nod] = 1;
    dp[nod] = cost[nod];
     
    for (size_t i = 0; i < L[nod].size(); i++) {
        int vecin = L[nod][i];
        if (!used[vecin])
            dfs (vecin);
         
        cst[nod] = max (cst[nod], dp[vecin]);
    }
     
    if (cst[nod] > 0)
        dp[nod] += cst[nod];
}
 
void solve() {
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs (i);
     
    long long ans = INF;
    for (int i = 1; i <= n; i++)
        ans = max (ans, dp[i]);
         
    g << ans << '\n';
}
 
int main() {
    int Teste;
     
    f >> Teste;
    while (Teste--) {
        init();
        read();
        solve();
    }
     
    return 0;
}