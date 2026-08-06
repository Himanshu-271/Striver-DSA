#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        random = nullptr;
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

Node *Clone(Node *head)
{
    if (head == nullptr)
        return nullptr;

    // brute by hashing-->

    /* Node *temp = head;
     unordered_map<Node *, Node *> mp;

     while (temp != nullptr)
     {

         Node *newnode = new Node(temp->data);
         mp[temp] = newnode;
         temp = temp->next;
     }

     temp = head;

     while (temp != nullptr)
     {

         Node *copynode = mp[temp];
         copynode->next = mp[temp->next];
         copynode->random = mp[temp->random];

         temp = temp->next;
     }

     return mp[head];*/

    // optimal -->

    Node *temp = head;
    while (temp != nullptr)
    {

        Node *copy = new Node(temp->data);
        copy->next = temp->next;
        temp->next = copy;

        temp = temp->next->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        if (temp->random != nullptr)
            temp->next->random = temp->random->next;
        else
            temp->next->random = nullptr;
        temp = temp->next->next;
    }

    Node *dummy = new Node(-1);
    Node *mover = dummy;

    temp = head;

    while (temp != nullptr)
    {
        mover->next = temp->next;
        temp->next = temp->next->next;
        mover = mover->next;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    // next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // random pointers
    n1->random = n3;
    n2->random = n1;
    n3->random = n4;
    n4->random = n2;

    Node *head = n1;

    head = Clone(head);

    if (head == nullptr)
        cout
            << " empty";

    else
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "random links" << endl;

        temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "--" << temp->random->data << endl;
            temp = temp->next;
        }
    }

    return 0;
}