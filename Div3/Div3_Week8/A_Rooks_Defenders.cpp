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

vi freqr(N), freqc(N);

void testCase()
{
    int n, q;
    cin >> n >> q;
    
    set<int> col, row;
    for(int i=1; i<=n; i++)
        col.insert(i), row.insert(i);

    int op;
    int x1, y1, x2, y2;
    while(q--)
    {
        cin >> op;
        if(op == 1)
        {       
            cin >> x1 >> y1;
            
            freqr[x1]++;
            freqc[y1]++;
            
            if(row.count(x1))
                row.erase(x1);
            if(col.count(y1))
                col.erase(y1);
        }
        else if(op == 2)
        {
            cin >> x1 >> y1;

            freqr[x1]--;
            freqc[y1]--;
            
            if(not freqr[x1])
                row.insert(x1);
            
            if(not freqc[y1])
                col.insert(y1);

        }
        else if(op == 3)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            
            int f = 0;
            int r = *row.lower_bound(min(x1,x2));
            f |= (r>max(x1,x2));
            
            int c = *col.lower_bound(min(y1,y2));
            f |= (c>max(y1,y2));

            cout << ( f ? "Yes" : "No") << el;
        }
    }
}


int32_t main()
{
    Morshedy_22

    int tc = 1;
    // cin >> tc;
    while(tc--)
        testCase();


    return 0;
}