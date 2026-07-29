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

    Node *head = Convertor(arr);

    // brute-->

    /*  Node *temp = head;
      int cnt = 0;

      while (temp != nullptr)
      {
          cnt++;
          temp = temp->next;
      }

      int middle = cnt / 2 + 1;

      Node *middlenode = head;

      while (middle - 1 > 0)
      {
          middle--;
          middlenode = middlenode->next;
      }

      if (middlenode == nullptr)
      {
          cout << "empty";
          return 0;
      }
      else
          cout << middlenode->data << "  " << middlenode;*/

    // optimal --->

    // slow or fast pointers-->

    // SLow move speed x  Fast move with 2x;
    // so slow reach mid  fast reaach end node(odd len) or out(even len);

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == nullptr)
    {
        cout << "empty";
        return 0;
    }

    else
    {
        cout << slow->data << "  " << slow;
    }
    return 0;
}