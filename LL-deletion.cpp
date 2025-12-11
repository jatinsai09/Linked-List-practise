#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
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

Node *deleteHead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;

    delete temp;

    return head;
}

Node *deleteNode(Node *head, int position)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;

    if (position == 1)
    {
        head = temp->next;
        delete temp;
        return head;
    }

    Node *prev = nullptr;
    for (int i = 1; i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}

Node *deleteLastNode(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *prev = head;
    while (prev->next->next != nullptr)
    {
        prev = prev->next;
    }

    delete prev->next;
    prev->next = nullptr;

    return head;
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
    for (int i = 1; i < 5; i++)
    {
        head = insertAtEnd(head, i);
    }
    head = insertAtFront(head, 0);
    head = insertBefore(head, 2, 22);
    head = insertAfter(head, 4, 44);
    printList(head);

    head = deleteHead(head);
    printList(head);

    head = deleteNode(head, 2); // (head, position)
    printList(head);

    head = deleteLastNode(head);
    printList(head);

    return 0;
}