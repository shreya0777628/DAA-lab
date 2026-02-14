#include <iostream>
using namespace std;

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    int d = 256, q = 101;
    int M = pat.size(), N = txt.size();
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < M-1; i++) h = (h*d) % q;
    for (int i = 0; i < M; i++) {
        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;
    }

    for (int i = 0; i <= N-M; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < M; j++)
                if (txt[i+j] != pat[j]) break;
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < N-M) {
            t = (d*(t - txt[i]*h) + txt[i+M]) % q;
            if (t < 0) t += q;
        }
    }
    return 0;
}
