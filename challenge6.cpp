#include<bits/stdc++.h>

using namespace std;

bool areBracketsProperlyMatched(string code_snippet) {
    stack<char> brackets;

    for(char i : code_snippet){
        if(i == '(' || i == '[' || i == '{'){
            brackets.push(i);
        }

        if(i == ')' || i == ']' || i == '}'){
            if(brackets.empty()){
                return false;
            }

            char top = brackets.top();
            brackets.pop();
            if(i == ')' && top != '(' || 
               i == ']' && top != '[' || 
               i == '}' && top != '{'){

                return false;
            }
        }

    }

    return brackets.empty();
}

int main(){
    cout<<areBracketsProperlyMatched("(((((([[[[[[{{{{}}}}]]]]]]))))))")<<endl;
    cout<<areBracketsProperlyMatched("(((((([[[[[[{{{{}}}}]]]]))))))");

    return 0;
}