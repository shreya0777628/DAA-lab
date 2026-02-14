#include <iostream>
using namespace std;

int main() {
    string txt = "THIS IS A TEST TEXT";
    string pat = "TEST";

    for (int i = 0; i <= txt.size() - pat.size(); i++) {
        int j;
        for (j = 0; j < pat.size(); j++)
            if (txt[i + j] != pat[j]) break;
        if (j == pat.size())
            cout << "Pattern found at index " << i << endl;
    }
    return 0;
}
