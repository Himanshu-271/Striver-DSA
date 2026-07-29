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

int Lengthloop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return 0;

    // brute--->

    /*  Node *temp = head;
      int time = 0;

      unordered_map<Node *, int> mp;

      while (temp != nullptr)
      {

          if (mp.find(temp) != mp.end())
          {
              return (time - mp[temp] + 1);
          }

          mp[temp] = time + 1;
          time++;

          temp = temp->next;
      }
      return 0;*/

    // optimal--->

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {

            fast = fast->next;
            int len = 1;

            while (fast != slow)
            {

                len++;
                fast = fast->next;
            }
            return len;
        }
    }
    return 0;
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

    temp->next = join;

    int len = Lengthloop(head);

    cout << len;
    return 0;
}