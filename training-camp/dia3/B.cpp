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

vector<ll> heap;
ll objective;
vector<pair<string,ll>> ops; 


void insert(ll x) {
  if (heap.size() == 0) heap.pb(x);
  else {
    heap.pb(0);
    ll n = heap.size();
    
    while (n/2 > 0 and heap[n/2] > x) {
      heap[n] = heap[n/2];
      n /= 2;
    }
    heap[n] = x;
  }
}

void removeMin() {
  heap[0] = heap[heap.size() - 1];
  heap.pop_back();

  // percolate down to keep property of v[i] <= v[i+1]
  
}


int main(){
  FIN;
  
  int m; cin >> m;
  forn(i,m) {
    string op; cin >> op;
    ll num = 0;
    
    if (op == "insert") {
      cin >> num;
      insert(num);
    }
    else if (op == "getMin") {
      cin >> objective;
    }
    else if (op == "removeMin") {
      removeMin();
    }
    ops.pb({op,num});
  }
  
  while () {
    
  }
  
  dbg(ops);
  dbg(heap);
  dbg(objective);
  
  
  return 0;
}
