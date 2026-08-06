#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string url;
    Node *next;
    Node *back;

    Node(string url1)
    {
        url = url1;
        next = nullptr;
        back = nullptr;
    }
};

class Browser
{
    Node *currnetPage;

public:
    Browser(string &homepage)
    {
        currnetPage = new Node(homepage);
    }

    void visit(string &url)
    {
        Node *newNode = new Node(url);
        currnetPage->next = newNode;
        newNode->back = currnetPage;
        currnetPage = newNode;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (currnetPage->back)
                currnetPage = currnetPage->back;
            else
                break;

            steps--;
        }
        return currnetPage->url;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (currnetPage->next)
                currnetPage = currnetPage->next;
            else
                break;

            steps--;
        }
        return currnetPage->url;
    }
};

int main()
{
    string home = "leetcode.com";

    Browser browser(home);

    string a = "google.com";
    browser.visit(a);

    string b = "facebook.com";
    browser.visit(b);

    string c = "youtube.com";
    browser.visit(c);

    cout << browser.back(1) << endl;    // facebook.com
    cout << browser.back(1) << endl;    // google.com
    cout << browser.forward(1) << endl; // facebook.com

    return 0;
}