#include <iostream>
#include <map>
using namespace std;

//This function returns the value of a Roman symbol
int romToint(string& s){
    map<char , int> Roman;
    Roman.insert(pair<char , int>('I',1));
    Roman.insert(pair<char , int>('V',5));
    Roman.insert(pair<char , int>('X',10));
    Roman.insert(pair<char , int>('L',50));
    Roman.insert(pair<char , int>('C',100));
    Roman.insert(pair<char , int>('D',500));
    Roman.insert(pair<char , int>('M',1000));
        
    int sum = 0;
    for (int i=0; i < s.length() ;i++){
        if(Roman[s[i]] < Roman[s[i+1]]){
            sum += Roman[s[i+1]]-Roman[s[i]];
            i++;
            continue;
        }
        sum += Roman[s[i]];
    }

    return sum;
}

int main(){
    string s = "III";
    cout << "Converting Roman numbers to integers:" << endl;
    cout << s << "->" << romToint(s) << endl;
}