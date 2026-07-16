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
    // edge cases->
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

Node *removeTail(Node *head)
{
    // edge csaes-->
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete (temp->next);
    temp->next = nullptr;

    return head;
}

int main()
{
    vector<int> arr = {1}; //{1, 2, 3, 4}; //{} / {1}
    Node *head = Convertor(arr);
    // new ll after remove tail-->
    head = removeTail(head);

    if (head == nullptr)
        cout << "no tail";

    else
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    return 0;
}