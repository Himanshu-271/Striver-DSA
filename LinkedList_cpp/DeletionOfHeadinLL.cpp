#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
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
        mover = temp;
    }
    return head;
}

Node *removeHead(Node *head)
{

    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4}; // {} / {1}
    Node *head = Convertor(arr);
    Node *newhead = removeHead(head);

    if (newhead != nullptr)
    {
        cout << newhead->data << endl;
        cout << newhead << endl;
        cout << newhead->next;
    }
    else
        cout << "empty LL" << endl;

    return 0;
}