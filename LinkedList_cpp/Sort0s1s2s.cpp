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

Node *Sort(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // brute--->

    /*  Node *temp = head;

      int cnt0 = 0;
      int cnt1 = 0;
      int cnt2 = 0;

      while (temp != nullptr)
      {

          if (temp->data == 0)
              cnt0++;
          else if (temp->data == 1)
              cnt1++;
          else
              cnt2++;

          temp = temp->next;
      }

      temp = head;

      while (temp != nullptr)
      {

          if (cnt0 > 0)
          {
              temp->data = 0;
              cnt0--;
          }

          else if (cnt1 > 0)
          {
              temp->data = 1;
              cnt1--;
          }

          else
          {
              temp->data = 2;
              cnt2--;
          }

          temp = temp->next;
      }*/

    // optimal -->

    Node *dummy0 = new Node(-1);
    Node *zero = dummy0;
    Node *dummy1 = new Node(-1);
    Node *one = dummy1;
    Node *dummy2 = new Node(-1);
    Node *two = dummy2;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }

        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }

        else
        {
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }

    zero->next = (dummy1->next) ? dummy1->next : dummy2->next;
    one->next = dummy2->next;
    two->next = nullptr;

    return dummy0->next;
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

    head = Sort(head);

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