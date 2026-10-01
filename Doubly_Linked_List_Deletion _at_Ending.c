#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *head;
    struct Node *temp;

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = NULL;

    printf("Before deletion: %d\n", head->data);

    if (head == NULL)
    {
        printf("List is empty.");
        return 0;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);

    printf("Node deleted from ending.\n");

    return 0;
}