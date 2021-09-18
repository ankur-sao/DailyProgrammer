#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Fingers{
    vector<string> dict[26][26];
    public:

    void load(const string &file);   // make it  boolean
    vector<string>& group(const string &A);
    static size_t lcs(const string &A, const string &B); // why static size_t? 
    
};





int main(){

    Fingers  fing;
    fing.load("enable1.txt");    //handle boolean


    string input[]  = {"qwertyuytresdftyuioknn", "gijakjthoijerjidsdfnokg"};

    size_t min_len = 5;

    for(auto &A : input){
        for(auto &B : fing.group(A)){
            if (B.size() >= min_len &&  fing.lcs(A,B) == B.size()){
                cout << B <<  " ";
            }
        }
        cout << "\n\n";
    }

    return 0;
}


void Fingers::load(const string& file){
    ifstream fin(file);
    string w;
    while (fin >> w) group(w).push_back(w);
}

vector<string>& Fingers::group(const string  &A){
    return dict[A.front()-'a'][A.back()-'a'];
}

size_t Fingers::lcs(const string &A, const string &B){
    int n = A.size(); int m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    
    for(size_t i = 1; i <= n; i++){
        for(size_t j = 1; j <= m ; j++){
            dp[i][j] = A[i-1] == B[j-1] ?
                         max(dp[i-1][j-1], dp[i][j-1]) + 1 :
                         max(dp[i][j-1], dp[i-1][j]); 
        }
    }
    return dp[n][m];
 }       