#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head;
    struct Node *temp;
    struct Node *prev;

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = head;

    if (head == NULL)
    {
        printf("List is empty.");
        return 0;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }

    printf("Node deleted from ending.\n");

    return 0;
}