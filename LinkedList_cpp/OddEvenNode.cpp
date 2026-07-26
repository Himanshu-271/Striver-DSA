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

Node *Convertor(vector<int> &v)
{

    if (v.empty())
        return nullptr;

    Node *head = new Node(v[0]);
    Node *mover = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;

        mover = temp;
    }
    return head;
}

Node *OddEven(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    //  brute --->

    /*    Node *temp1 = head;

        vector<int> brr;

        // Odds->
        while (temp1 != nullptr && temp1->next != nullptr)
        {
            brr.push_back(temp1->data);
            temp1 = temp1->next->next;
        }

        if (temp1 != nullptr)
            brr.push_back(temp1->data);

        Node *temp2 = head->next;

        // evens->
        while (temp2 != nullptr && temp2->next != nullptr)
        {
            brr.push_back(temp2->data);
            temp2 = temp2->next->next;
        }

        if (temp2 != nullptr)
            brr.push_back(temp2->data);

        Node *temp = head;
        int i = 0;

        while (temp != nullptr)
        {
            temp->data = brr[i];
            i++;
            temp = temp->next;
        }*/

    // optimal-->

    Node *odd = head;
    Node *even = head->next;
    Node *evenhead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenhead;

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

    head = OddEven(head);

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
