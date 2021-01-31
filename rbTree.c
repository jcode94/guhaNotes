// Muscle memory red-black tree conversion from C++ code at https://en.wikipedia.org/wiki/Red%E2%80%93black_tree

// Basic type definitions:

enum color_t
{
    BLACK,
    RED
};
typedef struct Node Node;

struct Node
{
    Node *parent;
    Node *left;
    Node *right;
    enum color_t color;
    int data;
};

// Helper functions:

Node *get_parent(Node *node)
{
    // Note that parent is set to null for the root node.
    return (!node ? NULL : node->parent);
}

Node *GetGrandParent(Node *node)
{
    // Note that it will return NULL if this is root or child of root
    return get_parent(get_parent(node));
}

Node *get_sibling(Node *node)
{
    Node *p = get_parent(node);

    // No parent means no sibling.
    if (!p)
    {
        return p;
    }

    if (node == p->left)
    {
        return p->right;
    }

    else
    {
        return p->left;
    }
}

Node *get_uncle(Node *node)
{
    Node *p = get_parent(node);

    // No parent means no uncle
    return get_sibling(p);
}

void rotate_left(Node *node)
{
    Node *nnew = node->right;
    Node *p = get_parent(node);
    assert(nnew); // Since the leaves of a red-black tree are empty,
                  // they cannot become internal nodes.
    node->right = nnew->left;
    nnew->left = node;
    node->parent = nnew;
    // Handle other childparent pointers;
    if (node->right)
    {
        node->right->parent = node;
    }

    // Initially n could be the root.
    if (p)
    {
        if (node == p->left)
        {
            p->left = nnew;
        }
        else if (node == p->right)
        {
            p->right = nnew;
        }
    }
}

void rotate_right(Node *node)
{
    Node *nnew = node->left;
    Node *p = get_parent(node);
    assert(nnew);

    node->left = nnew->right;
    nnew->right = node;
    node->parent = nnew;

    // Handle other child/parent pointers.
    if (node->left)
    {
        node->left->parent = node;
    }

    // Initially n could be the root.
    if (p)
    {
        if (node == p->left)
        {
            p->left = nnew;
        }

        else if (node == p->right)
        {
            p->right == nnew;
        }
    }
    nnew->parent = p;
}

Node *insert(Node *root, Node *node)
{
    // Insert new Node into the current tree.
    insert_recurse(root, node);

    // Repair the tree in case any of the red-black properties have been violated.
    insert_repair_tree(node);

    // Find the new root to return.
    root = node;
    while (get_parent(root))
    {
        root = get_parent(root);
    }
    return root;
}

void insert_recurse(Node *root, Node *node)
{
    // Recursibely descend the tree until a leaf is found.
    if (root)
    {
        if (node->data < root->data)
        {
            if (root->left)
            {
                insert_recurse(root->left, node);
                return;
            }
            else
            {
                root->left = node;
            }
        }
        else // node->data >= root->data
        {
            if (root->right)
            {
                insert_recurse(root->right, node);
                return;
            }
            else
            {
                root->right = node;
            }
        }
    }

    // Insert new Node n.
    node->parent = root;
    node->left = NULL;
    node->right = NULL;
    node->color = RED;
}