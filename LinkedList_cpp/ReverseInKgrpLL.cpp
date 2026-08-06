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

Node *Reverse(Node *temp)
{

    if (temp == nullptr || temp->next == nullptr)
        return temp;

    // recursion--->

    Node *newhead = Reverse(temp->next);
    Node *ptr = temp->next;
    ptr->next = temp;
    temp->next = nullptr;

    return newhead;
}

Node *fxn(Node *t, int k)
{

    while (t != nullptr && k - 1 > 0)
    {
        t = t->next;
        k--;
    }
    return t;
}

Node *Reversegrp(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp = head;
    Node *ptr = nullptr;

    while (temp != nullptr)
    {

        Node *kNode = fxn(temp, k);

        if (kNode == nullptr)
        {
            if (ptr != nullptr)
                ptr->next = temp;
            break;
        }

        Node *nextNode = kNode->next;
        kNode->next = nullptr;
        Reverse(temp);

        if (temp == head)
        {
            head = kNode;
        }
        else
        {
            ptr->next = kNode;
        }
        ptr = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
    int k;
    cout << "the val of grps:";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = Convertor(arr);

    head = Reversegrp(head, k);

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