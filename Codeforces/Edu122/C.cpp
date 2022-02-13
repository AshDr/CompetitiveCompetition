#include<bits/stdc++.h>
//#define cerr cout<<"#case:"
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < (int)v.size(); ++i)
    os << ' ' << v[i];
  }
  return os;
}
void dbg_out() { cerr << "\b\b )" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T){cerr << H << ", ";dbg_out(T...);}
#define debug(...) cerr << "( " << #__VA_ARGS__ << " ) = ( ", dbg_out(__VA_ARGS__)
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 10;
const int M = 1e5 + 10;
const int INF = 2147483647;
const LL MOD = 1e9 + 7;
int TT = 1;
LL gcd(LL x, LL y) {return y == 0 ? x : gcd(y, x % y);}
LL qpow(LL base, LL x, LL mod = MOD) {
    LL res = 1;
    while(x) {
       if(x & 1) res = (res * base) % mod;
       base = (base * base) % mod;
       x >>= 1;
    } 
    return res;
}
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL d = exgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}// (get inv) gcd(a,p) = 1 
int norm(int x) { return x >= MOD ? x - MOD : x; }
void add(int& x, int y) {
  if ((x += y) >= MOD)
    x -= MOD;
}

void sub(int& x, int y) {
  if ((x -= y) < 0)
    x += MOD;
}
#define sz(x) (int)x.size()
void solve() {
    LL hc,dc,hm,dm,k,w,a;
    cin >> hc >> dc >> hm >> dm;
    cin >> k >> w >> a;
    for(LL i = 0; i <= k; i++) {
        LL t1 = (hm + dc - 1 + i * w) / (dc + i * w);
        LL t2 = (hc + dm - 1 + (k - i) * a) / dm;
        if(t1 <= t2) {
            cout << "YES" << '\n';
            return ;
        }
    }
    cout << "NO" << '\n';

}
int main() {
    #ifdef ASHDR
    freopen("data.in","r",stdin);
    int nol_cl = clock();
    #endif
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(8);
    cin>>TT;
    while(TT--) solve();
    #ifdef ASHDR
    LOG("Time: %dms\n", int ((clock()
            -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
    #endif
    return 0;
}
/*
t1 = (hm + dc - 1 + p * w) / (dc + p * w); 人杀怪兽
t2 = (hc + dm - 1 + (k - p) * a) / dm;
E t1 <= t2  YES


*/