#include <bits/stdc++.h>

using namespace std;

void printPermo(string input,int i){
    //base case
    if(input[i] == '\0'){
        cout << input << endl;
        return;
    }
    //rec case
    for(int j=i; j<input.size(); j++){
        swap(input[j],input[i]);
        printPermo(input,i+1);
        swap(input[j],input[i]);
    }

}

int main(){

    string input;
    cin >> input;

    printPermo(input,0);

    return 0;
}
