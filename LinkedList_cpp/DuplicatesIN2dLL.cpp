#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

Node *Duplicate(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp = head;

    while (temp != nullptr)
    {
        Node *mover = temp->next;

        if (mover == nullptr) // last dulpicate handell or safe case
        {
            temp->next = mover;
            temp = mover;
            continue;
        }

        // skip dulpicates-->

        while (mover != nullptr && mover->back->data == mover->data)
        {
            mover = mover->next;
        }

        // duplicate delete-->
        Node *del = temp->next;

        while (del != mover)
        {
            Node *add = del->next;
            delete del;
            del = add;
        }

        // connections-->

        temp->next = mover;
        if (mover != nullptr)
            mover->back = temp;
        temp = mover;
    }

    return head;
}

int main()
{
    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = Convertor(arr);

    head = Duplicate(head);

    if (head == nullptr)
    {
        cout << "empty";
    }

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