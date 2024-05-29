#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string ToLowerCase(string s) {
    for (char& ch : s) {
        ch = tolower(static_cast<unsigned char>(ch));
    }
    return s;
}

int main() {
    int chislo;
    cin >> chislo;
    string stroka_vvoda;
    string slovo;
    vector<string> slova;
    getline(cin, stroka_vvoda);

    for(const char& c : stroka_vvoda){

        if (c != ' '){
            slovo += c;
        }
        if (c == ' ' && !slovo.empty()){
            slova.push_back(slovo);
            slovo.clear();
        }
    }
    slova.push_back(slovo);
    sort(slova.begin(), slova.end(), 
         [](const string& left, const string& right) {
            return ToLowerCase(left) < ToLowerCase(right);
        });
    for(const string& x : slova){
        cout << x << " "s;
    }
cout << endl;
}