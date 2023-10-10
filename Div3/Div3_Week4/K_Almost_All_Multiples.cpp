#include <bits/stdc++.h>

using namespace std;

//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define Morshedy_22 ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define FILL(a, b) memset(a, b, sizeof(a))
#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) (int)(x).size()
#define el '\n'
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

const int inf = 0x3f3f3f3f;
const ll infLL = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1e5+5;
const int mod = 1e9+7;
const int d4x[4]={-1, 0, 1, 0}, d4y[4]={0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

/*
---> وتظل تسعى جاهدا في همةٍ   ..  والله يعطي من يشاءُ إذا شكر <---
*/


void testCase()
{
    int n, x;
    cin >> n >> x;

    if(n%x)
        return cout << -1 << el, void();
    
    vi ans(n+1); 
    iota(all(ans), 0);

    ans[1] = x, ans[n] = 1;
    if(n!=x)
        ans[x] = n;

    for(int i=x; i<n; )
    {
        int j=i+i;
        for( ; j<n; j+=i)
        {
            if(ans[i]%j)
                continue;
            
            if(ans[j]<ans[i])
            {
                swap(ans[j],ans[i]);
                break;
            }
            
        }
        i = j;
    }

    for(int i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << el;
}

// 10 2
// 2 10 3 4 5 6 7 8 9 1 
int32_t main()
{
    Morshedy_22

    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();


    return 0;
}