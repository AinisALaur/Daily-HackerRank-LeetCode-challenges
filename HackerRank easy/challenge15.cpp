#include<bits/stdc++.h>

using namespace std;

void backtrack(vector<string> *res, map<char, string> mapping, int i, string *sol, int size, string digits){
    if(sol->length() == size){
        res->push_back(*sol);
        return;
    }

    for(auto k : mapping[digits[i]]){
        sol->push_back(k);
        backtrack(res, mapping, i + 1, sol, size, digits);
        sol->pop_back();
    }
}


vector<string> minTasksToCancelForNoConflict(string digits) {
    map<char, string> mapping;
    mapping['0'] = "0";
    mapping['1'] = "1";
    mapping['2'] = "abc";
    mapping['3'] = "def";
    mapping['4'] = "ghi";
    mapping['5'] = "jkl";
    mapping['6'] = "mno";
    mapping['7'] = "pqrs";
    mapping['8'] = "tuv";
    mapping['9'] = "wxyz";

    vector<string> res = {};
    string sol = "";

    if(digits.length() > 0)
        backtrack(&res, mapping, 0, &sol, digits.length(), digits);

    return res;
}

int main(){
    vector<string> a = minTasksToCancelForNoConflict("203");
    for(auto i : a){
        cout<<i<<" ";
    }

    return 0;
}