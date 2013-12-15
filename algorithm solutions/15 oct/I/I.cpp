#define nume "i"
//#define DBG

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

//#define _PARSARE_
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
#ifdef DBG
#define fout cout
#endif
//// hash-uri
//#include<ext/hash_map>
//hash_multimap<int,int> H;
//hash_map<char*,int> H;

#define foreach(it, v) for (typeof((v).begin()) it = (v).begin(),stop=(v).end(); it != stop; ++it)
#define foreach_r(it, v) for (typeof((v).rbegin()) it = (v).rbegin(),stop=(v).rend(); it != stop; ++it)
template<class T> inline void Swap(T& a,T& b){a^=b,b^=a,a^=b;}

int n,m;
bool letter(char s)
{
    bool b = (s>='a'&&s<='z') || (s>='A'&&s<='Z');
    return b;
}
bool symbol(char s)
{
    bool b = letter(s) || (s>='0'&&s<='9') || s=='_' || s=='-';
    return b;
}
bool word (string s)
{
    if(s.empty())
        return 0;
    if(s.length()==1)
        return symbol(s[0]);
    bool b = symbol(s[0]) && word(s.substr(1));
    return b;
}
bool domain(string s)
{
    if(s.empty())
        return 0;
    if(s.length()>3)
        return 0;
    if(s.length()==3)
        return letter(s[0])&&letter(s[1])&&letter(s[2]);
    if(s.length()==2)
        return letter(s[0])&&letter(s[1]);
    return 0;
}
bool prefix(string s)
{
    if(s.empty())
        return 0;
    int p = s.find_last_of('.');
    if(p>=0&&p<s.length()){
        bool b = prefix(s.substr(0,p)) && word(s.substr(p+1));
        return b;
    }
    bool b = word(s);
    return b;
        
}
bool suffix(string s)
{
    if(s.empty())
        return 0;
    int p = s.find_last_of('.');
    if(p<0 || p>=s.length())
        return false;
    bool b= prefix(s.substr(0,p)) && domain(s.substr(p+1));
    return b;
}
bool checkemail(string s)
{
    if(s.empty())
        return 0;
    int at = s.find('@');
    if(at<0 || at>=s.length())
        return false;
    bool b = prefix(s.substr(0,at)) && suffix(s.substr(at+1));
    return b;
}
int main()
{
    #ifdef _PARSARE_
    freopen(nume ".in","r",stdin);
    cit(n);
    #endif
    
//    freopen(nume ".in","r",stdin);
    
    cin>>n;
    string s;
    cin.get();
    for(int i=0;i<n;++i)
    {
        getline(cin,s);
        if(checkemail(s))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    
    
    #ifndef DBG
    fout.close();
    #endif
    return 0;
}
