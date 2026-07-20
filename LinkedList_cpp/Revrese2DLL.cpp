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

Node *Reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    // brute--->

    /*stack<int> st; // use LIFO

    Node *temp1 = head;

    while (temp1 != nullptr)
    {
        st.push(temp1->data); // store in stack;
        temp1 = temp1->next;
    }

    Node *temp2 = head;

    while (temp2 != nullptr)
    {
        temp2->data = st.top(); // copy in LL
        st.pop();
        temp2 = temp2->next;
    }*/

    // optimal -->

    Node *temp = head;      // back ptr;
    Node *ptr = temp->next; // next ptr;
    temp->next = nullptr;   // tail form of head

    while (ptr != nullptr)
    {
        Node *p = nullptr; // store adds of next node for movement;
        temp->back = ptr;  // reverse the links  b-->n  n-->b
        p = ptr->next;     // copy adds
        ptr->next = temp;

        temp = ptr; // move
        ptr = p;
    }

    temp->back = ptr; // make tail-->head back null ;

    return temp;
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

    // arr --> 2d ll -->

    Node *head = Convertor(arr);

    head = Reverse(head);

    if (head == nullptr)
    {
        cout << "empty ll";
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