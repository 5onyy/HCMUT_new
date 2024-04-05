#include<bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()

struct StudentList{
      vector<string> students;
      StudentList() = default;
      void add(){
            string name;
            cout << "Please enter student's name: \n";
            cin >> name;
            students.push_back(name);
      }
      void remove(){
            string name;
            cout << "Please enter the student's name to delete: ";
            cin >> name;
            if (del(name))    cout << "Delete sucessfully!\n";
            else cout << "Can't find the student with the given name!\n";
      }
      bool del(string s){
            for (auto i = students.begin(); i != students.end(); i++){
                  if (*i == s)      {students.erase(i);     return 1;}
            }
            return 0;
      }
      void display(){
            cout << "List of students\n" ;
            for (int i = 0; i < sz(students); i++){
                  cout << i + 1 << ". " << students[i] << '\n';
            }
      }
}students;

void ask(){
      cout << "\nPlease choose one of the above function\n" 
            << "---------------------------------------\n"
            << "(0) Exit the program\n"
            << "(1) Add new student to the list\n" 
            << "(2) Display the list of all students\n" 
            << "(3) Remove the student from the list\n" 
            << "---------------------------------------\n";
}

int main(){
      while (1){
            int option;
            ask();
            cin >> option;
            if (option == 0)  return 0;
            else{
                  if (option == 1)  students.add();
                  if (option == 2)  students.display();
                  if (option == 3)  students.remove();
            }
      }
}