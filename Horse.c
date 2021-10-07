#include <stdio.h>
#include<stdlib.h>

typedef struct horse {
char name[30];
int rank;
struct horse * next;
} horse ;

horse * addTail(horse * head) {
horse * new = (horse *)malloc(sizeof(horse));
printf("Give the name of the horse : "); scanf("%s", new->name);
printf("Give the rank of the horse : "); scanf("%d", &new->rank);
if (head == NULL) {new->next = head;
                              head = new;
                              }
else {                     new->next = NULL;
                              horse * liste = head;
while(liste->next != NULL) liste = liste->next;
                                          liste->next = new;
                                          }
return head;
}

horse * create(int n) {                          // insertion at tail of list
horse * liste = NULL;
for (int i = 1; i <= n; i++)
liste = addTail(liste);
return liste;
}

horse * maxRank(horse * head) {
if (head == NULL) return NULL;
else {
        horse * max = head, *p = head->next;
while(p != NULL) {
if(max->rank < p->rank) max = p;
p = p->next;
}
return max;
}
}

horse * deleteMaxRank(horse * head) {
horse *max = maxRank(head);
horse *before, *after, *liste = head;
if (max != NULL) {
        if (max == head) head = head->next;
else {
after = max->next;
while(liste->next != max) liste = liste->next;
before = liste;
before->next = after;
}
return head;
}
}

void display(horse * head) {
horse * liste = head;
while(liste != NULL) {
printf("horse %s has rank %d\n", liste->name, liste->rank);
liste = liste->next;
}
}

void saveFile(horse * head, char * file) {
FILE * pf;
pf = fopen(file, "w");
if(pf == NULL) printf("\nImpossible to open file\n");
else {
horse * liste = head;
while(liste != NULL) {
fprintf(pf, "%s\t%d\n", liste->name, liste->rank);
liste = liste->next;
}
fclose(pf);
}
}

void displayFile(char * file) {
FILE *pf;
pf = fopen(file, "r");
if(pf == NULL) printf("\nImpossible to open file\n");
else {
char nameHorse[30];
int r;
while(!feof(pf)) {
fscanf(pf, "%s%d", nameHorse, &r);
if(!feof(pf))
printf("Horse %s has rank %d\n", nameHorse, r);
}
fclose(pf);
}
}

void displayMaxRank(horse * liste) {
if (liste != NULL)
printf("horse %s has rank %d\n", liste->name, liste->rank);
}

void main() {
printf("----- Creation of 5 horses -----\n");
horse * H = create(5);
printf("\n----- List of horses -----\n");
display(H);
printf("\n-----Add a horse at end of liste -----\n");
H = addTail(H);
printf("\n----- Horse having max rank -----\n");
horse * max = maxRank(H);
displayMaxRank(max);
printf("\n----- After deletion of the horse -----\n");
H = deleteMaxRank(H);
display(H);
printf("\n----- Creation of File -----\n");
saveFile(H, "HorsesFile.txt");
printf("\n----- Display File -----\n");
displayFile("HorsesFile.txt");
}

