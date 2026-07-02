#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &v) // refrence pass
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; // == v.at(i)
    }
    cout << endl;
}
int main()
{
    vector<int> vec1;
    int size, elms;
    cin >> size;

    cout << " enter an elms:";
    for (int i = 0; i < size; i++)
    {
        cin >> elms;
        vec1.push_back(elms); // add elm line by line
    }
    display(vec1);
    vector<int>::iterator iter = vec1.begin();
    vec1.insert(iter, 566); // syntax = (iter+i,no of copy,elm)
    display(vec1);
    return 0;
}