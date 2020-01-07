#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	//int key;//
	int data;
	struct node* next;
};
void insert (struct node* root, int num, int key);
int hashf(int num);
struct node* hash[10000];
int main(int argc, char** argv) {
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("error\n");
		return 0;
	}

	char op; int num;
	//struct node** head = hash;//
	for (int i = 0; i < 10000; i++) {
		hash[i] = NULL;
	}
	//struct node* first = NULL;//
	while (fscanf(fp, "%c\t%d\n", &op, &num) !=EOF) {
		struct node* first = NULL;
		int key = hashf(num);
		if (op =='i') {
			if (hash[key] == NULL) {
				insert(first, num, key); 
			} else {
				struct node* existing = hash[key];
				 insert(existing, num, key);
			} 
		} else if (op == 's') {
			if (hash[key] == NULL) { 
				printf("%d\n", num);
			} else {
				int boo = 0;
				struct node* existing = hash[key];	
				//search(existing, num);
				if (existing == NULL) {
					printf("error");
				} else {
					struct node* ptr = existing;
					 while (ptr != NULL) {
						if (ptr->data == num) {
							boo = 1;
							break;
						}
						ptr = ptr->next;
					}
				}
				if (boo == 0) {
	
				} else {
	
				}
			}
		} else {
			printf("error\n");
		}
	}
	fclose(fp);
	return 0;
}

int hashf(int num) {
	int key = num % 10000;
	if (key < 0) key = key * -1;
	//printf("%d\t", key);
	return key;
}

void insert (struct node* root, int num, int key) {
	//int i;
	//int num[] = {num};
	//for(i=0; i <= num; i++){
	printf("%d\t", num);
	if (root == NULL) {
		
		struct node* new =(struct node*) malloc(sizeof(struct node));
		new->data = num;
		new->next = NULL;
		hash[key] = new;
		
		return;
	} else {
	
		struct node* move = root;
		while ( move->next != NULL) {
			if (move->data == num) {
				
				return;
			}
			move = move->next;	
		}
		struct node* nnode = (struct node*)  malloc(sizeof(struct node));
		nnode->data = num;
		nnode->next =NULL;
		move->next = nnode;
		hash[key] = nnode;
		
		return;
	}
}
