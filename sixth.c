#include <stdlib.h>
#include <stdio.h>
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* head = NULL;
struct Node* pNode = NULL;

struct Node* insert(int num, struct Node* point );

void printInorder(struct Node* node);

int height;

int main(int argc, char** argv) {
	FILE* fp = fopen(argv[1], "r");
	if ( fp == NULL) {
		
		printf("error");
	}
	int num[1];
	char character[1];
	while (fscanf(fp, "%c\t%d\n", character, num) != EOF) { 

		if (*character == 'i') {
			
			insert(*num, head);
		
	
		}
		else if (*character != 'i'){
			printf("error\n");
			exit(0);
		} 
		
	
	}
	printInorder(head);
	fclose(fp);
	return 0;
}


struct Node* insert(int num, struct Node* pCurNode ) {
	
	
		
	if (pCurNode == NULL) {
		pCurNode = (struct Node*) malloc( sizeof(struct Node));
		pCurNode->data = num;
		pCurNode->left = NULL;
		pCurNode->right = NULL;
		if (head == NULL) head = pCurNode;
		
	} else if (pCurNode-> data == num) {
		
		return pCurNode;
	} else if (pCurNode->data > num) {
		height++;
		
		pCurNode->left = insert(num, pCurNode->left );

		height--;
	} else { 
		height++;
	
		pCurNode->right = insert(num, pCurNode->right );
	
		height--;
	}
	return pCurNode;
}


void printInorder(struct Node* node) {
	
	if ( node == NULL ) return;
	if (node->left != NULL) {
		
		printInorder(node->left);
	} 
	printf("%d\t", node->data);
	if (node-> right != NULL) {
	
		printInorder(node->right);
	} 	
	return;
}
