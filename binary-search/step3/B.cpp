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
const ll MAXN = (ll)(1e14);


int main(){
  FIN;
  
  int n, k; cin >> n >> k;
  vector<int> nums(n,0); forn(i,n) cin >> nums[i];
  
  ll l = 0;
  ll r = MAXN;
  
  while (r > l + 1) {
    ll m = (l+r)/2;
    ll segments = 1;
    ll actSum = 0;
    int i = 0;
    bool f = false;
    dbg(l,m,r);
    while (i < n && f == false) {
      if (nums[i] > m) f = true;
      if (actSum + nums[i] > m) {
	actSum = 0;
	segments++;
      }
      actSum += nums[i];
      i++;
    }
    
    if (segments > k or f) l = m;
    else r = m;
  }
  cout << l << "\n";
  
  return 0;
}
