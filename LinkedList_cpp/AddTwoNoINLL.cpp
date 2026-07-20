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

Node *SumOFll(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *t2 = head2;

    Node *dummy = new Node(-1);
    Node *current = dummy;

    int carry = 0;
    int sum = 0;

    while (t1 != nullptr || t2 != nullptr)
    {

        sum = carry;

        if (t1 != nullptr)
            sum = sum + t1->data;
        if (t2 != nullptr)
            sum = sum + t2->data;

        int rem = sum % 10;
        carry = sum / 10;

        Node *temp = new Node(rem);
        current->next = temp;
        current = temp;

        if (t1 != nullptr)
            t1 = t1->next;
        if (t2 != nullptr)
            t2 = t2->next;
    }

    if (carry > 0)
    {
        Node *temp = new Node(carry);
        current->next = temp;
    }

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

    Node *head = SumOFll(head1, head2);

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