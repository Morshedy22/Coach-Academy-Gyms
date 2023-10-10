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
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if(a == b)
        return cout << 0 << el, void();
    
    if(abs(a-b) >= x)   
        return cout << 1 << el, void();
    
    int ans = -1, f = 0;
    if( abs(a-l) >= x)
    {
        if( abs(b-l) >= x)
            ans = 2, f=1;
        else if( abs(r-l) >= x)
            if(abs(r-b) >= x)
                ans = 3, f=1;
    }
    if(abs(r-a) >=x)
    {
        if(abs(r-b) >= x)
            ans = 2;
        else if(abs(r-l) >= x)
            if(abs(b-l) >= x)
                ans = (f ? min(ans,3LL) : 3);
    }

    cout << ans << el;
}


int32_t main()
{
    Morshedy_22

    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();


    return 0;
}