#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


/* 1. Insertion at Beginning */
void insertAtBeginning()
{
    struct Node *newNode;
    struct Node *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning.\n");
}


/* 2. Insertion at Ending */
void insertAtEnding()
{
    struct Node *newNode;
    struct Node *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted at ending.\n");
}


/* 3. Deletion at Beginning */
void deleteAtBeginning()
{
    struct Node *temp;
    struct Node *last;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    /* Only one node */
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        temp = head;
        head = head->next;
        last->next = head;

        free(temp);
    }

    printf("Node deleted from beginning.\n");
}


/* 4. Deletion at Ending */
void deleteAtEnding()
{
    struct Node *temp;
    struct Node *prev;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    /* Only one node */
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        prev = NULL;

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;

        free(temp);
    }

    printf("Node deleted from ending.\n");
}


/* 5. Forward Traversal */
void forwardTraversal()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward Traversal: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");
}


/* 6. Reverse Traversal */
void reverseTraversal(struct Node *temp)
{
    if (temp->next != head)
    {
        reverseTraversal(temp->next);
    }

    printf("%d ", temp->data);
}


/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n===== CIRCULAR LINKED LIST =====\n");
        printf("1. Insertion at Beginning\n");
        printf("2. Insertion at Ending\n");
        printf("3. Deletion at Beginning\n");
        printf("4. Deletion at Ending\n");
        printf("5. Forward Traversal\n");
        printf("6. Reverse Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertAtBeginning();
                break;

            case 2:
                insertAtEnding();
                break;

            case 3:
                deleteAtBeginning();
                break;

            case 4:
                deleteAtEnding();
                break;

            case 5:
                forwardTraversal();
                break;

            case 6:
                if (head == NULL)
                {
                    printf("List is empty.\n");
                }
                else
                {
                    printf("Reverse Traversal: ");
                    reverseTraversal(head);
                    printf("\n");
                }
                break;

            case 7:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}
