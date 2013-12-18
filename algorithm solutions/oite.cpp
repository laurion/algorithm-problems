#define nume "oite"
 
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
using namespace __gnu_cxx;
 
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
 
int n,s;
int v[1030];
#define MOD 24593ul
vector<int> H[MOD];
int main()
{
    #ifdef _PARSARE_
    freopen(nume ".in","r",stdin);
    cit(n);
    cit(s);
    #endif
     
     
    for(int i=0;i<n;++i)
        cit(v[i]);
 
    int sol=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j)
            if(s>=v[i]+v[j])
            {
                int list=(s-v[i]-v[j])%MOD;
                foreach(it,H[list])
                    if(*it==s-v[i]-v[j])
                        sol++;
            }
        for(int j=0;j<i;++j)
            H[(v[i]+v[j])%MOD].push_back(v[i]+v[j]);
    }
    fout<<sol<<'\n';
     
     
    fout.close();
    return 0;
}