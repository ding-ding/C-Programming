#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define 	BLACK	0
#define 	RED 	1

struct node{
	int data;
	int color;
	struct node *l;
	struct node *r;
};
typedef struct node rb_tree;

int lev = 0;
int tmp = 0;

rb_tree *get_node(int data)
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
	if((*p)->color && (*c)->color)
		return RED;
	else
		return BLACK;
}

void rb_modify(rb_tree **p, rb_tree **c, rb_tree **pp)
{
	printf("rb_modify\n");
	if(!(*pp)->l && !(*pp)->r) return;
	else if(!(*pp)->l && (*pp)->r)	rl_rot(*pp, *p);
	else if((*pp)->l && !(*pp)->r)	lr_rot(*pp, *p);
	else {
		if((*pp)->l->color && (*pp)->r->color) // case 1 pp -> red, other black
		{
			(*pp)->color = RED;
			(*pp)->l->color = BLACK;
			(*pp)->r->color = BLACK;
			if(lev == 1) {
				(*pp)->color = BLACK;
				lev--;
			}
		}
		else if((*pp)->l->color && !(*pp)->r->color)	// case 2-1 lr
		{
			lr_rot(*pp, *p);
		}
		else if(!(*pp)->l->color && (*pp)->r->color)	//case 2-2 rl
		{
			rl_rot(*pp, *p);
		}	
	}
}
$ rm -fr .git
$ git init
$ git remote add origin your-git-remote-url
$ git fetch
$ git reset --hard origin/master
$ git branch --set-upstream-to=origin/master master

void rb_ins(rb_tree **p, rb_tree **c, rb_tree **pp, int data)
{
	printf("rb_ins\n");
	if(!(*c)){
		*c = get_node(data);
	}
	else if(data < (*c)->data){
		if(!(*c)->color) lev++;
		rb_ins(c, &(*c)->l, p, data);
	}
	else if(data > (*c)->data){
		if(!(*c)->color) lev++;
		rb_ins(c, &(*c)->r, p, data);
	}
	if(!(*c)->color) lev--;
	if(rb_chk(p, c))
	{
		rb_modify(p, c, pp);
	}
}

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

int main(void)
{

	int i;
	int data[20] = {10, 11, 12, 13, 14, 15, 9, 8, 7, 6,
			5, 4, 3, 16, 17, 2, 18, 19, 1, 20};
	rb_tree *root = NULL;

	for(i = 0; i < 12; i++)
	{
		printf("lev = %d\n", lev);
		rb_ins(&root, &root, &root, data[i]);


	}

	return 0;
}