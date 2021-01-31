/*
*   This was copied for muscle memory from @accrazed, aka 'she who is senpai;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node Node;

struct Node
{
    Node *left;
    Node *right;
    int data;
};

Node *insert(Node *root, int data);
void in_order(Node *root);
void tree_sort(int *array, int length);
Node *create_node();
int *fill_array(int length);

int main()
{
    int *num_arr;
    int len_arr;

    printf("Length of array of items: ");
    scanf("%d", &len_arr);

    num_arr = fill_array(len_arr);

    tree_sort(num_arr, len_arr);

    free(num_arr);

    return 0;
}

int *fill_array(int length)
{
    time_t t;
    int *array = malloc(length * sizeof(int));

    srand((unsigned)time(&t));

    for (int i = 0; i < length; ++i)
    {
        *(array + i) = (rand() % 50) + 1; // random number 1-50
    }

    for (int i = 0; i < length; ++i)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");

    return array;
}

void tree_sort(int *array, int length)
{
    Node *root = calloc(1, sizeof(Node)); // root

    for (int i = 0; i < length; ++i)
    {
        insert(root, *(array + i));
    }

    in_order(root);
}

Node *insert(Node *root, int data)
{
    // Base case
    if (root == NULL)
    {
        return create_node(data);
    }

    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else // if data < root->data
    {
        root->left = insert(root->left, data);
    }

    return root;
}

void in_order(Node *root)
{
    // Base case
    if (!root)
    {
        return;
    }

    in_order(root->left);
    printf("Node: %d\n", root->data);
    in_order(root->right);
}

Node *create_node(data)
{
    Node *ret = calloc(1, sizeof(Node));

    if (ret == NULL)
        return NULL;

    ret->data = data;

    return ret;
}