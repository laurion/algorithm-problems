#define nume "d"
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
template<class T> inline void Swap(T& a,T& b)
{
    a^=b,b^=a,a^=b;
}

#define BAZA 1000000000
#define CIFRE 200

class Huge {
public:
    int Semn;
        int Cont;
        int V[CIFRE];
 
        Huge() {
                *this = 0;
        }
 
        Huge& operator =(long long Val) {
                this->V[0] = this->Cont = 0;
                if (Val < 0) {
                        Val = -Val;
                        this->Semn = -1;
                } else {
                        this->Semn = 1;
                }
                for (; Val; ) {
                        this->V[this->Cont++] = (int)(Val % BAZA);
                        Val -= Val % BAZA;
                        Val /= BAZA;
                }
                if (this->Cont) --this->Cont;
                return *this;
        }
 
        Huge& operator =(const Huge& B) {
                this->Cont = B.Cont;
                this->Semn = B.Semn;
                memcpy(this->V, B.V, sizeof(int) * (this->Cont + 1));
                return *this;
        }
 
        /*returneaza 1 daca A>B
         *                 0 daca A=B
         *                -1 daca A<B
         */
        int Comparare(const Huge &A, const Huge &B) const {
                if (A.Semn != B.Semn) {
                        if (A.Semn==1) return 1;
                        else return -1;
                } else {
                        if (A.Cont > B.Cont) {
                                if (A.Semn == 1) return 1;
                                else return -1;
                        } else if (A.Cont < B.Cont) {
                                if (A.Semn == 1) return -1;
                                else return 1;
                        } else {
                                int i;
                                for (i = A.Cont; A.V[i] == B.V[i] && i >= 0; --i);
                                if (i >= 0) {
                                        if (A.V[i] > B.V[i]) {
                                                if (A.Semn == 1) return 1;
                                                else return -1;
                                        } else {
                                                if (A.Semn == 1) return -1;
                                                else return 1;
                                        }
                                } else {
                                        return 0;
                                }
                        }
                }
        }
 
        bool operator >(const Huge& B) const {
                return Comparare(*this, B) == 1;
        }
 
        bool operator <(const Huge& B) const {
                return Comparare(*this, B) == -1;
        }
 
        bool operator >=(const Huge& B) const {
                return Comparare(*this, B) != -1;
        }
 
        bool operator <=(const Huge& B) const {
                return Comparare(*this, B) != 1;
        }
 
        bool operator ==(const Huge& B) const {
                return Comparare(*this, B) == 0;
        }
 
        bool operator !=(const Huge& B) const {
                return Comparare(*this, B) != 0;
        }
 
        bool operator >(const long long& b) const {
                Huge B;
                B = b;
                return Comparare(*this, B) == 1;
        }
 
        bool operator <(const long long& b) const {
                Huge B;
                B = b;
                return Comparare(*this, B) == -1;
        }
 
        bool operator >=(const long long& b) const {
                Huge B;
                B = b;
                return Comparare(*this, B) != -1;
        }
 
        bool operator <=(const long long& b) const {
                Huge B;
                B = b;
                return Comparare(*this, B) != 1;
        }
 
        bool operator ==(const long long& b) const {
                Huge B;
                B = b;
                return Comparare(*this, B) == 0;
        }
 
        bool operator !=(const long long& b) const {
                Huge B;
                B = b;
                return Comparare(*this, B) != 0;
        }
 
        Huge operator +() const {
                return *this;
        }
 
        Huge operator -() const {
                Huge A = *this;
                A.Semn = -A.Semn;
                return A;
        }
 
        Huge operator -(Huge C);
        Huge operator +(Huge C);
 
        Huge operator -(long long c) {
                Huge C;
                C = c;
                return *this - C;
        }
 
        Huge operator +(long long c) {
                Huge C;
                C = c;
                return *this + C;
        }
 
        Huge& operator ++() {
                int i;
                if (this->Semn == 1) {
                        ++this->V[0];
                        for (i = 0; this->V[i] == BAZA; ++i) {
                                this->V[i] = 0;
                                ++this->V[i + 1];
                        }
                        if (this->Cont < i) {
                                this->Cont = i;
                        }
                } else {
                        --this->V[0];
                        for (i = 0; this->V[i] == -1; ++i) {
                                this->V[i] += BAZA;
                                --this->V[i + 1];
                        }
                        if (this->V[this->Cont] == 0) {
                                --this->Cont;
                        }
                        if (this->Cont == -1) {
                                this->Semn = 1;
                                this->Cont = 0;
                        }
                }
                return *this;
        }
 
        Huge& operator --() {
                int i;
                if (this->Semn == -1) {
                        ++this->V[0];
                        for (i = 0; this->V[i] == BAZA; ++i) {
                                this->V[i] = 0;
                                ++this->V[i + 1];
                        }
                        if (this->Cont < i) {
                                this->Cont = i;
                        }
                } else {
                        if (this->Cont == 0 && this->V[0] == 0) {
                                this->Semn = -1;
                                this->V[0] = 1;
                        } else {
                                --this->V[0];
                                for (i = 0; this->V[i] == -1; ++i) {
                                        this->V[i] += BAZA;
                                        --this->V[i + 1];
                                }
                                if (this->V[this->Cont] == 0) {
                                        --this->Cont;
                                }
                                if (this->Cont == -1) {
                                        this->Cont = 0;
                                }
                        }
                }
                return *this;
        }
 
        Huge operator *(int Val) const {
                Huge A;
                if (Val < 0) {
                        Val = -Val;
                        if (this->Semn == -1) A.Semn = 1;
                        else A.Semn = -1;
                } else {
                        A.Semn = this->Semn;
                }
                int i;
                long long tmp;
                for (i = 0; i <= this->Cont + 1; ++i) {
                        A.V[i] = 0;
                }
                for (i = 0; i <= this->Cont; ++i) {
                        tmp = (long long)this->V[i] * Val + A.V[i];
                        A.V[i] = (int)(tmp % BAZA);
                        //A.V[i + 1] = (tmp - A.V[a]) / BAZA;
                        A.V[i + 1] = (int)(tmp / BAZA);
                }
                if (A.V[this->Cont + 1]) {
                        A.Cont = this->Cont + 1;
                } else {
                        A.Cont = this->Cont;
                }
                return A;
        }
 
        Huge operator *(const Huge& C) const {
                Huge A;
                if (this->Semn == 1) {
                        A.Semn = C.Semn;
                } else {
                        if (C.Semn == -1) A.Semn = 1;
                        else A.Semn = -1;
                }
                Huge Tmp;
                int i, j;
                for (i = 0; i <= this->Cont + C.Cont + 1; ++i) {
                        A.V[i] = 0;
                }
                for (i = 0; i <= C.Cont; ++i) {
                        Tmp = (*this) * C.V[i];
                        for(j = 0; j <= Tmp.Cont; ++j) {
                                A.V[i + j] += Tmp.V[j];
                                A.Cont = i + j;
                                if (A.V[i + j] >= BAZA) {
                                        A.V[i + j] -= BAZA;
                                        ++A.V[i + j + 1];
                                        A.Cont = i + j + 1;
                                }
                        }
                }
                return A;
        }
 
        Huge operator /(int Val) const {
                Huge A;
                if (Val < 0) {
                        Val = -Val;
                        if (this->Semn == -1) A.Semn = 1;
                        else A.Semn = -1;
                } else {
                        A.Semn = this->Semn;
                }
                int i;
                long long tmp1, tmp2;
                tmp1 = this->V[this->Cont];
                for (i = this->Cont; i >= 0; --i) {
                        tmp2 = tmp1 % Val;
                        tmp1 -= tmp2;
                        A.V[i] = (int)(tmp1 / Val);
                        if (i) tmp1 = tmp2 * BAZA + this->V[i - 1];
                }
                if (A.V[this->Cont]) {
                        A.Cont = this->Cont;
                } else {
                        A.Cont = this->Cont - 1;
                }
                return A;
        }
 
        int operator %(int Val) const {
                long long tmp = 0;
                int i;
                for(i = this->Cont; i >= 0; --i) {
                        tmp *= BAZA;
                        tmp += this->V[i];
                        tmp %= Val;
                }
                return (int)tmp;
        }
 
        Huge& operator +=(Huge B) {
                *this = *this + B;
                return *this;
        }
 
        Huge& operator -=(Huge B) {
                *this = *this - B;
                return *this;
        }
 
        Huge& operator +=(long long B) {
                *this = *this + B;
                return *this;
        }
 
        Huge& operator -=(long long B) {
                *this = *this - B;
                return *this;
        }
 
        Huge& operator *=(Huge& B) {
                *this = *this * B;
                return *this;
        }
 
        Huge& operator *=(int B) {
                *this = *this * B;
                return *this;
        }
 
        Huge& operator /=(int B) {
                *this = *this / B;
                return *this;
        }
 
        void afisare(FILE *output) {
                int i;
                if (this->Semn == -1) fprintf(output, "-");
                fprintf(output, "%d", this->V[this->Cont]);
                for(i = this->Cont - 1; i >= 0; --i) {
                        fprintf(output, "%.8d", this->V[i]);
                }
        }
 
        void afisare() {
                afisare(stdout);
        }
 
        void citire(FILE *input) {
                int  Nr0;
                char Nr[1000];
                int stop;
                int i, j;
                int tmp, tmpc;
                fscanf(input, "%s", Nr);
                Nr0 = strlen(Nr);
                if (Nr[0] == '-') {
                        stop = 1;
                        this->Semn = -1;
                } else {
                        stop = 0;
                        this->Semn = 1;
                }
                this->V[this->Cont = 0] = 0;
                for(i = Nr0 - 1; i >= stop; ) {
                        tmp = 0;
                        tmpc = 0;
                        for(j = 1; j <= 8 && i >= stop; ++j) {
                                tmp *= 10;
                                tmp += Nr[i] - '0';
                --i;
                ++tmpc;
                        }
                        for(j = 1; j <= tmpc; ++j) {
                                this->V[this->Cont] *= 10;
                                this->V[this->Cont] += tmp % 10;
                                tmp /= 10;
                        }
                        this->V[++this->Cont] = 0;
                }
                if (this->V[this->Cont] == 0) {
                        --this->Cont;
                }
                if (this->Cont == 0 && this->V[0] == 0 && this->Semn == -1) this->Semn = 0;
        }
 
        void citire() {
                citire(stdin);
        }
};
 
Huge Huge::operator +(Huge C) {
        Huge A;
        if ((this->Semn == -1 && C.Semn== -1) ||
                (this->Semn ==  1 && C.Semn==  1)) {
                A.Semn = this->Semn;
        int i;
        int tmp;
        int MAX = this->Cont + 1;
        if (MAX < C.Cont + 1) {
                MAX = C.Cont + 1;
        }
        for (i = 0; i <= MAX; ++i) {
                A.V[i] = 0;
        }
        for(i = this->Cont + 1; i <= MAX; ++i) {
                this->V[i] = 0;
        }
        for(i = C.Cont + 1; i <= MAX; ++i) {
                C.V[i] = 0;
        }
        for(i = 0; i <= MAX - 1; ++i) {
                tmp = A.V[i] + this->V[i] + C.V[i];
                //A.V[i] = tmp % BAZA;
                //A.V[i + 1] = tmp / BAZA;
                if (tmp < BAZA) {
                        A.V[i] = tmp;
                } else {
                        A.V[i] = tmp - BAZA;
                        A.V[i + 1] = 1;
                }
        }
        if (A.V[MAX]){
                A.Cont = MAX;
        } else {
                A.Cont = MAX - 1;
        }
                } else {
                        if (this->Semn == -1) {
                                this->Semn =  1;
                                A = C - *this;
                                this->Semn = -1;
                        } else {
                                C.Semn =  1;
                                A = *this - C;
                                C.Semn = -1;
                        }
                }
                return A;
}
 
Huge Huge::operator -(Huge C) {
        Huge A;
        if (this->Semn == -1 && C.Semn == -1) {
                this->Semn = 1;
                C.Semn = 1;
                A = C - *this;
                this->Semn = -1;
                C.Semn = -1;
        } else if (this->Semn == -1 && C.Semn ==  1) {
                this->Semn = 1;
                A = *this + C;
                this->Semn = -1;
                A.Semn = -1;
        } else if (this->Semn ==  1 && C.Semn == -1) {
                C.Semn = 1;
                A = *this + C;
                C.Semn = -1;
        } else if (this->Semn ==  1 && C.Semn ==  1) {
                if (*this >= C) {
                        A.Semn = 1;
                        int i;
                        int tmp;
                        int MAX = this->Cont + 1;
                        if (MAX < C.Cont + 1) {
                                MAX = C.Cont + 1;
                        }
                        for (i = 0; i <= MAX; ++i) {
                                A.V[i] = 0;
                                if (i > this->Cont) this->V[i] = 0;
                           if (i > C.Cont) C.V[i] = 0;
                        }
                        for (i = 0; i <= MAX - 1; ++i) {
                                tmp = A.V[i] + this->V[i] - C.V[i];
                                if (tmp >= 0) {
                                        A.V[i] = tmp;
                                } else {
                                        A.V[i] = tmp + BAZA;
                                        A.V[i + 1] = -1;
                                }
                        }
                        for (A.Cont = MAX; !A.V[A.Cont] && A.Cont; --A.Cont);
                } else {
                        A = C - *this;
                        A.Semn = -1;
                }
        }
        return A;
}
 
int n,k;
int b[252];
Huge d[252][252];//[500];
int main()
{
#ifdef _PARSARE_
    freopen(nume ".in","r",stdin);
    cit(n);
#endif
#ifdef DBG
    freopen(nume ".in","r",stdin);
#endif
    cin>>n>>k;
    int m=1e9,s=0;
    for(int i=1; i<=n; ++i) {
        cin>>b[i];
        m=min(m,b[i]);
        s+=b[i];
    }
    if((n*n)/2>s-1)
        cout<<0<<'\n';
    if(k>n)
        cout<<0<<'\n';
    else if(k==0)
        cout<<1<<'\n';
    else {
//        d[1][k]=1;
        d[0][0]=1;
        d[1][0]=1;
        d[1][1]=1;
        d[0][1]=0;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=b[i]; ++j) {
                Huge tmp=d[i-1][j-1];
                tmp*=b[i]-j+1;
                d[i][j]=tmp;
                d[i][j]+=d[i-1][j];
                //d[i][j]=d[i-1][j]+d[i-1][j-1]*(b[i]-j+1);
            }
        }
        #ifdef DBG
//        for(int i=0;i<=n+1;++i,cerr<<'\n'){
//            for(int j=0;j<=20;++j)
//                cerr<<d[i][j]<<' ';
//        }
        #endif
//        for(int i=d[n+1][0][0]; i>=1; --i)
//            cout<<d[n+1][0][i];
//        cout<<d[n][k];
        d[n][k].afisare();
        putchar('\n');
    }
#ifndef DBG
    fout.close();
#endif
    return 0;
}
