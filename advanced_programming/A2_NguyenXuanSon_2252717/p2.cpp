#include<bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()

struct StudentList{
      vector<string> students;
      vector<int> scores;
      StudentList() = default;
      void add(){
            cout << "Please enter student's name: \n";
            string name;      cin >> name;
            cout << "Please enter student's score: \n";
            int score;        cin >> score;
            students.push_back(name);
            scores.push_back(score);
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
            if (sz(students) == 0)  return void(cout<<"No student to display!\n");
            cout << "List of students\n" ;
            cout << "\tName\t\tScore\n"; 
            for (int i = 0; i < sz(students); i++){
                  cout << i + 1 << ".\t" << students[i] << "\t\t" << scores[i] << '\n';
            }
      }
      void findBest(){
            if (sz(scores) == 0)    return void(cout<<"No student to find\n");
            cout << "Student(s) with the highest scores: \n";
            int maxScore = *max_element(scores.begin(), scores.end());
            for (int i = 0; i < sz(scores); i++){
                  if (scores[i] == maxScore){
                        cout << i + 1 << ".\t" << students[i] << "\t\t" << maxScore << '\n';
                  }
            }
      }
}students;

void ask(){
      cout << "\nPlease choose one of the above function\n" 
            << "---------------------------------------\n"
            << "(0) Exit the program\n"
            << "(1) Add new student to the list\n" 
            << "(2) Display the list of all students\n" 
            << "(3) Find the students with highest score\n" 
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
                  if (option == 3)  students.findBest();
            }
      }
}