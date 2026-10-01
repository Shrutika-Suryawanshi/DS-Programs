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
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    printf("Node deleted from beginning.\n");

    return 0;
}