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
    int n, q;
    cin >> n >> q;

    vector<string> v(n);
    set<int> st;
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        if(stoi(v[i])>9)
            st.insert(i);
    }

    int op, l, r, k;
    while (q--)
    {
        cin >> op;
        if(op==1)
        {
            cin >> l >> r;
            l--, r--;
            vi rem;
            for(auto it = st.lower_bound(l); it!=st.upper_bound(r); it++)
            {
                int sum = 0;

                for(int i=0; i< sz( v[*it] ); i++)
                    sum+= (v[*it][i]-'0');
                
                v[*it] = to_string(sum);

                if(sum <= 9)
                    rem.pb(*it);                     
            }
            for(auto r : rem)
                st.erase(r);
        }else
        {
            cin >> k;
            k--;
            cout << v[k] << el;
        }
    }
    
}


int main()
{
    Morshedy_22

    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();


    return 0;
}