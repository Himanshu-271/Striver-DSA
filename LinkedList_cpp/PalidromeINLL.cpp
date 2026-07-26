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
    Node *halfhead = head;
    Node *ptr = halfhead->next;

    while (ptr != nullptr)
    {

        Node *add1 = ptr;
        Node *add2 = ptr->next;

        ptr->next = halfhead;

        halfhead = add1;
        ptr = add2;
    }

    head->next = nullptr;

    return halfhead;
}

bool Palidrome(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return true;

    // brute-->

    /* Node *temp = head;

     stack<int> st;

     while (temp != nullptr)
     {
         st.push(temp->data);
         temp = temp->next;
     }

     temp = head;

     while (temp != nullptr)
     {
         if (temp->data != st.top())
             return false;
         st.pop();
         temp = temp->next;
     }
     return true;*/

    // optimal -->

    Node *slow = head;
    Node *fast = head;

    // even case or odd case nodes-->
    while (fast->next != nullptr && fast->next->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse links-->

    Node *halfhead = Reverse(slow->next);

    // check -->

    Node *p1 = head;
    Node *p2 = halfhead;

    while (p2 != nullptr)
    {
        if (p1->data != p2->data)
        {
            Reverse(halfhead);
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    Reverse(halfhead);

    return true;
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

    bool ans = Palidrome(head);

    cout << ans;

    return 0;
}