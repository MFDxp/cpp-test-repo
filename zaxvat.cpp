#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <set>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result;
    cin >> result;
    ReadLine();
    return result;
}

int main() {
    const int queryCount = ReadLineWithNumber();

    vector<string> queries(queryCount);
    for (string& query : queries) {
        query = ReadLine();
    }
    const string buzzword = ReadLine();

    cout << count_if(queries.begin(), queries.end(), [buzzword](const string& query) {
        set <string> slova;
        string slovo;
        for(const char& c : query){

        if (c != ' '){
            slovo += c;
        }
        if (c == ' '){
            slova.insert(slovo);
            slovo.clear();   
        }
        }
        if(slova.count(buzzword)){
            slova.clear();
            return true;
        }
        slova.clear();
        
        return false;
        // Верните true, если query содержит слово buzzword
    });
    cout << endl;
}