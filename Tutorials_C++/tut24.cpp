#include <iostream>
using namespace std;

class Employee
{
private:
    static int count;
    int id;

public:
    void setData(void)
    {
        cout << "enter id no:" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "the id of emp is:" << id << endl
             << "and this emp no:" << count << endl;
    }
    static void getcount(void)
    {
        cout << "the vlalue of count is:" << count << endl
             << endl;
    }
};
int Employee::count; // define for static var  // here given value to count ; not in class
int main()
{
    Employee boby, him, om;
    boby.setData();
    boby.getData();
    Employee::getcount();

    him.setData();
    him.getData();
    Employee::getcount();

    om.setData();
    om.getData();
    Employee::getcount();

    return 0;
}