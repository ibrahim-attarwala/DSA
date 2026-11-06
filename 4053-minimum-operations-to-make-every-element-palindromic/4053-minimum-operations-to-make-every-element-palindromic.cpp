#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    long long lower(vector<long long>& v, long long x) {
        long long ans = 0LL;
        int i = 0, j = v.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (v[mid] == x) {
                return x;
            }
            if (v[mid] < x) {
                ans = v[mid];
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }

    long long upper(vector<long long>& v, long long x) {
        long long ans = 0LL;
        int i = 0, j = v.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (v[mid] == x) {
                return x;
            }
            if (v[mid] > x) {
                ans = v[mid];
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }

    long long check(vector<long long>& v, long long x) {
        long long ind1 = lower(v, x);
        long long ind2 = upper(v, x);
        return min(abs(ind1 - x), abs(ind2 - x)) / 2LL;
    }

    long long minOperations(vector<int>& nums) {
        long long op = 0;
        static vector<long long> even_palin;
        static vector<long long> odd_palin;
        if (even_palin.empty() || odd_palin.empty()) {
            for (long long i = 0; i < 10; i++) {
                if (i % 2 == 1) {
                    odd_palin.push_back(i);
                } else {
                    even_palin.push_back(i);
                }
            }

            for (int i = 1; i <= 10000; i++) {
                string s = to_string(i);
                string s2(s.rbegin(), s.rend());
                long long x = stoll(s + s2);
                if (x % 2 == 1) {
                    odd_palin.push_back(x);
                } else {
                    even_palin.push_back(x);
                }
            }

            for (int i = 10; i < 100000; i++) {
                string s = to_string(i);
                string s2(s.rbegin() + 1, s.rend());
                long long x = stoll(s + s2);
                if (x % 2 == 1) {
                    odd_palin.push_back(x);
                } else {
                    even_palin.push_back(x);
                }
            }

            sort(even_palin.begin(), even_palin.end());
            sort(odd_palin.begin(), odd_palin.end());
        }
        for (auto x : nums) {
            if (x % 2 == 1) {
                op += check(odd_palin, (long long)x);
            } else {
                op += check(even_palin, (long long)x);
            }
        }
        return op;
    }
};