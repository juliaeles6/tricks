#define MULTI // comment this line when there is only one testcase

#include <bits/stdc++.h>

using namespace std;

int K, Q, N;
vector<int> a;
vector<int> x[2];
bool has_excluded;
int r;

void solve() {
    cin >> K >> Q;
    a.assign(K, 0);
    for(int k = 0; k < K; ++k) {
        cin >> a[k];
    }

    while(Q--) {
        cin >> N;

        x[0].assign(N, 0);
        x[1].clear();
        r = 0;

        do {
            has_excluded = false;

            for(int i = 0; i < x[r].size(); ++i) {
                if(binary_search(a.begin(), a.end(), i + 1)) {
                    has_excluded = true;
                }
                else {
                    x[r ^ 1].push_back(i);
                }
            }

            x[r].clear();
            r ^= 1;
        }
        while(has_excluded);

        cout << x[r].size() << ' ';
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