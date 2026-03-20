#include <bits/stdc++.h>

using namespace std;

void backtrack(int open, int close, vector<string> *ans, string *sol, int n){
    if((*sol).length() == 2*n){
        (*ans).push_back(*sol);
        return;
    }

    if(open < n){
        (*sol).push_back('<');
        backtrack(open + 1, close, ans, sol, n);
        (*sol).pop_back();
    }

    if(open > close){
        (*sol).push_back('>');
        backtrack(open, close + 1, ans, sol, n);
        (*sol).pop_back();
    }
}


vector<string> generateAngleBracketSequences(int n) {
    vector<string> ans;
    string sol;

    backtrack(0, 0, &ans, &sol, n);

    return ans;
}


int main(){

    for(auto i : generateAngleBracketSequences(2)){
        cout<<i<<endl;
    }

    return 0;
}