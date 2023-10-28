#include <iostream>
#include <string>

/*
 * a Node class or struct ( you decide ) for your list nodes
 * a printList( ) function: prints the list
 * an insertNode( ) function: inserts a given node to the list
 * a deleteNode( ) function: deletes referenced node from the list
 */

class Node {
public:
    int data{};
    Node* next;
};

void printList(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

void insertNode(Node *head, int n)
{
    Node *temp = new Node();
    temp->data = n;
    temp->next = NULL; // previous three lines are creating a new node based off parameters

    Node *ptr = head; // ptr to head list
    while(ptr)
    {
        if(ptr->next == NULL) // end of head list
        {
            ptr->next = temp; // copy temp Node (from parameter values) into ptr
            return; // exit
        }
        ptr = ptr->next; // iterate through copy of head until end (NULL ptr is found)
    }
}

void initializeHead(Node *head)
{
    int headNum{};
    std::cout << "Enter in the first head: ";
    std::cin >> headNum;
    head->data = headNum;
    head->next = NULL;
}

void initializeNodes(Node *head)
{
    bool exit{ false };
    std::cout << "Enter in proceeding nodes (-1 to exit): ";
    while(!exit)
    {
        int n{};
        std::cin >> n;
        if(n == -1)
        {
            int status{};
            std::cout << "Confirm exit? Y - 1, N - INT (or -1 again to add -1): ";
            std::cin >> status;

            if(status == 1)
            {
                exit = true;
            }
            else if(status == -1)
            {
                insertNode(head, -1);
            }
            else
            {
                continue;
            }
        }
        else
        {
            insertNode(head, n);
        }
    }
}

Node *searchNode(Node *head, int n)
{
    Node *temp = head;
    while(temp)
    {
        if(temp->data == n)
        {
            return temp;
        }
        temp = temp->next;
    }
    std::cout << "\nNo Node " << n << " in list.\n";
}

bool deleteNode(Node **head, Node *ptrDel)
{
    Node *temp = *head;
    if(ptrDel == *head)
    {
        *head = temp->next;
        delete ptrDel;
        return true;
    } // if node deleting is head, reassign it to the next node before deleting

    while(temp)
    {
        if(temp->next == ptrDel)
        {
            temp->next = ptrDel->next;
            delete ptrDel;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node* head = new Node();
    initializeHead(head);
    initializeNodes(head);
    std::cout << "\nList: ";
    printList(head);

    // tried implementing into a separate function but had trouble with the pointers so i decided to make it simple
    int n{};
    std::cout << "\nEnter a value to delete from list: ";
    std::cin >> n;
    Node *ptrDel = searchNode(head, n);
    if (deleteNode(&head, ptrDel))
    {
        std::cout << "\nNode " << n << " deleted!\n";
    }
    std::cout << "\nModified list: ";
    printList(head);
    return 0;
}