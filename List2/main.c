#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef signed int sint32;
typedef unsigned char uint8;

typedef struct Node
{
    struct Node *NodeLink;
    uint32 NodeData;
}Node_t;

void Inser_Node_At_Beganing(struct Node **List);
void Inser_Node_At_End(struct Node **List);
void Inser_Node_After(struct Node *List);
void Delete_Node_At_Beganing(struct Node **List);
void Delete_Node(struct Node *List);
void Reverse_List(struct Node **List);
void Sort_List(struct Node **List);
void Display_All_Nodes(struct Node *List);
uint32 Get_Length(struct Node *List);
struct Node* swap(struct Node *ptr1, struct Node *ptr2);

struct Node *ListHaed = NULL;

int main()
{
    uint32 UserChoice = 0;
    uint32 Length = 0;

    while (1)
    {
        printf("Hello in Single Linked List\n");
        printf("=============================================\n");
        printf("(1)=> Inser_Node_At_Beganing\n");
        printf("(2)=> Inser_Node_At_End\n");
        printf("(3)=> Inser_Node_After\n");
        printf("(4)=> Delete_Node_At_Beganing\n");
        printf("(5)=> Delete_Node\n");
        printf("(6)=> Reverse_List\n");
        printf("(7)=> Sort_List\n");
        printf("(8)=> Display_All_Nodes\n");
        printf("(9)=> Get_Length\n");
        printf("(10)=> Quit Program\n");
        printf("==============================================\n");
        printf("Enter Choice:");
        scanf("%i", &UserChoice);

        switch (UserChoice)
        {
        case 1:
            Inser_Node_At_Beganing(&ListHaed);
        break;
        case 2:
            Inser_Node_At_End(&ListHaed);
        break;
        case 3:
            Inser_Node_After(ListHaed);
        break;
        case 4:
            Delete_Node_At_Beganing(&ListHaed);
        break;
        case 5:
            Delete_Node(ListHaed);
        break;
        case 6:
            Reverse_List(&ListHaed);
        break;
        case 7:
            Sort_List(&ListHaed);
        break;
        case 8:
            Display_All_Nodes(ListHaed);
        break;
        case 9:
            Length = Get_Length(ListHaed);
            printf("List Length: ");
            printf("%i\n", Length);
        break;
        case 10:
            printf("Exit Program\n");
            exit(1);
        break;
        
        default:
        printf("Invalid Choice\n");
        break;
        }
    }
    
    return 0;
}

void Inser_Node_At_Beganing(struct Node **List)
{
    struct Node *TempNode = NULL;

    TempNode = (struct Node *)malloc(sizeof(struct Node));

    if (TempNode)
    {
        printf("Enter Data: ");
        scanf("%i", &(TempNode->NodeData));

        if(*List)
        {
            TempNode->NodeLink = *List;
            *List = TempNode;
        }   
        else
        {
            TempNode->NodeLink = NULL;
            *List = TempNode;
        }
    }
    else
    {
        printf("Malloc Can not Allocate List in Memmory\n");
    }

}
void Inser_Node_At_End(struct Node **List)
{
    struct Node *TempNode = NULL;
    struct Node *LastNode = NULL;

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if (TempNode)
    {
        printf("Enter Data: ");
        scanf("%i", &(TempNode->NodeData));
        TempNode->NodeLink = NULL;

        if (!*List)
        {
            *List = TempNode;
        }
        else
        {
            LastNode = *List;
            while (LastNode->NodeLink)
            {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }
    }
    else
    {
        printf("Malloc Can not Allocate List in Memmory\n");
    }
    
}
void Inser_Node_After(struct Node *List)
{
    struct Node *Node_C = List;
    struct Node *TempNode = NULL;
    uint32 Counter = 1, Position = 0, Length = Get_Length(List);

    printf("Enter Position, (First Node Position (1) ): ");
    scanf("%i", Position);

    if (Position > Length)
    {
        printf("Invalid Position, LIST Has (%i) Nodes\n");
    }
    else
    {
        while (Counter < Position)
        {
           Counter++;
            Node_C = Node_C->NodeLink;
        }
        TempNode = (struct Node *)malloc(sizeof(struct Node));
        if (TempNode)
        {
            printf("Enter Data: ");
            scanf("%i", &(TempNode->NodeData));
            TempNode->NodeLink = Node_C->NodeLink;
            Node_C->NodeLink = TempNode;
        }
        else
        {
            printf("Malloc Can not Allocate List in Memmory\n");
        }
        
    }
    
    
}
void Delete_Node_At_Beganing(struct Node **List)
{
    struct Node *Node_C = *List;
    uint32 Length = Get_Length(*List);

    if (!Length)
    {
        printf("List Is Empty, Nothing To Delete\n");
    }
    else
    {
        *List = Node_C->NodeLink;
        Node_C->NodeLink = NULL;
        free(Node_C);
    }
}
void Delete_Node(struct Node *List)
{
    struct Node *Node_C = List;
    struct Node *NextNode = List;
    uint32 Position = 0, Counter = 1, Length = 0;

    Length = Get_Length(List);
    printf("Enter Position: ");
    scanf("%i", &Position);

    if ((Position > Length) || (1 == Position))
    {
        printf("Please Use Delete_Node_At_Beganing (Number 4)\n");
    }
    else
    {
        while (Counter < (Position - 1))
        {
            Counter++;
            Node_C = Node_C->NodeLink;
        }
        NextNode = Node_C->NodeLink ;
        Node_C->NodeLink = NextNode->NodeLink;
        free(NextNode);
    }
}
void Reverse_List(struct Node **List)
{
    struct Node *Node_c = *List;
    struct Node *NextNode = NULL;
    struct Node *PrevNode = NULL;

    if (!*List)
    {
        printf("List is Empty, Nothing To Recerse\n");
    }
    else
    {
        while ((Node_c))
        {
            NextNode = Node_c->NodeLink;
            Node_c->NodeLink = PrevNode;

            PrevNode = Node_c;
            Node_c = NextNode;
        }
        *List = PrevNode;
    }
    
}
void Sort_List(struct Node **List)
{
    struct Node **TempNode = NULL;
    struct Node *Ptr1 = NULL;
    struct Node *Ptr2 = NULL;
    struct Node *NextNode = NULL;
    uint32 Length = Get_Length(*List);
    sint32 SwapFlag = 0;
    for (uint32 Iteration1 = 1; Iteration1 < Length; Iteration1++)
    {
        TempNode = List;
        SwapFlag = 0;
        for (uint32 Iteration2 = 1; Iteration2 < Length - 1 - Iteration1; Iteration2++)
        {
            Ptr1 = *TempNode;
            Ptr2 = Ptr1->NodeLink;
            if (Ptr1->NodeData > Ptr2->NodeData)
            {
                *TempNode = swap(Ptr1, Ptr2);
                SwapFlag = 1;
            }
            TempNode = &(*TempNode)->NodeLink;
        }
        if (SwapFlag == 0)
        {
            break;
        }
        
    }

}
void Display_All_Nodes(struct Node *List)
{
    uint32 Length = 0;
    struct Node *TempNode = List;

    // Length = Get_Length(List);

    printf("List Data: ");
    if ( (!List))
    {
        printf("List is Empty \n");
    }
    else
    {
        while (TempNode)
        {
            printf("(%i) => ", TempNode->NodeData);
            TempNode = TempNode->NodeLink;
        }
        if (!TempNode)
        {
            printf("NULL\n");
        }   
    }
}
uint32 Get_Length(struct Node *List)
{
    uint32 Counter = 0;
    struct Node *TempNode = List;

    // printf("List Length: ");
    if (!List)
    {
        Counter = 0;
    }
    else
    {
        while (TempNode)
        {
            Counter++;
            TempNode = TempNode->NodeLink;
        }  
    }
    return (Counter);
}
struct Node* swap(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *tmp = ptr2->NodeLink;
    ptr2->NodeLink = ptr1;
    ptr1->NodeLink = tmp;
    return ptr2;
}