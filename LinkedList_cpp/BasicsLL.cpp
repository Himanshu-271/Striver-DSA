#include <bits/stdc++.h>
using namespace std;

struct Node
{

    // members -->
public:
    // two data dype we can store in a node;
    int data;
    Node *next;
    // imp each node it own data or pointer . so they no overwrite ;

    // constructor for value assign-->
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *Convertor(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // head ko point starting me;
    Node *mover = head;            // mover pointer bcoz we cant move head ;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // temp-- store new created node ka adds;
        mover->next = temp;            // mover se  new creted node ka adds store in next(pointer) of present node jha mover abhi jis node pe h; // connection kar rha
        mover = temp;                  // mover ko move next node par le jaye ge ;
    }
    return head;
}

int length(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};

    /*  Node *y = new Node{arr[0]}; // new node create of ll and new ret adds of node and that adds store in y;
      cout << y << endl;          // address
      cout << y->data;            // value
      */

    // arr--->ll convert-->

    Node *head = Convertor(arr);

    // cout << head->data;

    // temp pointer bnaye  that point head  initaly ;for itreation in whole ll-->

    Node *temp = head;

    while (temp != nullptr) // temp move hota hota end node tak chala jaye;
    {
        cout << temp->data << " "; // excess dat of that node;
        temp = temp->next;         // move over temp to next node;
    }

    cout << endl;

    // Length find-->

    int len = length(head);
    cout << "lenght of LL:" << len;

    return 0;
}