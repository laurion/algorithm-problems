#define nume "icrisop"
///
#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<string>
#include<sstream>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<list>
#include<algorithm>
 
using namespace std;
 
#define _PARSARE_
#ifdef _PARSARE_
#define DIM 8192
char ax[DIM+16];
int _idx;
template<class T>
inline void cit(T& x)
{
    x=0;
    while((ax[_idx]<'0' || ax[_idx]>'9') && (ax[_idx]!='-'))
        if(++_idx==DIM)fread(ax, 1, DIM, stdin), _idx=0;
 
    int neg=0;
    if(ax[_idx]=='-') {
        neg=1;
        if(++_idx==DIM)fread(ax, 1, DIM, stdin),_idx=0;
    }
 
    while(ax[_idx]>='0' && ax[_idx]<='9') {
        x=x*10+ax[_idx]-'0';
        if(++_idx==DIM)fread(ax,1, DIM, stdin),_idx=0;
    }
    if(neg) x=-x;
}
#else
ifstream fin (nume ".in");
#endif //_PARSARE_
ofstream fout(nume ".out");
 
#define foreach(it, v) for (typeof((v).begin()) it = (v).begin(),stop=(v).end(); it != stop; ++it)
#define foreach_r(it, v) for (typeof((v).rbegin()) it = (v).rbegin(),stop=(v).rend(); it != stop; ++it)
template<class T> inline void Swap(T& a,T& b){a^=b,b^=a,a^=b;}
 
int N,S,x;
int ap[105],dp[105];
int sol[105][105],aux[105][105],C[105][105],ans[105][105];
#define MOD 666013
inline void mul(int A[][105],int B[][105])
{
    memset(C,0,sizeof(C));
    for(int i=0;i<105;++i)
        for(int j=0;j<105;++j)
            for(int k=0;k<105;++k)
                C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j])%MOD;
    memcpy(A,C,sizeof(C));
}
int main()
{
    #ifdef _PARSARE_
    freopen(nume ".in","r",stdin);
    cit(N);
    cit(S);
    #endif
     
//    fin>>n>>S;
    for(int i=0,x;i<N;++i)
        cit(x),++ap[x];
     
    dp[0]=1;
    for(int n=1;n<=100;++n)
        for(int i=1;i<=n;++i)
            dp[n]=(dp[n]+dp[n-i]*ap[i])%MOD;
    if(S<=51){
        fout<<dp[S]<<'\n';
        return 0;
    }
    for(int i=1;i<100;++i)
        aux[i+1][i]=1;
    for(int i=1;i<=100;++i)
        aux[i][100]=ap[100-i+1];
    int& P=S;
    for(int i=1;i<=100;++i)
        sol[i][i]=1;
    for(--P;P;P>>=1)
    {
        if(P&1)
            mul(sol,aux);
        mul(aux,aux);
    }
     
    memcpy(ans[1],dp,sizeof(dp));
    mul(ans,sol);
    fout<<ans[1][1]<<'\n';
 
    fout.close();
    return 0;
}