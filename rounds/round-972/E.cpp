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
typedef pair<int,int> pi;
typedef vector<bool> vb;
typedef vector<int> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

struct tip {
  int x; // valor del elemento
  vi v; // referencias a siguientes
}; 

int isin(char c, vi &a) {
  // check if value is present and return its position
}

void solve() {
  int l, n, m; cin >> l >> n >> m;
  vi a(l); forn(i,l) cin >> a[i];

  vector<pi> start;
  vector<vector<tip>> mat(n, vector<tip>(m));
  forn(i,n) forn(j,m) {
    cin >> mat[i][j].x;
    if (mat[i][j].x == a[0]) start.pb({i,j});
  }

  vector<vi> lastapps(l);

  // build graph
  forn(y,n) {
    forn(x,m) {
      int act = isin(mat[y][x].x, a);
      if (act != -1 and act > 0) {
        for (int u: lastapps[act-1]) {
        }
      }
    }
  }
}

int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
