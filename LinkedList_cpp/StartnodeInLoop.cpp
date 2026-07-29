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

Node *Loop(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return nullptr;

    // brute-->
    // hashing -->

    /* unordered_map<Node *, int> mp;

     Node *temp = head;

     while (temp != nullptr)
     {

         if (mp.find(temp) != mp.end()) // check if present;
         {
             return temp;
         }

         mp[temp] = 1; // maping to 1 if no present or insert in map;

         temp = temp->next;
     }

     return nullptr; // if no loop  */

    // optimal --->

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = Convertor(arr);

    // Create loop: 5 -> 2
    Node *temp = head;
    Node *join = head->next; // Node with value 2

    while (temp->next != nullptr)
        temp = temp->next;

    // temp->next = join;

    Node *startnode = Loop(head);

    if (startnode == nullptr)
    {
        cout << "no loop or empty ";
    }

    else
        cout << startnode->data << "   " << startnode;

    return 0;
}