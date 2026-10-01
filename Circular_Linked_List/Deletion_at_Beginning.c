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
            temp = temp->next;

        temp->next = head->next;
        temp = head;
        head = head->next;

        free(temp);
    }

    printf("Node deleted from beginning.\n");

    return 0;
}