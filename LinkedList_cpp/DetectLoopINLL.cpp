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

bool Detectloop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    // brute -->
    // hashing--->

    /* unordered_map<Node *, int> mp;


     Node *temp = head;

     while (temp != nullptr)
     {
         if (mp.find(temp) != mp.end())
             return true;
         mp[temp] = 1;
         temp = temp->next;
     }
     return false;*/

    // optimal -->
    // fast slow ptrs  oR Rabit - Tortoise capture method-->

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    // int n;
    // cout << "the val of n:";
    // cin >> n;

    // vector<int> arr(n);

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = Convertor(arr);

    // Create loop: 5 -> 2
    Node *temp = head;
    Node *join = head->next; // Node with value 2

    while (temp->next != nullptr)
        temp = temp->next;

    // temp->next = join;

    bool ans = Detectloop(head);

    cout << ans;

    return 0;
}