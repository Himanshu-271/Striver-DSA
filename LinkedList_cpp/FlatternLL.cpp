#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int x)
    {
        data = x;
        next = nullptr;
        child = nullptr;
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
        mover->child = temp;
        mover = temp;
    }
    return head;
}

Node *Flattern(Node *head)
{

    if (head == nullptr || (head->child == nullptr && head->next == nullptr))
        return head;

    // brute--->

    vector<int> v;

    Node *temp = head;

    while (temp != nullptr)
    {
        Node *t = temp;

        while (t != nullptr)
        {
            v.push_back(t->data);
            t = t->child;
        }

        temp = temp->next;
    }

    sort(v.begin(), v.end());

    head = Convertor(v);

    return head;
}

Node *merge(Node *head, Node *newhead)
{

    Node *t1 = head;
    Node *t2 = newhead;

    Node *dummy = new Node(-1);
    Node *mover = dummy;

    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->data > t2->data)
        {
            mover->child = t2;
            t2 = t2->child;
            mover = mover->child;
        }
        else
        {
            mover->child = t1;
            t1 = t1->child;
            mover = mover->child;
        }
        mover->next = nullptr;
    }

    while (t1 != nullptr)
    {
        mover->child = t1;
        t1 = t1->child;
        mover = mover->child;
        mover->next = nullptr;
    }

    while (t2 != nullptr)
    {
        mover->child = t2;
        t2 = t2->child;
        mover = mover->child;
        mover->next = nullptr;
    }

    return dummy->child;
}
Node *Flatn(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newhead = Flatn(head->next);

    head = merge(head, newhead);

    return head;
}
int main()
{

    // input-->

    // Main list
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    // Child list of 5 : 5 -> 7 -> 8 -> 30
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    // Child list of 10 : 10 -> 20
    head->next->child = new Node(20);

    // Child list of 19 : 19 -> 22 -> 50
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    // Child list of 28 : 28 -> 35 -> 40 -> 45
    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    /*
    5 ----> 10 ----> 19 ----> 28
    |        |        |        |
    7        20       22       35
    |                 |        |
    8                 50       40
    |                          |
    30                         45
    */

    // brute-->

    // head = Flattern(head);

    // recursion + optimal-->

    head = Flatn(head);

    if (head == nullptr)
        cout
            << " empty";

    else
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->child;
        }
    }
    return 0;
}
