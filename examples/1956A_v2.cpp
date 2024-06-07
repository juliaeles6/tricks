#define MULTI // comment this line when there is only one testcase

#include <bits/stdc++.h>

using namespace std;

int K, Q, N;
vector<int> a;
bool has_excluded;
int cnt;

void solve() {
    cin >> K >> Q;
    a.assign(K, 0);
    for(int k = 0; k < K; ++k) {
        cin >> a[k];
    }

    while(Q--) {
        cin >> N;

        do {
            cnt = N;
            has_excluded = false;

            for(int i = 1; i <= N; ++i) {
                if(binary_search(a.begin(), a.end(), i)) {
                    --cnt;
                    has_excluded = true;
                }
            }

            N = cnt;
        }
        while(has_excluded);

        cout << cnt << ' ';
    }
    cout << '\n';
}

void precalc() {
	// some precalculations if needed
}

int main() {
	precalc();

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#ifdef MULTI
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
#else 
	solve();
#endif

	return 0;
}