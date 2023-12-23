#include <bits/stdc++.h>

using namespace std;

pair<int,vector<vector<char>>> lcs(string &text_f, string &text_s, int &count){
    count++;
    count++;
    int n = text_f.size(), m = text_s.size();
    
    count++;
    count++;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<char>> dir(n+1, vector<char>(m+1));

    count++;
    for(int i = 0; i <= n; i++){
        count++;
        count++;
        for(int j = 0; j <= m; j++){
            count++;
            
            if(i == 0 || j == 0){
                count++;
                dp[i][j] = 0; count++;
                dir[i][j] = '0'; count++;
            }else if(text_f[i-1] == text_s[j-1]){
                count++;
                dp[i][j] = dp[i-1][j-1] + 1; count++;
                dir[i][j] = 'd'; count++;
            }else if(dp[i-1][j] > dp[i][j-1]){
                count++;
                dp[i][j] = dp[i-1][j]; count++;
                dir[i][j] = 'u'; count++;
            }else{
                dp[i][j] = dp[i][j-1]; count++;
                dir[i][j] = 'l'; count++;
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
    string  first_code = "";
    string second_code = "";
    char excel[]="comportamiento.csv";
    FILE *output = fopen(excel,"w");
    int count = 0;

    for(int i = 0; i < 1000; i++){
        first_code += "a";
        second_code += "a";
        vector<vector<char>> grid;
        int len;
        // function call
        tie(len, grid) = lcs(first_code, second_code, count);
        fprintf(output,"%d,%d\n",i,count);
        // printing the length of longest common subsequence
        cout<<"Length of longest common subsequence: "<<len<<endl;

        // printing the longest common subsequence
        cout<<"Longest common subsequence: "<<endl<<endl;
        print_lcs(grid, first_code, first_code.size(), second_code.size());
        count = 0;
    }
}