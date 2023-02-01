#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool login();
void registerUser();

void menu() {
  int choice;
  bool isLoggedIn;

  do {
    cout << "=========================================" << endl;
    cout << "Enter a choice from the menu " << endl;
    cout << "=========================================" << endl;
    cout << " 1: Create account " << endl;
    cout << " 2: Login " << endl;
    cout << " 3: Exit program " << endl;
    cout << "=========================================" << endl;
    cin >> choice;

    switch(choice) {
      case 1:
        registerUser();
      break;
      case 2:
        isLoggedIn = login();
        if(isLoggedIn) {
          cout << "Welcome to the application " << endl;
          return;
        }
      break;
      case 3:
        cout << "=========================================" << endl;
        cout << "Exiting the application.... " << endl;
        cout << "=========================================" << endl;
      break;
    }
  }while (choice != 3);
}

bool login() {
  string name, password, account_details;
  cin.ignore();
  cout << "=========================================" << endl;
  cout << "Enter your username: " << endl;
  getline(cin, name);
  cout << "Enter your password: " << endl;
  getline(cin, password);
  cout << "=========================================" << endl;

  fstream fs;
  fs.open("accounts.txt", ios::in);
  
  int i = 1;

  while(getline(fs, account_details)) {
    string username = account_details.substr(0, account_details.find(":"));
    string userpass = account_details.substr(account_details.find(":") + 1);

    if(username.compare(name) == 0 && userpass.compare(password) == 0)  {
      cout << "Hi " << name << endl;
      return true;
    }
  }
  cout << "Login attempt failed... " << endl;
  fs.close();
  return false;
}

void registerUser() {
  string name, password, userdetails;

  cin.ignore();
  cout << "=========================================" << endl;
  cout << "Enter your username: " << endl;
  getline(cin, name);
  cout << "Enter your password: " << endl;
  getline(cin, password);

  fstream fs;
  fs.open("accounts.txt", ios::in);
  while(getline(fs, userdetails)) {
    string username = userdetails.substr(0,userdetails.find(":"));
    if(username == name) {
      cout << "The username: " << name << " has already been taken" << endl;
      return;
    }
  }
  fs.close();
  fs.open("accounts.txt", ios::app);
  cout << name << ":" << password << endl;
  fs << name + ":" + password;
  fs << endl;
  fs.close();
  cout << "=========================================" << endl;
  cout << "Account created successfully " << endl;
}