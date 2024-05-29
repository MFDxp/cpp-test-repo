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
    string stroka_vvoda;
    string slovo;
    vector<string> slova;
    getline(cin, stroka_vvoda);
    bool first = true; // это чтобы что?
    for(const char& c : stroka_vvoda){
        
        if (first){ // не лишнее ли?
            first = false;
            continue;
        }
        if (slovo.size() == 0 && c == ' '){ // перемудрил
            continue;
        }
        if (c != ' '){
            slovo += c;
        }
        if (c == ' '){
            slova.push_back(slovo); // подумай как обойтись условиями со строк 31 - 37, мб доп проверочку какую и все)
            slovo.clear();
        }
    }
    slova.push_back(slovo); // всегда ли?
    sort(slova.begin(), slova.end(), 
         [](const string& left, const string& right) {
            return ToLowerCase(left) < ToLowerCase(right);
        });
    for(const string& x : slova){
        cout << x << " "s;
    }
    
}
