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
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;

    head = newNode;

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
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at ending.\n");
}


/* 3. Deletion at Beginning */
void deleteAtBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

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

    temp = head;
    prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }

    free(temp);

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

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


/* 6. Reverse Traversal */
void reverseTraversal(struct Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    reverseTraversal(temp->next);

    printf("%d ", temp->data);
}


/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
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
                printf("Reverse Traversal: ");

                if (head == NULL)
                {
                    printf("List is empty.");
                }
                else
                {
                    reverseTraversal(head);
                }

                printf("\n");
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
