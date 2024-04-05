#include<bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

ll Rand(ll l, ll h)
{
      assert(l <= h);
      ll res = 0;
      for (int i = 0; i < 4; i++)
            res = (res << 15) ^ (rd() & ((1 << 15) - 1));
      return l + res % (h - l + 1);
}

class University;
class College;

class Course{
private:
      string courseName;
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
      void doAssignment(){
            for (int &score : assignment){
                  score = Rand(1LL,100LL);
            }
      }
      void takeTest(){
            for (int &score: test){
                  score = Rand(1LL,100LL);
            }
      }
      void takeExam(){
            for (int &score : exam){
                  score = Rand(1LL,100LL);
            }
      }
};

class Student{
protected:
      class StudentInfo
      {
      public:
            vector<vector<Course>> semester;
            string name;
            string dateOfBirth;
            int typ;
            StudentInfo(string _name, string _dateOfBirth, int _typ){
                  init(_name,_dateOfBirth,_typ);
                  return;
            }
            void init(string _name, string _dateOfBirth, int _typ){
                  name = _name;
                  dateOfBirth = _dateOfBirth;
                  typ = _typ;
                  if (typ == 1){
                        semester = vector<vector<Course>>(8,vector<Course>(4,Course(1)));
                  }
                  else semester = vector<vector<Course>>(4,vector<Course>(3,Course(0)));
            }
      };
      
      bool del(string s){
            auto listOfStudent = findStudents(s);
            if (sz(listOfStudent) == 0)   return 0;
            if (sz(listOfStudent) == 1){
                  for (auto i = students.begin(); i != students.end(); i++){
                        if ((*i)-> name == s)      {students.erase(i);     return 1;}
                  }
            }
            else {
                  cout << "Please choose No. the students you want to erase: \n";
                  cout << "No.\t\tName\t\tDate of Birth\n";
                  for (auto i : listOfStudent){
                        cout << i.first + 1 << "\t\t" << i .second -> name << "\t\t" << i.second -> dateOfBirth << '\n';
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
                        ans.push_back({i, new StudentInfo(students[i] -> name, students[i] -> dateOfBirth, students[i] -> typ)});
            }
            return ans;
      }
      vector<StudentInfo*> students;

public:
      Student() = default;
      void add(int typ){
            cout << "Please enter student's name: ";
            string name;      cin >> name;
            cout << "Please enter student's date of birth: ";
            string dateOfBirth;      cin >> dateOfBirth;
            StudentInfo *newStudent = new StudentInfo(name,dateOfBirth,typ);
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
                  cout << i + 1 << ".\t" << students[i] -> name << "\t\t" << students[i] -> dateOfBirth << '\n';
            }
      }
      // void findBest(){
      //       if (sz(students) == 0)    return void(cout<<"No student to find\n");
      //       cout << "Student(s) with the highest scores: \n";
      //       int maxScore = (*max_element(students.begin(), students.end(), [&](StudentInfo *a, StudentInfo *b) {
      //             return a -> score < b -> score;
      //       })) -> score;
      //       for (int i = 0; i < sz(students); i++){
      //             if (students[i] -> score == maxScore){
      //                   cout << i + 1 << ".\t" << students[i] -> name << "\t\t" << maxScore << '\n';
      //             }
      //       }
      // }
};

class UniStudent : public Student{
public:
      UniStudent() = default;
      void assignScore(int sem_id){
            while (1) {
                  cout << "Please choose the semester you want to assign (a number between 1 and 8): ";
                  cin >> sem_id;
                  if (sem_id <= 8 && sem_id >= 1)     break;
            }
            
            while (1){
                  string studentName;
                  cout << "Please enter the name of the student you want to assign: ";
                  cin >> studentName;
                  auto attempt = findStudents(studentName);
                  if (sz(attempt) != 0) break;
            }
            
            vector<pair<int,StudentInfo*>> listOfStudent;
            cout << "Please choose No. the students you want to assign score: \n";
            cout << "No.\t\tName\t\tDate of Birth\n";
            for (auto i : listOfStudent){
                  cout << i.first + 1 << "\t\t" << i .second -> name << "\t\t" << i.second -> dateOfBirth << '\n';
            }
            int pos;    cin >> pos;
      }
      
};

class CollegeStudent : public Student{
public:
      CollegeStudent() = default;
      void assignScore(int sem_id){
            while (1) {
                  cout << "Please choose the semester you want to assign (a number between 1 and 8): ";
                  cin >> sem_id;
                  if (sem_id <= 8 && sem_id >= 1)     break;
            }
            
            while (1){
                  string studentName;
                  cout << "Please enter the name of the student you want to assign: ";
                  cin >> studentName;
                  auto attempt = findStudents(studentName);
                  if (sz(attempt) != 0) break;
            }
            vector<pair<int,StudentInfo*>> listOfStudent;
            cout << "Please choose No. the students you want to assign score: \n";
            cout << "No.\t\tName\t\tDate of Birth\n";
            for (auto i : listOfStudent){
                  cout << i.first + 1 << "\t\t" << i .second -> name << "\t\t" << i.second -> dateOfBirth << '\n';
            }
            int pos;    cin >> pos;
      }     
};


class University{
private:
      string name;
      UniStudent students;
public:
      void addStudent(){
            return void(students.add(1));
      }
      void removeStudent(){
            return void(students.remove());
      }
      void displayStudent(){
            return void(students.display());
      }
      // void findBestStudent(){
      //       return void (students.findBest());
      // }      
}university;

class College{
private:
      string name;
      CollegeStudent students;
public:
      void addStudent(){
            return void(students.add(0));
      }
      void removeStudent(){
            return void(students.remove());
      }
      void displayStudent(){
            return void(students.display());
      }
      // void findBestStudent(){
      //       return void (students.findBest());
      // }      
}college;




int ask_type(){
      cout << "Please choose one of the school to manage\n";
      cout << "1.University\n2.College\n";
      int typ;    cin >> typ;
      return typ;
}

void ask(){
      cout << "\nPlease choose one of the above function\n" 
            << "---------------------------------------\n"
            << "(0) Exit the program\n"
            << "(1) Add a new student to the list\n" 
            << "(2) Display the list of all students\n" 
            //<< "(3) Find the students with highest score\n" 
            << "(4) Remove a student from the list\n" 
            << "(5) Assign score to the students\n"
            << "---------------------------------------\n";
}

int main(){
      srand(time(NULL));
      while (1){
            int option;
            int typ = ask_type();
            ask();
            cin >> option;
            if (option == 0)  return 0;
            else{
                  if (option == 1 && typ)  university.addStudent();
                  if (option == 2 && typ)  university.displayStudent();
                  //if (option == 3)  university.findBestStudent();
                  if (option == 4 && typ)  university.removeStudent(); 
                  
                  if (option == 1 && !typ)  college.addStudent();
                  if (option == 2 && !typ)  college.displayStudent();
                  //if (option == 3 && !typ)  university.findBestStudent();
                  if (option == 4 && !typ)  college.removeStudent(); 
            }
      }
}