#include <bits/stdc++.h>
using namespace std;

class Node
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

Node *DeletElm(Node *head, int k)
{
    if (head == nullptr)
        return head;

    else if (head->next == nullptr)
    {
        if (k == 1)
        {
            delete head;
            return nullptr;
        }
    }

    else if (k == 1)
    {

        Node *temp = head;
        head = head->next;
        head->back = nullptr;

        delete temp;
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

                if (temp->next == nullptr)
                {
                    ptr->next = temp->next;
                    temp->back = nullptr;
                    delete temp;
                    return head;
                }

                ptr->next = temp->next;
                temp->next->back = ptr;
                delete temp;
                return head;
            }
            ptr = temp;
            temp = temp->next;
        }

        return head;
    }
}

int main()
{
    int k;
    cout << "the val of k:";
    cin >> k;

    vector<int> arr = {1, 2, 3}; //{}//{1};

    // arr --> 2d ll -->

    if (k > arr.size())
    {
        cout << "not possible";
        return 0;
    }

    Node *head = Convertor(arr);
    head = DeletElm(head, k);

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