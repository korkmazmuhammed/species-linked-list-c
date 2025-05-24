#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Inf
{
    char *class;
    char *order;
    char *family;
    char *genus;
    char *species;
    struct Inf *next;
} Inf;

Inf *inf_create(char *class, char *order, char *family, char *genus, char *species)
{
    Inf *cre = (Inf *)malloc(sizeof(Inf));

    cre->class = (char *)calloc(sizeof(char), strlen(class));
    strcpy(cre->class, class);

    cre->order = (char *)calloc(sizeof(char), strlen(order));
    strcpy(cre->order, order);

    cre->family = (char *)calloc(sizeof(char), strlen(family));
    strcpy(cre->family, family);

    cre->genus = (char *)calloc(sizeof(char), strlen(genus));
    strcpy(cre->genus, genus);

    cre->species = (char *)calloc(sizeof(char), strlen(species));
    strcpy(cre->species, species);
    cre->next = NULL;

    return cre;
}

Inf *find_last(Inf *root)
{
    if (root == NULL || root->next == NULL)
        return root;
    return find_last(root->next);
}

void print_inf(Inf *root)
{
    while (root)
    {
        printf("Class: %s\n", root->class);
        printf("Order: %s\n", root->order);
        printf("Family: %s\n", root->family);
        printf("Genus: %s\n", root->genus);
        printf("Species: %s\n", root->species);
        root = root->next;
        printf("\n");
    }
}

Inf *find_prev(Inf *head, Inf *target)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    if (head->next == target)
        return head;
    return find_prev(head->next, target);
}

void sort_by_thing(Inf **head, int choice)
{
    Inf *i, *j, *prev_i, *prev_j, *temp;
    int result;

    for (i = *head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            switch (choice)
            {
            case 1:
                result = (strcmp(i->class, j->class) > 0);
                break;
            case 2:
                result = (strcmp(i->order, j->order) > 0);
                break;
            case 3:
                result = (strcmp(i->family, j->family) > 0);
                break;
            case 4:
                result = (strcmp(i->genus, j->genus) > 0);
                break;
            case 5:
                result = (strcmp(i->species, j->species) > 0);
                break;
            default:
                printf("INVALID CHOICE\n");
                return;
                break;
            }
            if (result)
            {
                prev_j = find_prev(*head, j);
                prev_i = find_prev(*head, i);

                if (prev_i)           /*parent of i is not null*/
                    prev_i->next = j; /*next of previus is now j*/
                else
                    *head = j; /*if it is empty we are in the start point*/

                if (prev_j != i) /*if i and j are nnot in the same order*/
                {
                    temp = j->next; /*swapping /normal swap*/
                    j->next = i->next;
                    i->next = temp;

                    if (prev_j)           /*if previous j is not null*/
                        prev_j->next = i; /*prev_j now points i */
                }
                else /*if i and j are in the same order */
                {
                    temp = j->next;
                    j->next = i;
                    i->next = temp;
                }
                temp = i;
                i = j;
                j = temp;
            }
        }
    }
}

int determineChoice(char *select)
{
    int choice;
    if (strcmp(select, "class") == 0)
        choice = 1;
    else if (strcmp(select, "order") == 0)
        choice = 2;
    else if (strcmp(select, "family") == 0)
        choice = 3;
    else if (strcmp(select, "genus") == 0)
        choice = 4;
    else if (strcmp(select, "species") == 0)
        choice = 5;
    else
    {
        printf("INVALID CHOICE\n");
        return -1;
    }
    return choice;
}

int modify(Inf *root)
{
    char *spcs = (char *)calloc(sizeof(char), 10);
    printf("Enter Species Information to Modify\n");
    printf("Old Species:");
    scanf(" %s", spcs);
    while (root)
    {
        if (strcmp(root->species, spcs) == 0)
        {
            printf("New Class: ");
            scanf(" %[^\n]s", root->class);

            printf("New Order: ");
            scanf(" %[^\n]s", root->order);

            printf("New Family: ");
            scanf(" %[^\n]s", root->family);

            printf("New Genus: ");
            scanf(" %[^\n]s", root->genus);
            printf("New Species: ");
            scanf(" %[^\n]s", root->species);
            return 1;
        }
        root = root->next;
    }
    return -1;
}

Inf *delete(Inf *root, char *target)
{
    Inf *ci = root;
    Inf *li = NULL;
    int flag = 1;

    while (flag && ci != NULL)
    {
        if (strcmp(ci->species, target) == 0)
        {
            if (li == NULL)
                root = ci->next;
            else
                li->next = ci->next;
            free(ci->species);
            free(ci->family);
            free(ci->order);
            free(ci->class);
            free(ci->genus);
            free(ci);
            flag = 0;
        }
        li = ci;
        ci = ci->next;
    }
    return root;
}

int main()
{
    char expression = 0;
    int flag = 1;

    char class[15];
    char order[15];
    char family[15];
    char genus[15];
    char species[15];
    char *select = (char *)calloc(sizeof(char), 8);
    Inf *root = NULL;
    Inf *last = NULL;
    while (flag)
    {
        printf("WHAT DO YOU WANT TO DO\n");
        printf("1: ADD INFORMATION\n");
        printf("2: SORT BY SELECTED CRITERIA\n");
        printf("3: PRINT INFORMATION\n");
        printf("4: DELETE INFORMATRION\n");
        printf("5: MODIFY INFORMATRION\n");

        printf("6:EXIT \n");

        scanf(" %c", &expression);

        switch (expression)
        {
        case '1':
            printf("Enter Species Information\n");
            printf("Class: ");
            scanf(" %[^\n]s", class);
            printf("Order: ");
            scanf(" %[^\n]s", order);
            printf("Family: ");
            scanf(" %[^\n]s", family);
            printf("Genus: ");
            scanf(" %[^\n]s", genus);
            printf("Species: ");
            scanf(" %[^\n]s", species);

            last = find_last(root);
            if (last == NULL)
                root = inf_create(class, order, family, genus, species);
            else
                last->next = inf_create(class, order, family, genus, species);
            break;
        case '2':
            printf("Enter list criteria:(class,order,family,genus,species): ");
            scanf("%s", select);
            int choice = determineChoice(select);
            sort_by_thing(&root, choice);
            break;
        case '3':
            print_inf(root);
            break;
        case '4':
            printf("Enter species to delete: ");
            scanf("%s", species);
            root = delete (root, species);
            break;
        case '5':
            int m = modify(root);
            if (m == -1)
                printf("OLD INFORMATION NOT FOUNDED!!!\n");
            break;
        case '6':
            printf("EXITTED\n");
            flag = 0;
            break;
        default:
            printf("INVALID CHOICE TRY AGAIN \n");
            break;
        }
    }
}
