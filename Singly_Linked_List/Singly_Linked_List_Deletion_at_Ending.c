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
    head->next = NULL;

    printf("Before deletion: %d\n", head->data);

    if (head == NULL)
    {
        printf("List is empty.");
        return 0;
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

    return 0;
}