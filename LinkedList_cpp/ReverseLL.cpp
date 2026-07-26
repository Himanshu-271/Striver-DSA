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

Node *Reverse(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    // Brute--->

    /* stack<int> st;

     Node *temp = head;

     while (temp != nullptr)
     {
         st.push(temp->data);
         temp = temp->next;
     }

     temp = head;

     while (temp != nullptr)
     {
         temp->data = st.top();
         st.pop();
         temp = temp->next;
     }*/

    // optimal--->

    /* Node *temp = head;
     Node *ptr = head->next;

     while (ptr != nullptr)
     {

         Node *add1 = ptr;
         Node *add2 = ptr->next;

         ptr->next = temp;

         temp = add1;
         ptr = add2;
     }

     head->next = nullptr;

     return temp;*/

    // recursion--->

    Node *newhead = Reverse(head->next);
    Node *ptr = head->next;
    ptr->next = head;
    head->next = nullptr;
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

    head = Reverse(head);

    if (head == nullptr)
    {
        cout << "empty";
        return 0;
    }

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}