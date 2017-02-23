#include <stdio.h>
#include <malloc.h>

#define _EMPTY 0;

typedef struct node
{
	int data;

	struct node* right;	//bigger
	struct node* left;	//smaller
} NODE;


NODE *init_node(int data){
	NODE *node;
	node = (NODE *) malloc (sizeof(NODE));
	node -> data = data;
	node -> right = 0;
	node -> left = 0;
	return node;
}

void insert(NODE **ins, int data)
{
	// Recursion
	if(!(*ins)) (*ins) = init_node(data);
	else if(data < (*ins) -> data)	insert(&(*ins)->left, data);
	else if(data > (*ins) -> data)	insert(&(*ins)->right, data);
	else {
		printf("%d already exist\n", data);
		return;
	}
	// Iteration

}


void print_tree(NODE *tmp)
{
	if(!tmp) return;
	printf("%d ",tmp->data);
	print_tree(tmp->left);
	print_tree(tmp->right);
}


NODE *search_node(NODE **s_node, NODE **p_node, int data)
{
	// Recursion
	// if(!(*sch)) return;
	// if(data < (*sch)->data) search_node(&(*sch)->left, data);
	// else if(data > (*sch)->data) search_node(&(*sch)->right, data);
	// else if(data == (*sch)->data) 
	// {
	// 	printf("data detecting\n");
	// 	return;
	// }
	//Iteration
	if(!(*s_node)) return 0;
	int flag = 1;
	NODE *tmp = (*s_node);
	while(flag)
	{
		if(data < tmp->data) 
		{
			if(!tmp->left) return 0;
			(*p_node) = tmp;
			tmp = tmp->left;
		}
		else if(data > tmp->data) 
		{
			if(!tmp->right)	return 0;			
			(*p_node) = tmp;
			tmp = tmp->right;
		}
		else if(data == tmp->data) 
			return tmp;
	}
}

// left high
int leftToLargest(NODE* alt, NODE *alt_p, int data)
{
	if(alt->right) {
		leftToLargest(alt->right, alt, data);
	}else{
		if(alt->left) alt_p->right = alt->left;
		data = alt->data;
		if(alt_p->left && alt_p->left == alt) alt_p->left = 0;
		free(alt);
		return data;
	}	
}

int rightToSmaller(NODE *alt, NODE *alt_p, int data)
{
	if(alt->left) {
		rightToSmaller(alt->left, alt, data); 
	}else{
		// if(alt_p->right && alt_p == alt) alt_p->data = alt->data;
		if(alt->right) alt_p->left = alt->right;
		data = alt->data;
		if(alt_p->right && alt_p->right == alt) alt_p->right = 0;
		free(alt);
		return data;
	}
}

void alt(NODE *alt, NODE **p_node, int data)
{
	if(alt->left) {
		alt->data = leftToLargest(alt->left, alt, data);
	} 
	else if(alt->right) {
		alt->data = rightToSmaller(alt->right, alt, data);
	} 
	else {
		if((*p_node)->left && (*p_node)->data == alt->data) (*p_node)->left = 0;
		else (*p_node)->right = 0;
		free(alt);
	}
}

void delete(NODE **top, int data)
{
	NODE *p_node = *top;
	NODE *tmp = search_node(top, &p_node, data);
	alt(tmp, &p_node, data);
	printf("delete fin\n");
	print_tree(&(**top));
	printf("\n");
}


int main (void)
{
	NODE *top = _EMPTY;
	int i;
	int data[12] = {50,20,10,40,30,35,80,90,100,60,70,65};

	for(i = 0; i < 12; i++)
	{
		insert(&top, data[i]);
	}
	print_tree(top);
	printf("\n");
	// search_node(&top, 120);
	delete(&top, 35);
	delete(&top, 90);
	delete(&top, 50);
	delete(&top, 20);

	print_tree(top);
	printf("\n");
	return 0;
}
