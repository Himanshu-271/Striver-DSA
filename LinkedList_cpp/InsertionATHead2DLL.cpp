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

Node *InsertElm(Node *head, int elm)
{
    if (head == nullptr)
    {
        Node *temp = new Node(elm);
        return temp;
    }

    Node *temp = new Node(elm);
    temp->next = head;
    head->back = temp;

    return temp;
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
    Node *newhead = InsertElm(head, elm);

    Node *temp = newhead;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}