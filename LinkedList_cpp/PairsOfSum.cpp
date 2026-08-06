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

vector<pair<int, int>> Pairs(Node *head, int sum)
{
    vector<pair<int, int>> ans;

    // brute --->

    /*Node *fix = head;

    while (fix != nullptr)
    {

        Node *mover = fix->next;

        while (mover != nullptr)
        {

            if (fix->data + mover->data == sum)
            {
                ans.push_back({fix->data, mover->data});
            }

            else if (fix->data + mover->data > sum)
                break;

            mover = mover->next;
        }

        fix = fix->next;
    }

    return ans;*/

    // optimal ---->

    Node *l = head;

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *r = temp;

    while (l != r && r->next != l)
    {

        if (l->data + r->data == sum)
        {
            ans.push_back({l->data, r->data});
            l = l->next;
            r = r->back;
        }

        else if (l->data + r->data > sum)
            r = r->back;

        else
            l = l->next;
    }
    return ans;
}

int main()
{
    int sum;
    cout << "the val of sum:";
    cin >> sum;

    int n;
    cout << "the val of n:";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = Convertor(arr);

    vector<pair<int, int>> ans = Pairs(head, sum);

    if (ans.empty())
        cout << "no pairs found";

    else
    {
        for (auto it : ans)
        {
            cout << it.first << " " << it.second << endl;
        }
    }

    return 0;
}