#include <iostream>
#include <vector>
using namespace std;

void computeLPS(string pat, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < pat.size(); ) {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len-1];
        else
            lps[i++] = 0;
    }
}

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    vector<int> lps(pat.size());
    computeLPS(pat, lps);

    for (int i = 0, j = 0; i < txt.size(); ) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }
        if (j == pat.size()) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j-1];
        } else if (i < txt.size() && pat[j] != txt[i]) {
            if (j) j = lps[j-1];
            else i++;
        }
    }
    return 0;
}
