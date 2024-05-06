#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} node;

// Function to create a new node with given value
node* createNode(int value) {
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

// Function to add a node at the end of the list
void push_back(node** array, int value) {
    node* temp = createNode(value);

    if (*array == NULL) {
        *array = temp;
    } else {
        node* p = *array;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

// Function to remove the last node from the list
void pop_back(node** array) {
    if (*array == NULL) {
        return;
    }
    node* p = *array;
    node* prev = NULL;
    while (p->next != NULL) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL) {
        *array = NULL; // Removing the only node
    } else {
        prev->next = NULL;
    }
    free(p);
}

int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

// Function to add a node at the front of the list
void push_front(node** array, int value) {
    node* temp = createNode(value);
    temp->next = *array;
    *array = temp;
}

// Function to remove the first node from the list
void pop_front(node** array) {
    if (*array == NULL) {
        return;
    }
    node* temp = *array;
    *array = (*array)->next;
    free(temp);
}

// Function to get the value of the first node
int front(node* array) {
    if (array == NULL) {
        printf("Error: List is empty\n");
        return -1; // Assuming -1 indicates an error or invalid value
    }
    return array->value;
}

// Function to get the value of the last node
int back(node* array) {
    if (array == NULL) {
        printf("Error: List is empty\n");
        return -1; // Assuming -1 indicates an error or invalid value
    }
    while (array->next != NULL) {
        array = array->next;
    }
    return array->value;
}

// Function to insert a node at a specific position
void insert(node** array, int value, int pos) {
    if (pos < 0) {
        printf("Error: Invalid position\n");
        return;
    }
    if (pos == 0) {
        push_front(array, value);
        return;
    }
    node* temp = createNode(value);
    node* p = *array;
    int i = 0;
    while (p != NULL && i < pos - 1) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Error: Position out of bounds\n");
        return;
    }
    temp->next = p->next;
    p->next = temp;
}

// Function to delete a node at a specific position
void deletee(node** array, int pos) {
    if (*array == NULL || pos < 0) {
        printf("Error: List is empty or invalid position\n");
        return;
    }
    if (pos == 0) {
        pop_front(array);
        return;
    }
    node* p = *array;
    node* prev = NULL;
    int i = 0;
    while (p != NULL && i < pos) {
        prev = p;
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Error: Position out of bounds\n");
        return;
    }
    prev->next = p->next;
    free(p);
}

// Function to get the size of the list
int size(node* array) {
    int count = 0;
    while (array != NULL) {
        count++;
        array = array->next;
    }
    return count;
}

// Function to check if the list is empty
bool empty(node* array) {
    return (array == NULL);
}

int main() {
    node* arr = NULL;

    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    printf("Value at position 2: %d\n", get(arr, 2));
    printf("Value at position 0: %d\n", get(arr, 0));
    printf("Value at position 5: %d\n", get(arr, 5));

    push_front(&arr, 1);
    printf("Value at the front: %d\n", front(arr));

    pop_front(&arr);
    printf("Value at the front after pop: %d\n", front(arr));

    printf("Value at the end: %d\n", back(arr));

    insert(&arr, 9, 3);
    printf("Value at position 3 after insertion: %d\n", get(arr, 3));

    deletee(&arr, 4);
    printf("Size of the list: %d\n", size(arr));
    printf("Is the list empty? %s\n", empty(arr) ? "Yes" : "No");

    return 0;
}
