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

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
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

ii find(vi &v) {
  int num = 0;
  int i = 0;
  while (i < v.size()) {
    if (v[i] == num) num++;
    else break;
    i++;
  }
  int num2 = num +1;
  while (i < v.size()) {
    if (v[i] == num2) num2++;
    else break;
    i++;
  }

  return {num, num2};
}

bool cmp(ii &a, ii &b) {
  return a.fs > b.fs or (a.fs == b.fs and a.ss < b.ss);
}

void build(set<ll> &st, unordered_map<ll, ll> &dp, vector<ii> &mexes) {
  // function to precompute for every i which is the best option
  sort(all(mexes), cmp);
  for (auto &[f,s] : mexes) {
    st.insert(f);
    dp[f] = max(max(dp[f], s), dp[s]);
  }
}

void solve() {
  ll n,m; cin >> n >> m;
  vector<vi> g(n);
  vector<ii> mexes(n);
  ll mex = 0, mex2 = 0;
  forn(i,n) {
    int l; cin >> l;
    g[i].resize(l);

    forn(j,l) cin >> g[i][j];
    sort(all(g[i]));
    g[i].erase(unique(all(g[i])),g[i].end());

    mexes[i] = find(g[i]);
    mex = max(mex, mexes[i].fs);
    mex2 = max(mex2, mexes[i].ss);
  }
  ll ans = 0;

  // calculate f(i) for i = 0..m 
  unordered_map<ll, ll> dp; // graph
  set<ll> s;
  build(s, dp, mexes);

  vi reps; // vector to save repeated numbers
  if (n > 1 and mexes[0].fs == mexes[1].fs) reps.pb(mexes[0].fs);
  forr(i,1,n-1) {
    if (i +1 >= n or i-1 < 0) continue;
    if (mexes[i].fs == mexes[i+1].fs and mexes[i].fs != mexes[i-1].fs) 
      reps.pb(mexes[i].fs);
  }
  for (auto i : reps) mex = max(mex, dp[i]);

  forr(i,0,min(m, mex2) +1) {
    // check if number dp state was edited
    ll mi = max(i, mex);
    if (esta(i,s)) mi = max(mi, dp[i]);
    ans += mi;
  }
  if (m > mex2) {
    ans += m*(m+1)/2;
    ans -= (mex2+1)*mex2/2;
  }

  cout << ans << '\n';
  // RAYA;
}

int main(){
  FIN;
  int t = 1; cin >> t;
  while (t--) solve();
  return 0;
}
