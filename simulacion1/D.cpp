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

vector< vector<ll> > g; // graph represented as an adjacency list
vector <bool> visto(MAXN,false);
vector<pair<ll,ll>> hijoProfundo; // pair< distancia, indexDelHijo>
  

void dfs(ll v) {
  visto[v] = true;
  hijoProfundo[v] = {-1,0};
  if (g[v].size() == 0) hijoProfundo[v] = {1,v};
  
  for (ll u : g[v]) if (!visto[u]) {
    dfs(u);
    pair<ll,ll> hijodeu = hijoProfundo[u];
    hijodeu.first++;
    hijoProfundo[v] = max(hijoProfundo[v],hijodeu);
  }
}

int main(){
  FIN;
  
  ll n,k; cin >> n >> k;

  vector<ll> v(n);
  g.resize(n+5);
  hijoProfundo.resize(n);
  
  v[0] = -1;
  for (ll i = 1; i < n; i++) {
    cin >> v[i];
    v[i]--;
    g[v[i]].pb(i);
  }
  dfs(0);
  
  vector<bool> borrado(n);
  priority_queue<pair<ll,ll>> q;
  
  forn(i,n) {
    pair<ll,ll> hijodei = hijoProfundo[i];
    hijodei.second = i;
    q.push(hijodei);
  }
  
  ll tot = 0;
  forn(i,k) {
    pair<ll,ll> act = q.top();
    while (borrado[act.second]) {
      q.pop();
      act = q.top();
    }
  
    ll hoja = hijoProfundo[act.second].second;
    while (hoja != -1 and borrado[hoja] == false) {
      borrado[hoja] = true;
      tot++;
      hoja = v[hoja];
    }
  }
  
  cout << tot << "\n";
  
  return 0;
}
