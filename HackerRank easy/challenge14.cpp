#include<bits/stdc++.h>

using namespace std;

int isAnagram(string s, string t) {
    int sLength = s.length();
    int tLength = t.length();
    
    if(sLength != tLength){
        return 0;
    }
    
    map<char, int> sComp;
    map<char, int> tComp;
    
    
    for(char i : s){
        if(sComp.count(i) == 0){
            sComp[i] = 1;
        }else{
            ++sComp[i];
        }
    }
    
    for(char i : t){
        if(sComp.count(i) == 0){
            return 0;
        }
        
        if(tComp.count(i) == 0){
            tComp[i] = 1;
        }else{
            ++tComp[i];
        }
    }
    
    for(char i : s){        
        if(sComp[i] != tComp[i]){
            return 0;
        }
    }
    
    return 1;
}

int main(){
    cout<<isAnagram("listen", "silten");

    return 0;
}