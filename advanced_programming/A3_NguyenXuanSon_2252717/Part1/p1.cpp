#include<bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

/*-------------------------------FOR DEBUGGING --------------------------------------*/
#define DEBUG(X) { auto _X = (X); std::cout << "L" << __LINE__ << ": " << #X << " = " << (_X) << std::endl; }
#define db(x) { std::cout << "[" << #x << " = "; std::cout << (x) << "] "; }
#define debug(x) { std::cout << "[" << #x << " = "; std::cout << (x) << "] " << endl; }

// For printing std::pair, container, etc.
template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {
    return out << '(' << p.first << ", " << p.second << ')';
}

template<class Con, class = decltype(begin
(std::declval<Con>()))>
typename std::enable_if < !std::is_same<Con, std::string>::value, std::ostream& >::type
operator << (std::ostream& out, const Con& con) {
    out << '{';
    for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
        out << (it == beg ? "" : ", ") << *it;
    }
    return out << '}';
}
template<size_t i, class T> std::ostream& print_tuple_utils(std::ostream& out, const T& tup) {
    if (i == std::tuple_size<T>::value) return out << ")";
    else return print_tuple_utils < i + 1, T > (out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U> std::ostream& operator << (std::ostream& out, const std::tuple<U...>& t) {
    return print_tuple_utils<0, std::tuple<U...>>(out, t);
}
/*-----------------------------------------------------------------------------------*/

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
    void print() {
        db(assignment);
        cout << '\n';
        db(test);
        cout << '\n';
        db(exam);
        cout << '\n';
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
        while (1) {
            if (sz(students) == 0)  return void(cout<<"No student to display!\n");
            cout << "List of students\n" ;
            cout << "\tName\t\Date of Birth\n"; 
            for (int i = 0; i < sz(students); i++){
                    cout << i + 1 << ".\t" << students[i] -> name << "\t\t" << students[i] -> dateOfBirth << '\n';
            }
            cout << "--------------------------------------------\n";
            cout << "Choose the student you want to view score (Choose the number from 1 to "<< sz(students) << ")" << "\n";
            for (int i = 0; i < sz(students); i++){
                cout << i + 1 << ".\t" << students[i] -> name << "\t\t" << students[i] -> dateOfBirth << '\n';
            }
            cout << "Or -1 to quit display menu.\n";
            int pos;    
            while (1) {
                cin >> pos;
                if (pos == -1)  return;
                if (!(pos >= 1 && pos <= sz(students)))     
                    {cout << "Retry!\n"; continue;}
                else break;
            }
            cout << "Student: " << students[pos - 1] -> name << "\n";
            cout << "--------------------------------------------\n";
            int cnt = 1, cnt_course = 1;
            for (auto sem : students[pos - 1]->semester) {
                cout << "Semester " << cnt << "\n";
                cnt_course = 1;
                for (auto course : sem){
                    cout << "Course " << cnt_course << '\n';
                    course.print();
                    cnt_course++;
                }
                cnt++;
                cout << "--------------------------------------------\n";
            }
        }
    }
};

class UniStudent : public Student{
public:
    UniStudent() = default;
    void assignScore(){
        if (sz(students) == 0)  return void(cout << "No students to assign scores! \n");
        int sem_id;
        while (1) {
                cout << "Please choose the semester you want to assign (a number between 1 and 8): ";
                cin >> sem_id;
                if (sem_id <= 8 && sem_id >= 1)     break;
        }
        for (auto &student : students) {
            for (auto &course : student -> semester[sem_id - 1]) {
                course.doAssignment();
                course.takeExam();
                course.takeTest();
            }
        }
    }
};

class CollegeStudent : public Student{
public:
    CollegeStudent() = default;
    void assignScore(){
        if (sz(students) == 0)  return void(cout << "No students to assign scores! \n");
        int sem_id;
        while (1) {
                cout << "Please choose the semester you want to assign (a number between 1 and 4): ";
                cin >> sem_id;
                if (sem_id <= 4 && sem_id >= 1)     break;
        }
        for (auto &student : students) {
            for (auto &course : student -> semester[sem_id - 1]) {
                course.doAssignment();
                course.takeExam();
                course.takeTest();
            }
        }
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
    void assignScore() {
        return void(students.assignScore());
    }  
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
    void assignScore() {
        return void(students.assignScore());
    }
}college;


int ask_type(){
    cout << "Please choose one of the school to manage\n";
    cout << "0.Quit\n1.University\n2.College\n";
    int typ;    cin >> typ;
    return typ;
}

void ask(){
    cout << "\nPlease choose one of the above function\n" 
        << "---------------------------------------\n"
        << "(0) Exit the program\n"
        << "(1) Add a new student to the list\n" 
        << "(2) Display the list of all students\n" 
        << "(3) Remove a student from the list\n" 
        << "(4) Assign score to the students\n"
        << "---------------------------------------\n";
}

int main(){
    srand(time(NULL));
    while (1){
        int option;
        int typ = ask_type();
        if (typ == 0)      return 0;
        ask();
        cin >> option;
        if (option == 0)  return 0;
        else{
                if (option == 1 && typ == 1)  university.addStudent();
                if (option == 2 && typ == 1)  university.displayStudent();
                if (option == 3 && typ == 1)  university.removeStudent(); 
                if (option == 4 && typ == 1)  university.assignScore(); 
                
                if (option == 1 && typ == 2)  college.addStudent();
                if (option == 2 && typ == 2)  college.displayStudent();
                if (option == 3 && typ == 2)  college.removeStudent(); 
                if (option == 4 && typ == 2)  college.assignScore();
        }
    }
}