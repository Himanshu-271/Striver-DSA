#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

Node *Constructor(vector<int> &arr)
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

Node *Remove(Node *head, int k)
{

    if (head == nullptr)
        return nullptr;

    else if (head->next == nullptr && head->data == k)
    {

        delete head;
        return nullptr;
    }

    Node *temp = head;
    Node *ptr = nullptr;

    while (temp != nullptr)
    {

        if (temp->data == k)
        {

            if (temp == head)
            {
                head = head->next;

                if (head != nullptr)
                    head->back = nullptr;

                delete temp;

                temp = head;
            }

            else
            {

                if (temp->next == nullptr)
                {
                    ptr->next = nullptr;
                    delete temp;
                    return head;
                }

                ptr->next = temp->next;
                temp->next->back = ptr;

                delete temp;

                temp = ptr->next;
            }
        }

        else
        {

            ptr = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    int k;
    cout << "the value of key :";
    cin >> k;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = Constructor(arr);

    head = Remove(head, k);

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