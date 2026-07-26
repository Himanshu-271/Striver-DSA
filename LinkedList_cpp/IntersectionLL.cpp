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

Node *Intersection(Node *head1, Node *head2)
{

    // brute--->

    // hashing-->

    unordered_map<Node *, int> mp; //<addres of nodes,map to 1>

    Node *temp = head1;

    while (temp != nullptr)
    {
        mp[temp] = 1;
        temp = temp->next;
    }

    temp = head2;

    while (temp != nullptr)
    {
        if (mp.find(temp) != mp.end()) // common node come check by addres that store of nodes
        {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

Node *Collision(Node *temp1, Node *temp2, int x)
{

    while (x > 0)
    {
        x--;
        temp1 = temp1->next;
    }

    while (temp1 != temp2)
    {

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node *FindIntersection(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *t2 = head2;

    if (t1 == nullptr || t2 == nullptr)
        return nullptr;

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
            return t1;

        if (t1 == nullptr)
            t1 = head2;
        if (t2 == nullptr)
            t2 = head1;
    }
    return t1;
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

    int m;
    cout << "the val of m:";
    cin >> m;

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    int r;
    cout << "teh val of r:";
    cin >> r;

    vector<int> crr(r);

    for (int i = 0; i < r; i++)
    {
        cin >> crr[i];
    }

    Node *head1 = Convertor(arr);
    Node *head2 = Convertor(brr);
    // common ll-->
    Node *head3 = Convertor(crr);

    if (head1 != nullptr && head2 != nullptr && head3 != nullptr)
    {
        Node *temp1 = head1;

        while (temp1->next != nullptr)
        {
            temp1 = temp1->next;
        }

        Node *temp2 = head2;

        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }

        temp1->next = head3;
        temp2->next = head3;
    }

    // brute-->

    //  Node *commonNode = Intersection(head1, head2);

    /* if (commonNode == nullptr)
         cout << "No Intersectiuon";
     else
     {
         cout << commonNode->data << "  " << commonNode;
     }*/

    // optimal -->

    /* Node *t1 = head1;
     Node *t2 = head2;

     int len1 = 0;
     int len2 = 0;

     while (t1 != nullptr)
     {

         len1++;
         t1 = t1->next;
     }

     while (t2 != nullptr)
     {

         len2++;
         t2 = t2->next;
     }

     Node *point = nullptr;
     if (len1 > len2)
     {
         point = Collision(head1, head2, len1 - len2);
     }

     else
     {
         point = Collision(head2, head1, len2 - len1);
     }

     if (point == nullptr)
     {
         cout << "no intersect";
         return 0;
     }

     else
         cout << point->data << "   " << point;*/

    // Switch Pointer approch -->
    // No need find len diff  similiar apove approch work algo-->

    Node *intersect = FindIntersection(head1, head2);

    if (intersect == nullptr)
    {
        cout << "no intersect";
        return 0;
    }

    else
        cout << intersect->data << "   " << intersect;

    return 0;
}