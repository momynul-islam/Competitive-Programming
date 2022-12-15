#include <bits/stdc++.h>

using namespace std;

int main(){

    char str[1000];
    cin.getline(str,1000);
    int space = 0;
    for(int i=0; str[i]!='\0'; i++){
        if(str[i] == ' ')
            space ++;
    }

    int index = strlen(str) + (2*space);
    str[index] = '\0';

    for(int i=strlen(str); i>=0; i--){
        if(str[i] == ' '){
            str[index--] = '0';
            str[index--] = '2';
            str[index--] = '%';
            //index -= 3;
        }
        else
            str[index--] = str[i];
    }

    cout << str << endl;

    return 0;
}
