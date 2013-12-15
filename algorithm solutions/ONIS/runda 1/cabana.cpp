#define nume "cabana"
 
#ifndef INFOARENA
#define fisier "../ONIS/" nume
//#define DBG
#else
#define fisier nume
#endif
 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
 
ifstream fin(fisier".in");
ofstream fout(fisier".out");
 
#ifdef DBG
#define fout cout
#endif
 
using namespace std;
 
const int MAX_K = 1000000 + 1;
const int MOD = 1000000007;
 
int factorial[MAX_K];
long long n,k;
 
long long explog(long long x){
     
    if(!x)
        return 1;
    if(x % 2)
        return (explog(x-1) * factorial[k]) % MOD;
    else {
        long long tmp = explog(x/2);
        return (tmp*tmp) % MOD;
    }
}
void f(){
     
    factorial[0] = 1;
    for( int i = 1; i<= MAX_K; i ++)
        factorial[i] = (1LL * factorial[i-1] * i) % MOD;
}
long long euclid(long long a, long long b, long long& x, long long& y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
     
    long long x0,y0;
    long long D = euclid(b,a%b,x0,y0);
    x = y0;
    y = x0 - (a/b) * y0;
     
    return D;
}
void euclid2(long long a,long long b,long long &d,long long &x,long long &y)
{
    if( b == 0 ){
         
        d = a;
        x = 1;
        y = 0;
        return;
    }
    long long x0, y0;
    euclid2( b, a%b, d, x0, y0 );
    x = y0;
    y = x0-y0*(a/b);
}
int main()
{
    int t=0;
    f();
    fin >> t;
    for(;t;--t){
        fin>>n>>k;
        if(!k){
            fout<<0<<'\n';
            continue;
        }
        long long sol = explog(n/k);
        n = n%k;
        if(n){
            sol = ( sol * factorial[k] ) % MOD;
            long long x=0, y=0, d=0;
            euclid2(factorial[k-n], MOD,d, x, y);
            if(x < 0)
                x += (-x/MOD + 1) * MOD;
            sol = (sol * x) % MOD;
        }
        fout << sol << '\n';
    }
     
     
    return 0;
}