#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

    string complexNumberMultiply(string num1, string num2) {
        int plus1 = num1.find('+');

        int real1 = stoi(num1.substr(0, plus1));
        int imag1= stoi(num1.substr(plus1 + 1, num1.size() - plus1 - 2));

         int plus2 = num2.find('+');

        int real2 = stoi(num2.substr(0, plus2));
        int imag2= stoi(num2.substr(plus2 + 1, num2.size() - plus2 - 2));

        //now apply formula 
        int real=(real1*real2)-(imag1*imag2);
        int imag=(real1*imag2)+(imag1*real2);
        return to_string(real)+"+"+to_string(imag)+"i";

    }


int main(){
    string num1="1+2i";
    string num2="1+2i";
    cout<<complexNumberMultiply(num1,num2)<<endl;
    
    return 0;
}