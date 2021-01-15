#include <iostream>
#include <stack>
#include <string>

using namespace std;


string valido(string p) {
    stack <char> S;
    S.push(p[0]);

    for (int i = 1; i < p.size(); ++i) {
        if (!S.empty()) {
            if (p[i] == S.top()) {
                S.pop();
            }
            else {
                S.push(p[i]);
            }
        }
        else {
            S.push(p[i]);
        }
    }

    if (S.empty()) {
        return "Yes";
    }
    else {
        return "No";
    }
}



int main()
{
    string in;

    cin >> in;
    //in = "+++";

    cout << valido(in) << endl;
}
