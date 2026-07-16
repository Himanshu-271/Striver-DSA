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

Node *Insertelm(Node *head, int elm, int k)
{
    if (head == nullptr)
    {
        if (k == 1)
            return new Node(elm);
        else
            return nullptr;
    }

    if (k == 1)
    {
        Node *temp = new Node(elm);
        temp->next = head;
        head = temp;

        return head;
    }

    else
    {
        Node *temp = head;

        int cnt = 0;
        Node *ptr = nullptr;

        while (temp != nullptr)
        {
            cnt++;
            if (cnt == k)
            {
                Node *x = new Node(elm);
                ptr->next = x;
                x->next = temp;
                return head;
            }
            ptr = temp;
            temp = temp->next;
        }

        Node *lastAdd = new Node(elm);
        ptr->next = lastAdd;
        return head;
    }
}

int main()
{
    int elm;
    cout << "the val of elm:";
    cin >> elm;

    int k;
    cout << "the val of k:";
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

    head = Insertelm(head, elm, k);

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}