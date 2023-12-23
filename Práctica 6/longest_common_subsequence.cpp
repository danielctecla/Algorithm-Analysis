#include <bits/stdc++.h>

using namespace std;

pair<int,vector<vector<char>>> lcs(string &text_f, string &text_s){
    int n = text_f.size(), m = text_s.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<char>> dir(n+1, vector<char>(m+1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                dir[i][j] = '0';
            }else if(text_f[i-1] == text_s[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 'd';
            }else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                dir[i][j] = 'u';
            }else{
                dp[i][j] = dp[i][j-1];
                dir[i][j] = 'l';
            }
        }
    }

    return {dp[n][m], dir};
}

void print_lcs(vector<vector<char>> &dir, string &text_f, int i, int j){
    if(i == 0 || j == 0) return;
    
    if(dir[i][j] == 'd'){
        print_lcs(dir, text_f, i-1, j-1);
        cout<<text_f[i-1];
    }else if(dir[i][j] == 'u') print_lcs(dir, text_f, i-1, j);
    else print_lcs(dir, text_f, i, j-1);
}

string onlyChars(string &text){
    string temp = "";
    for(auto &c : text){
        if(c != ' ' && c != '\n') temp+=c;
    } 
    
    return temp;
}

int main(){
    // variable declaration
    string file_one, file_two;
    ifstream file_f("longest_common_subsequence.cpp");
    ifstream file_s("readFiles.cpp");
    
    if(!file_f.is_open() && !file_s.is_open()) return 0;

    stringstream buffer_f, buffer_s;
    buffer_f << file_f.rdbuf();
    buffer_s << file_s.rdbuf();
    file_one = buffer_f.str();
    file_two = buffer_s.str();
    file_f.close();
    file_s.close();

    
    string  first_code = onlyChars(file_one);
    string second_code = onlyChars(file_two);
    
    vector<vector<char>> grid;
    int len;
    // function call
    tie(len, grid) = lcs(first_code, second_code);

    // printing the length of longest common subsequence
    cout<<"Length of longest common subsequence: "<<len<<endl;

    // printing the longest common subsequence
    cout<<"Longest common subsequence: "<<endl<<endl;
    print_lcs(grid, first_code, first_code.size(), second_code.size());
}