#include<bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()

class University;

class Student{
private:
      class StudentInfo
      {
      public:
            string name;
            int score;
            string dateOfBirth;
            StudentInfo() = default;
            StudentInfo(string _name, int _score) : name(_name), score(_score){};
      };
      
      bool del(string s){
            auto listOfStudent = findStudents(s);
            if (sz(listOfStudent) == 1){
                  for (auto i = students.begin(); i != students.end(); i++){
                        if ((*i)-> name == s)      {students.erase(i);     return 1;}
                  }
            }
            else {
                  cout << "Please choose No. the students you want to erase: \n";
                  cout << "No.\t\tName\t\tScore\n";
                  for (auto i : listOfStudent){
                        cout << i.first + 1 << "\t\t" << i .second -> name << "\t\t" << i.second -> score << '\n';
                  }
                  int pos;    cin >> pos;
                  for (auto i = students.begin(); i != students.end(); i++){
                        if (i - students.begin() + 1 == pos){
                              students.erase(i);      return 1;
                        }
                  }
            }
            return 0;
      }
      
      vector<pair<int,StudentInfo*>> findStudents(string name){
            vector<pair<int,StudentInfo*>> ans;
            for (int i = 0; i < sz(students); i++){
                  if (students[i] -> name == name)
                        ans.push_back({i, new StudentInfo(students[i] -> name, students[i] -> score)});
            }
            return ans;
      }
      vector<StudentInfo*> students;

public:
      Student() = default;
      void add(){
            cout << "Please enter student's name: ";
            string name;      cin >> name;
            cout << "Please enter student's score: ";
            int score;        cin >> score;
            StudentInfo *newStudent = new StudentInfo(name,score);
            students.push_back(newStudent);
      }
      void remove(){
            string name;
            cout << "Please enter the student's name to delete: ";
            cin >> name;
            if (del(name))    cout << "Delete sucessfully!\n";
            else cout << "Can't find the student with the given name!\n";
      }
      void display(){
            if (sz(students) == 0)  return void(cout<<"No student to display!\n");
            cout << "List of students\n" ;
            cout << "\tName\t\tScore\n"; 
            for (int i = 0; i < sz(students); i++){
                  cout << i + 1 << ".\t" << students[i] -> name << "\t\t" << students[i] -> score << '\n';
            }
      }
      void findBest(){
            if (sz(students) == 0)    return void(cout<<"No student to find\n");
            cout << "Student(s) with the highest scores: \n";
            int maxScore = (*max_element(students.begin(), students.end(), [&](StudentInfo *a, StudentInfo *b) {
                  return a -> score < b -> score;
            })) -> score;
            for (int i = 0; i < sz(students); i++){
                  if (students[i] -> score == maxScore){
                        cout << i + 1 << ".\t" << students[i] -> name << "\t\t" << maxScore << '\n';
                  }
            }
      }
};

class University{
private:
      string name;
      Student students;
public:
      void addStudent(){
            return void(students.add());
      }
      void removeStudent(){
            return void(students.remove());
      }
      void displayStudent(){
            return void(students.display());
      }
      void findBestStudent(){
            return void (students.findBest());
      }      
}university;

class Course{
private:
      vector<int> assignment;
      vector<int> test;
      vector<int> exam;
public:
      Course(int typ){
            initCourse(typ);
            return;
      }
      void initCourse(int typ){
            if (typ){   // 1 : UniStudent
                  assignment.resize(3);
                  test.resize(2);
                  exam.resize(1);
            }
            else{       // 2 : CollegeStudent
                  assignment.resize(3);
                  test.resize(1);
                  exam.resize(1);
            }
      }
};

class UniStudent : public Student{
private:
      vector<Course> semester;
public:
      UniStudent() : semester(8,Course(1)) {};
};

class CollegeStudent : public Student{
private:
      vector<Course> semester;
public:
      CollegeStudent() : semester(4,Course(0)) {};      
};

void ask(){
      cout << "\nPlease choose one of the above function\n" 
            << "---------------------------------------\n"
            << "(0) Exit the program\n"
            << "(1) Add a new student to the list\n" 
            << "(2) Display the list of all students\n" 
            << "(3) Find the students with highest score\n" 
            << "(4) Remove a student from the list\n" 
            << "---------------------------------------\n";
}

int main(){
      while (1){
            int option;
            ask();
            cin >> option;
            if (option == 0)  return 0;
            else{
                  if (option == 1)  university.addStudent();
                  if (option == 2)  university.displayStudent();
                  if (option == 3)  university.findBestStudent();
                  if (option == 4)  university.removeStudent();
            }
      }
}