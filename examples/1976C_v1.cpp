#define MULTI // comment this line when there is only one testcase

#include <bits/stdc++.h>

using namespace std;

int N1, N2, N, cnt1, cnt2, nn1, nn2;
long long ok;
vector<long long> p, t, ans;
vector<pair<int, long long> > pt, tp;

void calc(int i) {
    if(cnt1 == N1 && cnt2 == N2) {
        ans[i - 1] = ok - max(t[i], p[i]);
    }
    else if(cnt1 > N1) {
        int k = cnt1 - N1;

        ans[i - 1] = ok - max(t[i], p[i]);
        if(i == N) {
            ans[i - 1] -= pt[nn1 - 1].second;
        }
        else {
            if(p[i] > t[i] && pt[nn1 - k].first <= i) {
                ans[i - 1] -= pt[nn1].second - pt[nn1 - k - 1].second - p[i] + t[i];
            }
            else {
                ans[i - 1] -= pt[nn1].second - pt[nn1 - k].second;
            }
        } 
    }
    else {
        int k = cnt2 - N2;
        ans[i - 1] = ok - max(t[i], p[i]);
        if(i == N) {
            ans[i - 1] -= tp[nn2 - 1].second;
        }
        else {
            if(p[i] < t[i] && tp[nn2 - k].first <= i) {
                ans[i - 1] -= tp[nn2].second - tp[nn2 - k - 1].second - t[i] + p[i];
            }
            else {
                ans[i - 1] -= tp[nn2].second - tp[nn2 - k].second;
            }
        } 
    }
}

void solve() {
    cin >> N1 >> N2;
    N = N1 + N2 + 1;
    p.assign(N + 1, 0);
    t.assign(N + 1, 0);
    ans.assign(N, 0);

    pt.clear();
    tp.clear();

    pt.push_back({0, 0});
    tp.push_back({0, 0});

    for(int i = 1; i <= N; ++i) {
        cin >> p[i];
    }

    for(int i = 1; i <= N; ++i) {
        cin >> t[i];
    }

    cnt1 = cnt2 = 0;
    ok = 0;
    nn1 = nn2 = 0;

    for(int i = 1; i <= N; ++i) {
        cnt1 += p[i] > t[i];
        cnt2 += p[i] < t[i];
        ok += max(p[i], t[i]);

        if(p[i] > t[i]) {
            long long s = pt.back().second;
            pt.push_back({i, s + p[i] - t[i]});
            ++nn1;
        }
        else {
            long long s = tp.back().second;
            tp.push_back({i, s + t[i] - p[i]});
            ++nn2;
        }
    }

    for(int i = 1; i < N; ++i) {
        if(p[i] > t[i]) {
            --cnt1;
            calc(i);
            ++cnt1;
        }
        else {
            --cnt2;
            calc(i);
            ++cnt2;
        }
    }

    cnt1 = cnt2 = 0;
    for(int i = 1; i < N; ++i) {
        if(p[i] > t[i]) {
            if(cnt1 < N1) {
                ++cnt1;
                ans[N - 1] += p[i];
            }
            else {
                cnt2++;
                ans[N - 1] += t[i];
            }
        }
        else {
            if(cnt2 < N2) {
                ++cnt2;
                ans[N - 1] += t[i];
            } 
            else {
                ++cnt1;
                ans[N - 1] += p[i];
            }
        }
    }

    for(auto e : ans) {
        cout << e << ' ';
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