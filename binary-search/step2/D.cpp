#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


int m, n;
vector< vector<int> > a;
vector<int> aux;
vector<int> results;

bool good(int x) {
    int total = 0;
    aux.resize(n);
    results.resize(n);

    forn(i,n) {
        int t = a[i][0];
        int z = a[i][1];
        int y = a[i][2];
        int cont = 0;
                
		int bloque = z*t + y;
		cont = z*(x/bloque) + (x % bloque)/t;
		
		dbg(x, i, cont);
        aux[i] = cont;
        total += cont;
    }
    
    if (total >= m) forn(i,n) results[i] = aux[i];
    return total >= m;
}

int main() {

    cin >> m >> n;
    a.resize(n);

    forn (i,n) {
        a[i].resize(3);
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    int l = 0;
    int r = 1e5;

    forn (i, 60) {
        int middle = (l + r) / 2;
		dbg(i, middle);
        if (good(middle)) {
            r = middle;
        } else {
            l = middle;
        }
    }

    cout << r << "\n";
    forn(i, n) cout << results[i] << " ";

    return 0;
}
