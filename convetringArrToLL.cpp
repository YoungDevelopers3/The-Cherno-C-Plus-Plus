#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertingArr2LL(vector<int> &arr)
{
    Node *header = new Node(arr[0]);
    Node *mover = header;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return header;
}
int main()
{
    vector<int> arr = {12, 5, 8, 9};
    Node *header = convertingArr2LL(arr);
    cout << header->data;
}