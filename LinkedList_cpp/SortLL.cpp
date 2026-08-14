#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

Node *Middle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *head1, Node *head2)
{

    if (head1 == nullptr && head2 == nullptr)
        return nullptr;
    else if (head1 == nullptr)
        return head2;
    else if (head2 == nullptr)
        return head1;

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 != nullptr && t2 != nullptr)
    {

        if (t1->data > t2->data)
        {
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        }

        else
        {
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
        }
    }

    if (t1 == nullptr)
        temp->next = t2;
    else
        temp->next = t1;

    return dummy->next;
}

Node *Sort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    // brute-->

    /* Node *temp = head;

     vector<int> arr;

     while (temp != nullptr)
     {
         arr.push_back(temp->data);
         temp = temp->next;
     }

     sort(arr.begin(), arr.end());

     head = Convertor(arr);

     return head;*/

    // optimal + Merge sort use --->

    Node *middle = Middle(head);

    Node *nexthead = middle->next;
    middle->next = nullptr;

    Node *lefthead = Sort(head);
    Node *righthead = Sort(nexthead);

    Node *newhead = merge(lefthead, righthead);

    return newhead;
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

    head = Sort(head);

    if (head == nullptr)
        cout << "empty";

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