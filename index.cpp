
#include<bits/stdc++.h>
using namespace std;

struct Date {
  int day;
  int month;
  int year;
};

map<string, Date> birthdays;

void AddBirthday() {
  string name;
  Date birthday;
  cout << "Enter name: ";
  cin >> name;
  cout << "Enter day: ";
  cin >> birthday.day;
  cout << "Enter month: ";
  cin >> birthday.month;
  cout << "Enter year: ";
  cin >> birthday.year;
  birthdays[name] = birthday;
  cout << "Birthday added for " << name << endl;
}

void EditBirthday() {
  string name;
  cout << "Enter name: ";
  cin >> name;
  if (birthdays.count(name) == 0) {
    cout << "No such person found" << endl;
    return;
  }
  Date birthday;
  cout << "Enter day: ";
  cin >> birthday.day;
  cout << "Enter month: ";
  cin >> birthday.month;
  cout << "Enter year: ";
  cin >> birthday.year;
  birthdays[name] = birthday;
  cout << "Birthday updated for " << name << endl;
}

void FindBirthday() {
  string name;
  cout << "Enter name: ";
  cin >> name;
  if (birthdays.count(name) == 0) {
    cout << "No such person found" << endl;
    return;
  }
  auto birthday = birthdays[name];
  cout << name << " was born on " << birthday.day << "/" << birthday.month << "/" << birthday.year << endl;
}

void ViewMonthlyBirthdays() {
  int month;
  cout << "Enter month: ";
  cin >> month;
  cout << "People born in month " << month << ":" << endl;
  for (const auto& pair: birthdays) {
    const string& name = pair.first;
    const Date& birthday = pair.second;
    if(birthday.month == month)
      cout << name << endl;
  }
}

int main() {
  int choice = 0;
  while (choice != 5) {
    cout << "1. Add birthday" << endl;
    cout << "2. Edit birthday" << endl;
    cout << "3. Find birthday" << endl;
    cout << "4. View monthly birthdays" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            AddBirthday();
            break;
        case 2:
            EditBirthday();
            break;
        case 3:
            FindBirthday();
            break;
        case 4:
            ViewMonthlyBirthdays();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice" << endl;
            exit(1);
        }
    }
    return 0;
}