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

Node *Rotate(Node *head, int k)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    int len = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }

    if (k % len == 0)
        return head;

    else
        k = k % len;

    temp = head;
    int x = len - k - 1;
    Node *adds = nullptr;

    while (temp->next != nullptr)
    {
        if (x == 0)
            adds = temp;
        temp = temp->next;
        x--;
    }
    temp->next = head;
    head = adds->next;
    adds->next = nullptr;

    return head;
}

int main()
{
    int k;
    cout << "the val of K";
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

    head = Rotate(head, k);

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