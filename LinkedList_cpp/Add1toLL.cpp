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

Node *Reverse(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newhead = Reverse(head->next);
    Node *ptr = head->next;
    ptr->next = head;
    head->next = nullptr;
    return newhead;
}

int helper(Node *temp)
{

    if (temp == nullptr)
        return 1;

    int carry = helper(temp->next);

    temp->data = temp->data + carry;

    if (temp->data < 10)
        return 0;

    else
    {
        temp->data = 0;
        return 1;
    }
}

Node *ADD1(Node *head, int x)
{
    if (head == nullptr)
        return head;

    // Brute--->

    /*  Node *newhead = Reverse(head);

      int carry = x;

      Node *temp = newhead;

      while (temp != nullptr)
      {

          int sum = temp->data + carry;

          temp->data = sum % 10;

          carry = sum / 10;

          if (carry == 0)
              break;

          temp = temp->next;
      }

      head = Reverse(newhead);

      if (carry > 0)
      {
          Node *temp = new Node(1);
          temp->next = head;
          return temp;
      }

      return head;*/

    // Optimal  -->

    // recursion+backtracking-->

    Node *temp = head;

    int carry = helper(temp);

    if (carry > 0)
    {
        Node *temp = new Node(carry);
        temp->next = head;
        return temp;
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

    head = ADD1(head, 1);

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