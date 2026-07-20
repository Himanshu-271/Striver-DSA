#include <bits/stdc++.h>
using namespace std;

struct Node
{

public:
    int data;
    Node *next;
    Node *back;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *Convertor(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        temp->back = mover;

        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    // arr --> 2d ll -->

    Node *head = Convertor(arr);

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}