#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
struct node {
	int data;
	struct node* ptr;
};
struct node* head = NULL;
struct node* insert(int value);
struct node* delete( int value, struct node* head);
int size = 0;
int value;
int main(int argc, char** argv) {
	
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) printf("error\n"); 	
	fseek(fp, 0, SEEK_END); 
	if (ftell(fp) ==0) {
		return 0;
	}
	rewind(fp);
	char iod; int num;
	while ( fscanf(fp,"%c %d\n", &iod, &num) != EOF) {
		if (iod == ' ') {
		} else if (iod == 'i') {
			head = insert(num);
		} else if ( iod == 'd') {
			head = delete(num, head);
		} else { 
			printf("error\n");
		}
	}
	fclose(fp);
	printf("%d\n", size); 
	struct node* pt;
	for (pt = head; pt != NULL; pt = pt->ptr) 
	{
		if (pt->data == pt->data){

			printf("%d\t", pt->data);
		
		
	}
	}
	printf("\n");
	return 0;
}

struct node* insert(int value) {
	if (head == NULL) { 
		head = malloc( sizeof( struct node));
		head->data = value;
		head->ptr = NULL;
		size++;
		return head;
	}
	else if ( head->data >= value) {//>
		struct node* pushin = malloc(sizeof(struct node));
		pushin->data = value;
		pushin->ptr = head;
		size++;
		return pushin;
	}
	else if (head->data == value){
		return NULL;//
	}


		else{ 
		struct node* point = head;
		struct node* previous;
		while (point != NULL) {
			if (point->data >= value) {
				struct node* pushin;
			
				pushin = malloc(sizeof(struct node));
				pushin->data = value;//=
				pushin->ptr = previous->ptr;
				previous->ptr = pushin;
				size++;
				return head;
			
			}

			else if (point->data == value) {
				return head;
			}
			previous = point;
			point = point->ptr;
		}
		struct node* pushin = malloc(sizeof(struct node));
		pushin->data = value;//=
		pushin->ptr = NULL;
		previous->ptr = pushin;
		size++;
		return head;
	}
}

struct node* delete(int value, struct node* head) {
	if (head == NULL) return head;
	else if (head->data == value) {
		if (head->ptr == NULL) {
			head = head->ptr; 
			size--;
			return head;
		}
		size--;
		head = head->ptr;
	} 
	struct node* pt = head;
	struct node* previous = head;
	while (pt != NULL) {
		if (pt->data == value){
			
			previous->ptr = pt->ptr;
			size--;
			return head;
		}
		previous = pt;
		pt = pt->ptr;
	}
	
	return head;
}

