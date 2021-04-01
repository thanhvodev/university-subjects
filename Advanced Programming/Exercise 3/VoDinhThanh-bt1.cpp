#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Faculty
{
private:
    string ten;

public:
    Faculty() {}
    Faculty(string ten) { setTen(ten); }
    void setTen(string ten)
    {
        this->ten = ten;
    }
    string getTen() { return ten; }
    ~Faculty() {}
};

class Lecturer
{
private:
    Faculty *falculty;
    string ten;

public:
    Lecturer() {}
    Lecturer(string ten, string falName)
    {
        setFaculty(falName);
        setTen(ten);
    }
    void setFaculty(string falName)
    {
        falculty = new Faculty("falName");
    }
    void setTen(string ten)
    {
        this->ten = ten;
    }
    string getTen() { return ten; }
    ~Lecturer() { delete falculty; }
};

class Classroom
{
private:
    string ten;

public:
    Classroom() {}
    Classroom(string ten) { setTen(ten); }
    void setTen(string ten)
    {
        this->ten = ten;
    }
    string getTen() { return ten; }
    ~Classroom() {}
};

class Subject
{
private:
    string ten;
    string *lecturerList;
    Classroom *classroom;

public:
    Subject() {}
    Subject(string tenMon, string *&lecNameL, string className)
    {
        setClassroom(className);
        this->lecturerList = lecNameL;
        setTen(tenMon);
    }
    void setClassroom(string classroomName)
    {
        classroom = new Classroom(classroomName);
    }
    void setTen(string ten)
    {
        this->ten = ten;
    }
    string getTen() { return ten; }
    ~Subject() { delete classroom; }
};

class Student
{
private:
    int id;
    string tenSV;
    Faculty *faculty;
    string *subjectList;

public:
    Student() {}
    Student(int id, string tenSV, string falName, string *&subjectList)
    {
        setId(id);
        setTenSV(tenSV);
        setFaculty(falName);
        this->subjectList = subjectList;
    }
    void setId(int id) { this->id = id; }
    int getId() { return id; }
    void setTenSV(string tenSV) { this->tenSV = tenSV; }
    string getTenSV() { return tenSV; }
    void setFaculty(string falName) { faculty = new Faculty(falName); }
    ~Student()
    {
        delete faculty;
        delete subjectList;
    }
};

void inputFaculty(vector<Faculty> &facultyList, int numberOfFaculty)
{
    for (int i = 0; i < numberOfFaculty; i++)
    {
        cout << "Input detail for faculty " << i + 1 << ": " << endl;
        cout << "Input name of faculty: ";
        string falName = "";
        cin >> falName;
        facultyList.push_back(Faculty(falName));
    }
}

void inputLecturer(vector<Lecturer> &lecList, int numOfLec)
{
    for (int i = 0; i < numOfLec; i++)
    {
        cout << "Input detail for lecturer " << i + 1 << ": " << endl;
        string nameLec = "";
        string nameFal = "";
        cout << "Input name of lecturer: ";
        cin >> nameLec;
        cout << "Input name of faculty: ";
        cin >> nameFal;
        lecList.push_back(Lecturer(nameLec, nameFal));
    }
}

void inputClassroom(vector<Classroom> &classList, int numClass)
{
    for (int i = 0; i < numClass; i++)
    {
        cout << "Input detail for classroom " << i + 1 << ": " << endl;
        string nameClass = "";
        cout << "Input name of classroom: ";
        cin >> nameClass;
        classList.push_back(Classroom(nameClass));
    }
}

void inputSubject(vector<Subject> &subList, int numSub)
{
    for (int i = 0; i < numSub; i++)
    {
        cout << "Input detail for subject " << i + 1 << ": " << endl;
        string nameSub = "";
        cout << "Input name of subject: ";
        cin >> nameSub;
        string nameClass = "";
        cout << "Input name of classroom: ";
        cin >> nameClass;
        ///////////////////
        cout << "Input number of lecturer of subject " << i + 1 << ": ";
        int numLec = 0;
        cin >> numLec;
        string *lecList = new string[numLec];
        for (int j = 0; j < numLec; j++)
        {
            string lec = "";
            cout << "Input lecturer " << j + 1 << ": ";
            cin >> lec;
            lecList[j] = lec;
        }
        subList.push_back(Subject(nameSub, lecList, nameClass));
        lecList = NULL;
    }
}

void inputStudent(vector<Student> &stuList, int numStu)
{
    for (int i = 0; i < numStu; i++)
    {
        cout << "Input detail for student " << i + 1 << ": " << endl;
        int id = 0;
        cout << "Input id of student: ";
        cin >> id;
        string nameStu = "";
        cout << "Input name of student: ";
        cin >> nameStu;
        string nameFal = "";
        cout << "Input name of faculty: ";
        cin >> nameFal;
        cout << "Input number of subject of student " << i + 1 << ": ";
        int numSub = 0;
        cin >> numSub;
        string *subList = new string[numSub];
        for (int j = 0; j < numSub; j++)
        {
            string sub = "";
            cout << "Input subject " << j + 1 << ": ";
            cin >> sub;
            subList[j] = sub;
        }
        stuList.push_back(Student(id, nameStu, nameFal, subList));
        subList = NULL;
    }
}

void checkCondition(int num)
{
    if (num > 100)
    {
        cout << "Too much";
        exit(0);
    }
}

int main()
{
    int numberOfFaculty = 0;
    cout << "How many faculty ? ";
    cin >> numberOfFaculty;
    checkCondition(numberOfFaculty);

    vector<Faculty> facultyList;
    inputFaculty(facultyList, numberOfFaculty);

    int numberOfLecturer = 0;
    cout << "How many lecturers ? ";
    cin >> numberOfLecturer;
    checkCondition(numberOfLecturer);

    vector<Lecturer> lecturerList;
    inputLecturer(lecturerList, numberOfLecturer);

    int numClass = 0;
    cout << "How many classrooms ? ";
    cin >> numClass;
    checkCondition(numClass);

    vector<Classroom> classroomList;
    inputClassroom(classroomList, numClass);

    int numSub = 0;
    cout << "How many subjects ? ";
    cin >> numSub;
    checkCondition(numSub);

    vector<Subject> subjectList;
    inputSubject(subjectList, numSub);

    int numStu = 0;
    cout << "How many students ? ";
    cin >> numStu;
    checkCondition(numStu);

    vector<Student> stuList;
    inputStudent(stuList, numStu);
}