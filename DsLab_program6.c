#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int rows, cols, value;
    struct Node *next;
};

typedef struct Node Node;

int sparse_matrix(int matrix[][100], int rows, int cols)
{
    int count = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != 0)
                count++;
        }
    }

    if (count > (rows * cols) / 2)
        return 0;
    else
        return 1;
}

Node * create_Sparse_Matrix(int matrix[][100], int rows, int cols)
{
    Node *head = NULL;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != 0)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->rows = i;
                newNode->cols = j;
                newNode->value = matrix[i][j];
                newNode->next = NULL;

                if (head == NULL)
                    head = newNode;
                else
                {
                    Node *temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode;
                }
            }
        }
    }

    return head;
}

void display_sparse_matrix(Node *head)
{
    Node *temp = head;
    printf("Row\tColumn\tValue\n");

    while (temp != NULL)
    {
        printf("%d\t%d\t%d\n", temp->rows, temp->cols, temp->value);
        temp = temp->next;
    }
}

int main()
{
    int matrix[100][100], rows, cols;

    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (sparse_matrix(matrix, rows, cols))
    {
        printf("The given matrix is sparse.\n");
        Node *sparse_matrix = create_sparse_matrix(matrix, rows, cols);
        printf("Sparse matrix representation:\n");
        display_sparse_matrix(sparse_matrix);
    }
    else
    {
        printf("The given matrix is not sparse.\n");
    }

    return 0;
}