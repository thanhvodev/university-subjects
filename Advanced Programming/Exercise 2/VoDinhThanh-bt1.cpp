#include <iostream>
#include <vector>

using namespace std;

class Grade
{
private:
  string nameOfCourse;
  int mark;

public:
  Grade() {}
  Grade(string naCor, int mar)
  {
    setMark(mar);
    setNameOfCourse(naCor);
  }
  void setMark(int mar)
  {
    mark = mar;
  }
  void setNameOfCourse(string na)
  {
    nameOfCourse = na;
  }
  int getMark() { return mark; }
};
class Student
{
private:
  int studentID;
  string name;
  vector<Grade> grade;

public:
  Student() {}
  void setName(string c)
  {
    name = c;
  }
  void setStudetID(int stuID)
  {
    studentID = stuID;
  }
  void addGrade(Grade &gra)
  {
    if (grade.size() < 10)
      grade.push_back(gra);
    else
      cout << "Grade List is full";
  }
  int getNumOfGrade()
  {
    return grade.size();
  }
  vector<Grade> &getGrade()
  {
    return grade;
  }
};

void inputGrade(int numOfGrades, vector<Grade> &grade)
{
  for (int i = 0; i < numOfGrades; i++)
  {
    cout << "Name of Grade " << i + 1 << ":";
    string nameOfGrade;
    cin >> nameOfGrade;
    cout << "Mark of Grade " << i + 1 << ":";
    int markGrade;
    cin >> markGrade;

    grade.push_back(Grade(nameOfGrade, markGrade));
  }
}

void inputInfo(int numberOfStu, Student *&stuList)
{
  for (int i = 0; i < numberOfStu; i++)
  {
    int a;
    cout << "Input details for Students " << i + 1 << ": " << endl;
    cout << "Student ID? ";
    int stuID = 0;
    cin >> stuID;
    cout << "Name? ";
    string name;
    cin >> name;
    stuList[i].setName(name);
    stuList[i].setStudetID(stuID);
    cout << "How many Grades? ";

    cin >> a;
    inputGrade(a, stuList[i].getGrade());
  }
}

int main()
{
  int numberOfStu = 0;
  cout << "Enter number of Students? ";
  cin >> numberOfStu;
  if (numberOfStu <= 0)
    exit(0);
  Student *stuList = new Student[numberOfStu];
  inputInfo(numberOfStu, stuList);
  cout << "Which student avarage grade? ";
  int whichStu;
  cin >> whichStu;
  double avarage;
  double sum = 0;
  vector<Grade> temp = stuList[whichStu - 1].getGrade();
  for (auto &it : temp)
  {
    sum += (double)it.getMark();
  }
  avarage = sum / (double)temp.size();
  cout << "Average grade for student " << whichStu << ": ";
  cout << avarage;
  delete stuList;
}