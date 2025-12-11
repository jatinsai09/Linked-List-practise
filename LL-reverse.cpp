#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};

Node *insertAtFront(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}

Node *insertBefore(Node *head, int key, int new_data)
{
    Node *cur = head;
    while (cur->next->data != key)
    {
        cur = cur->next;
    }
    if (cur == nullptr)
    {
        return head;
    }

    Node *newNode = new Node(new_data);
    newNode->next = cur->next;
    cur->next = newNode;
    return head;
}

Node *insertAfter(Node *head, int key, int new_data)
{
    Node *cur = head;
    while (cur->data != key)
    {
        cur = cur->next;
    }
    if (cur == nullptr)
    {
        return head;
    }

    Node *newNode = new Node(new_data);
    newNode->next = cur->next;
    cur->next = newNode;
    return head;
}

Node *insertAtEnd(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);
    if (!head)
    {
        return new_node;
    }

    Node *last = head;
    while (last->next)
    {
        last = last->next;
    }
    last->next = new_node;

    return head;
}

Node *reverseList(Node *head)
{
    Node *prev = nullptr, *cur = head, *nextNode;

    while (nextNode != nullptr)
    {
        nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    return prev;
}

void printList(Node *node)
{
    while (node)
    {
        cout << node->data;
        if (node->next != nullptr)
        {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << "\n";
}

int main()
{
    Node *head = nullptr;
    for (int i = 1; i <= 5; i++)
    {
        head = insertAtEnd(head, i);
    }
    head = insertAtFront(head, 0);
    head = insertBefore(head, 2, 22);
    head = insertAfter(head, 4, 44);
    cout << "Initial Linked List: \n";
    printList(head);

    cout << "After reversing: \n";
    head = reverseList(head);
    printList(head);

    return 0;
}