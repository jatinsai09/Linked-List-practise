#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
        prev = nullptr;
    }
};

Node *insertAtFront(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head;

    if (head != NULL)
    {
        head->prev = new_node;
    }

    return new_node;
}

Node *insertAtPosition(Node *head, int pos, int new_data)
{
    Node *new_node = new Node(new_data);

    if (pos == 1)
    {
        new_node->next = head;
        if (head != NULL)
        {
            head->prev = new_node;
        }
        head = new_node;
        return head;
    }

    Node *cur = head;
    for (int i = 1; i < pos - 1 && cur != nullptr; i++)
    {
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Position is out of bounds.\n";
        delete new_node;
        return head;
    }

    new_node->prev = cur;
    new_node->next = cur->next;

    cur->next = new_node;
    if (new_node->next != nullptr)
    {
        new_node->next->prev = new_node;
    }

    return head;
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
    newNode->prev = cur;
    newNode->next = cur->next;

    cur->next = newNode;
    newNode->next->prev = newNode;
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
    newNode->prev = cur;

    cur->next = newNode;
    if (newNode->next)
    {
        newNode->next->prev = newNode;
    }
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
    new_node->prev = last;

    return head;
}

void printList(Node *node)
{
    while (node)
    {
        cout << node->data;
        if (node->next != nullptr)
        {
            cout << " <-> ";
        }
        node = node->next;
    }
    cout << "\n";
}

int main()
{
    Node *head = nullptr;
    for (int i = 1; i <= 6; i++)
    {
        head = insertAtEnd(head, i);
    }
    printList(head);

    head = insertAtPosition(head, 3, 22);
    printList(head);
    head = insertBefore(head, 4, 44);
    printList(head);
    head = insertAfter(head, 5, 55);
    printList(head);
    head = insertAtFront(head, 0);
    printList(head);

    return 0;
}