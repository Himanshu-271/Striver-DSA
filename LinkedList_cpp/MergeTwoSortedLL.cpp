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

Node *Merge(Node *head1, Node *head2)
{

    if (head1 == nullptr && head2 == nullptr)
        return nullptr;
    else if (head1 == nullptr)
        return head2;
    else if (head2 == nullptr)
        return head1;

    // brute--->

    /* vector<int> v;

     Node *t1 = head1;
     Node *t2 = head2;

     while (t1 != nullptr && t2 != nullptr)
     {

         if (t1->data > t2->data)
         {
             v.push_back(t2->data);
             t2 = t2->next;
         }

         else
         {
             v.push_back(t1->data);
             t1 = t1->next;
         }
     }

     while (t1 != nullptr)
     {
         v.push_back(t1->data);
         t1 = t1->next;
     }

     while (t2 != nullptr)
     {
         v.push_back(t2->data);
         t2 = t2->next;
     }

     sort(v.begin(), v.end());

     Node *head = Convertor(v);

     return head;*/

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

    int m;
    cout << "the val of m:";
    cin >> m;

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    Node *head1 = Convertor(arr);
    Node *head2 = Convertor(brr);

    Node *head = Merge(head1, head2);

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