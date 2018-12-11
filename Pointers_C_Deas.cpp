#include <iostream>
using namespace std;

struct Passenger{
    string name;
    string password;
    string birthday;
    string pin;
};

void check_Palindrome(string* password)
{
    string reverse;
    string oPassword = *password;
    string *p = NULL;
    p = password;
    for (int i = int(oPassword.length() - 1); i >= 0; i--) {
        reverse += oPassword[i];
    }
    if(reverse == oPassword) {
        cout << "Your password is a palindrome" << endl;
        cout << "The address to your password is " << p << endl;
    }else {
        cout << "Your password " << oPassword << " is not a palindrome." << endl;
    }
}

string is_Digit(string num){
    string other;
    string newNum;
    for (int i = 0; i <= num.length(); i++){
        if (isdigit(num[i]) != 0) {
            newNum += num[i];
        } else
            other += num[i];
    }
    return newNum;
}

int main(){
    string name;
    bool correct;
    string password;
    string birthday;
    string pin;
    string ans;
    Passenger account;
    while(!correct) {
        cout << "Welcome to Deas Airlines!" << endl;
        cout << "Enter your name for the account: " << endl;
        getline(cin, name);
        account.name = name;
        cout << "Enter a password: " << endl;
        getline(cin, password);
        account.password = password;
        cout << "Enter your birthday numerically: " << endl;
        getline(cin, birthday);
        //take out characters in the date/pin if the user added them
        account.birthday = is_Digit(birthday);
        cout << "Enter your pin: " << endl;
        getline(cin, pin);
        account.pin = is_Digit(pin);
        cout << endl;
        cout << "Account name: " << account.name << endl;
        cout << "Account password: " << account.password << endl;
        cout << "Account birthday: " << account.birthday << endl;
        cout << "Account pin: " << account.pin << endl;
        cout << "Is this correct? Yes or No: ";
        getline(cin, ans);
        if (ans == "Yes"){
            correct = true;
            cout << "Your account has been created." << endl;
        } else {
            correct = false;
        }
    }
    string* pass = &account.password;
    check_Palindrome(pass);
    cout << "Would you like to add another account? Yes or No" << endl;
    getline(cin, ans);
    if(ans == "Yes"){
        main();
    }else {
        cout << "Thank you. Have a great day!" << endl;
    }
};

