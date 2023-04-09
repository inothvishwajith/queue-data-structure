#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int marks;
    int fronts;
    int rear;
    int maxsize;
public:
    int highestScience;
    int highestMath;
    string name;
    string namee;
    int index;
    string *n; //student
    string *s; //subject
    int *m; //marks
    int *e; //atend exam or not
    Student(int j);
    bool isFull();
    bool isEmpty();
    void dequeue();
    void enqueue(int a1);
    void Display_menu();
    void Insertstudent();
    void DeleteStudent();
    int searchStudent(string name);
    void DisplayRelevantStudent();
    void NotAttendStudent();
    void DisplayHighestMarks();
    void DisplayLowestMarks();
    int getTotalStudents();
    void DisplayHighestMarksStudent();
    void DisplayLowestMarksStudent();
};

Student::Student(int j)
{
    maxsize = j;
    n = new string[maxsize];
    fronts = 0;
    rear = -1;
    s = new string[maxsize];
    fronts = 0;
    rear = -1;
    m = new int[maxsize];
    fronts = 0;
    rear = -1;
    e = new int[maxsize];
    fronts = 0;
    rear = -1;
    highestScience = -1;
    highestMath = -1;

}

void Student::enqueue(int a1){
    if(isFull()){
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Que is Full!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}
}

void Student::dequeue(){
  if(isEmpty()){
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Que is Empty!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  }
  else{
    cout << "Removed student " << n[fronts] << " from the queue" << endl;
    fronts++;
    if(fronts > rear){
      fronts=0;
      rear=-1;
    }
  }
}


bool Student::isEmpty(){
  if(rear == -1){
    return true;
  }
  else{
    return false;
  }
}

bool Student::isFull(){
 if(rear == maxsize-1){
    return true;
 }
 else{
   return false;
 }
}

void Student::Insertstudent()
{
    if(isFull()){
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Que is Full!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    }
    else{
        rear=0;
        while(rear <= maxsize-1){
            cout << "Enter name of student: ";
            cin >> n[rear];
            cout << "Enter subject of student (type ""s"" for science & ""m"" for maths): ";
            cin >> s[rear];
            cout << "student attend exam or not(type if attend = 1 or not = 0): ";
            cin >> e[rear];
            if(e[rear] == 1){
            if(s[rear] == "m"){
                cout << "Enter marks of maths student: ";
                cin >> m[rear];
            }
            else if(s[rear] == "s"){
                cout << "Enter marks of science student: ";
                cin >> m[rear];
            }}
            else{
                m[rear]= 0;
            }
            rear++;
        }
    }
}

void Student::DeleteStudent() {
    string gg;
    if (isEmpty()){
       cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Student not found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
    }
    else{
    gg = n[fronts];
    n[fronts]= n[++fronts];
    s[fronts]= s[++fronts];
    m[fronts]= m[++fronts];
    e[fronts]= e[++fronts];

    cout << "Student " << gg << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Delete Sucessfully!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
    }

}


int Student::searchStudent(string name) {
    for (int i = 0; i <= rear; i++) {
        if (n[i] == name) {
            return i;
        }
    }
    return -1; // student not found
}


void Student::DisplayRelevantStudent() {
    char subject;
    cout << "Enter subject to display relevant students (type ""s"" for science & ""m"" for maths): ";
    cin >> subject;

    string subject_str(1, subject); // Convert char to string

    bool found = false;
    for (int i = fronts; i <= rear; i++) {
        if (s[i] == subject_str) {
            found = true;
            cout << "Name: " << n[i] << endl;
        }
    }

    if (!found) {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!No students found for the selected subject!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }
}

void Student::NotAttendStudent(){
    bool found = false;
    for (int i = fronts; i <= rear; i++) {
        if (e[i] == 0) {
            found = true;
            cout << "Name: " << n[i] << ", Subject:  " << s[i] << "not attend "<< endl;
        }
    }
}


void Student::DisplayHighestMarks() {
  int highestScience = -1;
int highestMath = -1;

for (int i = 0; i < maxsize; i++){
    if (s[i] == "m" && e[i] == 1 && m[i] > highestMath){
        highestMath = m[i];
        name = n[i];
    }
    else if (s[i] == "s" && e[i] == 1 && m[i] > highestScience){
        highestScience = m[i];
        namee = n[i];
    }
}

cout << "Highest Maths marks: " << highestMath << ", Student name: " << name << endl;
cout << "Highest Science marks: " << highestScience << ", Student name: " << namee << endl;
}


void Student::DisplayLowestMarks() {
int lowestMath = m[0];
int lowestScience = m[0];
for(int i = 0; i < maxsize; i++){
  if(s[i] == "m"){
    if(m[i] < lowestMath){
      lowestMath = m[i];
      name = n[i];
    }
  }
  else if(s[i] == "s"){
    if(m[i] < lowestScience){
      lowestScience = m[i];
      namee = n[i];
    }
  }

}
cout << "The lowest marks for Maths is: " << lowestMath << ", Student name: " << name << endl;
cout << "The lowest marks for Science is: " << lowestScience << ", Student name: " << namee << endl;
}

int Student::getTotalStudents() {
    if (isEmpty()) {
        return 0;
    } else {
        return rear + 1;
    }
}

void Student::DisplayHighestMarksStudent() {
    int highestScience = -1;
    int highestMath = -1;
    string Hi_math_student = "";
    string Hi_science_student = "";

    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    for (int i = 0; i <= rear; i++) {
        if (s[i] == "s" && m[i] > highestScience) {
            highestScience = m[i];
            Hi_science_student= n[i];
        }
        else if (s[i] == "m" && m[i] > highestMath) {
            highestMath = m[i];
            Hi_math_student = n[i];
        }
    }

    cout << "Highest marks for Science: " << highestScience << " (Student " << Hi_science_student << ")" << endl;
    cout << "Highest marks for Math: " << highestMath << " (Student " << Hi_math_student << ")" << endl;
}


void Student::DisplayLowestMarksStudent() {
    int lowest_math_marks = 100;
    int lowest_science_marks = 100;
    string lowest_math_student = "";
    string lowest_science_student = "";

    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    for (int i = 0; i <= rear; i++) {
        if (s[i] == "m" && m[i] < lowest_math_marks) {
            lowest_math_marks = m[i];
            lowest_math_student = n[i];
        }
        else if (s[i] == "s" && m[i] < lowest_science_marks) {
            lowest_science_marks = m[i];
            lowest_science_student = n[i];
        }
    }

    cout << "Lowest marks for Math: " << lowest_math_marks << " (Student " << lowest_math_student << ")" << endl;
    cout << "Lowest marks for Science: " << lowest_science_marks << " (Student " << lowest_science_student << ")" << endl;
}

void Student::Display_menu() {
    cout << "1. Add New Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Display Next Student" << endl;
    cout << "4. Search Student" << endl;
    cout << "5. Display Relevant Student is for which Subject" << endl;
    cout << "6. Display Highest Marks for Science and Math" << endl;
    cout << "7. Display Lowest Marks for Science and Math" << endl;
    cout << "8. Display Total Number of Students" << endl;
    cout << "9. Display whose not attend to exam" << endl;
    cout << "10. Display Lowest Marks Student for Math and Science" << endl;
    cout << "11. Display Highest Marks of Student for Math and Science" << endl;
    cout << "12. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    cout<<"=======================================================================================================================" << endl;
    cout<<"---------------------------------------------------------------AYUBOWAN!-----------------------------------------------" << endl;
    cout<<"=======================================================================================================================" << endl;
    cout<<"-------------------------------------------------------------Admin Login------------------------------------------------" << endl;
    string username = "admin";
    string password = "admin";
    string input_username, input_password;

    cout << "=================Username: ";
    cin >> input_username;

    cout << "=================Password: ";
    cin >> input_password;

    if (input_username == username && input_password == password) {
        cout << "==================================================Login successful!=========a==========================================" << endl;
        int quesize;
        int choice;
        cout << "How many student you think to insert for queue:" << endl;
        cin >> quesize;
        Student s(quesize);
        while (true) {
        s.Display_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                s.Insertstudent();
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Student added to the queue!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                break;
            case 2:
                s.DeleteStudent();
                break;
            case 3:
                cout << "Marks: " << endl;
                break;
            case 4:

                cout << "Enter name of student to search for: ";
                cin >> s.name;
                s.index = s.searchStudent(s.name);
                if (s.index == -1) {
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Student not found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                } else {
                    cout << "Name: " << s.n[s.index] << endl;
                    cout << "Subject: " << s.s[s.index] << endl;
                    if (s.e[s.index] == 1){
                       cout << "Marks: " << s.m[s.index] << endl;
                    }
               }
                break;
            case 5:
                s.DisplayRelevantStudent();
                break;
            case 6:
                 s.DisplayHighestMarks();
                break;
            case 7:
                s.DisplayLowestMarks();
                break;
            case 8:
                cout << "Total number of students: " << s.getTotalStudents() << endl;
                break;
            case 9:
                s.NotAttendStudent();
                break;
            case 10:
                s.DisplayHighestMarksStudent();
                break;
            case 11:
                s.DisplayLowestMarksStudent();
                break;
            case 12:
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Thanks for using us!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                break;
        }
        }

    } else {
        cout << "Invalid username or password. Please try again." << endl;
}

return 0;
}
