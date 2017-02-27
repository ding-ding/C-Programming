#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define 	BLACK	0
#define 	RED 	1

typedef struct rb_tree{
	int data;
	int color;
	struct rb_tree l;
	struct rb_tree r;
}rb_tree;

rb_tree *get_node(data)
{
	rb_tree *tmp = (rb_tree *)malloc(sizeof(rb_tree));
	// tmp = (rb_tree *)malloc(sizeof(rb_tree));
	tmp->l = NULL;
	tmp->r = NULL;
	tmp->color = 1;
	return tmp;
}

rb_tree *ll_rot(rb_tree *p, rb_tree *c)
{
	p->l = c->r;
	c->r = p;

	return c;
}

rb_tree *rr_rot(rb_tree *p, rb_tree *c)
{
	p->r = c->l;
	c->l = p;

	return c;
}

rb_tree *lr_rot(rb_tree *p, rb_tree *c)
{
	c = rr_rot(c, c->r);
	return ll_rot(p, c);
}

rb_tree *rl_rot(rb_tree *p, rb_tree *c)
{
	c = ll_rot(c, c->l);
	return rr_rot(p, c);
}

int rb_chk(rb_tree **p, rb_tree **c)
{
	if((*p)->color && (*c)->color)	//	
		return RED;
	else
		return BLACK;
}

void rb_rotation(rb_tree **pp, rb_tree **p)
{
	if(pp->l->color && pp->r->color) // case 1 pp -> red, other black
	{

	}
	else if(pp->l->color && !pp->r->color)	// case 2-1 lr
	{
		lr_rot(*pp, *p);
	}
	else if(!pp->l->color && pp->r->color)	//case 2-2 rl
	{
		rl_rot(*pp, *p);
	}
}

// Recursion
void rb_ins(rb_tree **p, rb_tree **c, rb_tree **pp, int data)
{
	if(!(*c))
		*c = get_node(data);
	else if(data < (*c)->data)
		rb_ins(c, &(*c)->l, p, data);
	else if(data > (*c)->data)
		rb_ins(c, &(*c)->r, p, data);
	if(rb_chk(p, c))
	{
		rb_rotation(pp, p);
	}
}

// Iteration
// void rb_ins(rb_tree **root, int data)
// {
// 	int abs;


// 0
// 	while(1)
// 	{
// 		if(!(*root))
// 			*root = get_node(data);
// 		else if(data < (*root)->data)

// 		else if(data > (*root)->data)

// 		if(rb_tree)
// 	}
// }

void main(void)
{

	int i;
	int data[20] = {10, 11, 12, 13, 14, 15, 9, 8, 7, 6,
			5, 4, 3, 16, 17, 2, 18, 19, 1, 20};
	rb_tree *root = NULL;

	for(i = 0; i < 12; i++)
	{
		// rb_ins(&root, &root, &root, data[i]);


	}

	return 0;
}