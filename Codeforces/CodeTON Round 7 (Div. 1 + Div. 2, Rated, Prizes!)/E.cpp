/*
           ▃▆█▇▄▖
       ▟◤▖　　　  ◥█  
   ◢◤ 　  ◢▐　　     ▐▉
 ▗◤　  　   ▂ ▗▖　 ▕ █▎
 ◤　▗▅▖ ◥▄　 ▀▀▀◣　█▊
▐　▕▎  ◥▖◣◤　 　　◢██
█◣　◥▅█▀　     　▐███◤
▐█▙▂　　　      ◢███◤
　◥██◣　　　　 ◢▄◤
　　　▀██▅▇▀▎▇

*/
#include <bits/stdc++.h>
#include <random>
#include <vector>
#define LOG(FMT...) fprintf(stderr, FMT)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<double,double> pdd;
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
mt19937_64 myrand(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {return (ull)myrand()%B;}
ll gcd(ll x, ll y) {return y == 0 ? x : gcd(y, x % y);}
ll qpow(ll base, ll x, ll mod) {
    ll res = 1;
    base %= mod;
    while(x) {
       if(x & 1) res = (res * base) % mod;
       base = (base * base) % mod;
       x >>= 1;
    } 
    return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}// (get inv) gcd(a,p) = 1 

const int N = 1e6 + 10;
const int M = 1e5 + 10;
const int INF = 2147483647;
const ll MOD = 1e9 + 7;
int TT = 1;
int n;
template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x; i < n; i += i & -i) {
            a[i] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        if(x <= 0) return ans;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    int find_kth(int k) {
        int ans = 0,cnt = 0;
        for (int i = 1 << __lg(n);i >= 0;i--)  //这里的20适当的取值，与MAX_VAL有关，一般取lg(MAX_VAL)
        {
            ans += (1 << i);
            if (ans >= n || cnt + a[ans] >= k)
                ans -= (1 << i);
            else
                cnt += a[ans];
        }
        return ans + 1;
    }//注意k不能太大
};
struct node {
	int l, id;
};
int a[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Fenwick<int> fw(2 * n + 1);
    vector<vector<node>> b(2 * n + 1);  
    for(int i = 1; i <= n; i++) {
    	if(i <= a[i]) {
    		b[a[i]].push_back({i, a[i]});
    		b[a[i] + n].push_back({i + n, a[i]});
    	}else {
    		b[a[i] + n].push_back({i, a[i]});
    	}
    }
    vector<int> ans(n + 1);
    for(int i = 1; i <= 2 * n; i++) {
        for(auto [l, id]: b[i]) {
            if(l <= n) {
                ans[id] = (i - l) - (fw.rangeSum(l, i));
            }
            fw.add(l, 1);
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main() {
    #ifdef ASHDR
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
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