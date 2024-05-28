#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}


vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

struct Document {
    int id;
    int relevance;
};

bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
    return lhs.relevance > rhs.relevance;
}
class SearchServer {
   public:

    
struct DocumentContent {
    int id = 0;
    vector<string> words;
};
    
    
    void ParseQuery(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
        if (stop_words_.count(word) == 0) {
        query_.insert(word);
        
    }
    }
    }
         
    
    void SetStopWords(const string& text){
        for (const string& word : SplitIntoWords(text)) {
        stop_words_.insert(word);
    }
    }
    
    void AddDocument(int document_id, const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document);
    documents_.push_back({document_id, words});
    }
    
    
    
        vector<Document> FindTopDocuments() {
    auto matched_documents = FindAllDocuments();

    sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
    if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
        matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
    }
    return matched_documents;
        }


    private:
    
            int MatchDocument(const DocumentContent& content) {
    if (query_.empty()) {
        return 0;
    }
    set<string> matched_words;
    for (const string& word : content.words) {
        if (matched_words.count(word) != 0) {
            continue;
        }
        if (query_.count(word) != 0) {
            matched_words.insert(word);
        }
    }
    return static_cast<int>(matched_words.size());
}
            
    vector<Document> FindAllDocuments() {
    vector<Document> matched_documents;
    for (const auto& document : documents_) {
        const int relevance = MatchDocument(document);
        if (relevance > 0) {
            matched_documents.push_back({document.id, relevance});
        }
    }
    return matched_documents;
}

    
    
    
    vector<DocumentContent> documents_;
    set<string> stop_words_;
    set<string> query_;
    
    vector<string> SplitIntoWordsNoStop(const string& text) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words_.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

};

SearchServer CreateSearchServer(){
    SearchServer search_server;
    search_server.SetStopWords(ReadLine());
    
    const int document_num = ReadLineWithNumber();
    for(int x = 0; x<document_num; ++x ){
        search_server.AddDocument(x, ReadLine());
    }
    search_server.ParseQuery(ReadLine());
    
    return search_server;
}

int main() {
    
    SearchServer server = CreateSearchServer();
    
     for (auto [document_id, relevance] : server.FindTopDocuments()) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
             << endl;
     }
}