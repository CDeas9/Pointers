/* Name: Callie Deas
# Date: 10/27/2018
# Class: CSC 1120
# Pledge: I have neither given nor received unauthorized aid on this
program.
# Description: This pointers program simulates an airline's account creation system. After the user inputs their
 information, the program tests to see if the password is a palindrome.
# Input: The user inputs a name, password, birthdate, and pin. They are also prompted to varify
 their information.
# Output:The program will display the users information once it is all inputed and whether the
 password is a palindrome or not.
 */

#include <iostream>
using namespace std;

/*
 * I created a struct passenger mostly as practice with structs, but also in case I wanted to do
 * more with the project, I could keep a file of individual passengers.
 */
struct Passenger{
    string name;
    string password;
    string birthday;
    string pin;
};

/*This function reverses the password using pointers. Then it checks to see if the original password and
 * the reverse are the same. If it is, it also prints the address to the password.
Parameters: string pointer to the password put in by the user.
 */
void check_Palindrome(string* password)
{
    string reverse;
    //going through the original password
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

/*
 * This function takes a sting and tests for characters. If it there is a character, it is added on
 * to a extra string. If it is an int, it is added to the new number which is returned and made the
 * birthday or pin.
 * Parameters: string num is the birthday or pin added by the user.
 * Returns a new number which is the number without characters.
 */
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

