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

Node *Insertelm(Node *head, int elm)
{
    Node *temp = new Node(elm);
    temp->next = head;
    head = temp;

    return head;
}

int main()
{
    int elm;
    cout << "the val of elm:";
    cin >> elm;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = Convertor(arr);

    Node *newhead = Insertelm(head, elm);

    // if (newhead == nullptr)
    // {
    //     cout << "not possible";
    //     return 0;
    // }

    Node *temp = newhead;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}