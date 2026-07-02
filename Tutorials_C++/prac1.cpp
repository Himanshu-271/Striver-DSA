#include <iostream>
using namespace std;
class teacher;
class student
{
    int marks;

public:
    void setmarks(int m)
    {
        marks = m;
    }
    friend class teacher;
};

class teacher
{

public:
    void showMarks(student s)
    {
        cout << "the marks of st is:" << s.marks << endl;
    }
};
int main()
{
    int marks;
    cout << "enter the marks :" << endl;
    cin >> marks;
    student s1;
    teacher t;
    s1.setmarks(marks);
    t.showMarks(s1);

    return 0;
}