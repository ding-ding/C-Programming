#include <stdio.h>
#include <stdlib.h>

#define LL	-2
#define RR	2
#define LR	-3
#define RL	3

struct node
{
	int data;
	int lev;
	struct node *l;
	struct node *r;
};
typedef struct node avl_tree;

avl_tree *get_node(void)
{
	avl_tree *tmp;
	tmp = (avl_tree *)malloc(sizeof(avl_tree));
	tmp->l = NULL;
	tmp->r = NULL;
	tmp->lev = 1;
	return tmp;
}

int lev_chk(avl_tree *root)
{
	int r = root->r > 0 ? root->r->lev : 0;
	int l = root->l > 0 ? root->l->lev : 0;
	return r - l;
}

int lev_modify(avl_tree *root)
{
	int l, r;

	r = root->r > 0 ? root->r->lev : 0;
	l = root->l > 0 ? root->l->lev : 0;

	if(l > r)
		return l + 1;

	return r + 1;
}

avl_tree *ll_rot(avl_tree *p, avl_tree *c)
{
	p->l = c->r;
	c->r = p;
	p->lev = lev_modify(p);
	printf("p ->lev = %d\n", p->lev);
	c->lev = lev_modify(c);
	printf("c ->lev = %d\n", c->lev);
	return c;
}

avl_tree *rr_rot(avl_tree *p, avl_tree *c)
{
	p->r = c->l;
	c->l = p;
	p->lev = lev_modify(p);
	c->lev = lev_modify(c);
	return c;
}

avl_tree *lr_rot(avl_tree *p, avl_tree *c)
{
	c = rr_rot(c, c->r);
	return ll_rot(p, c);
}

avl_tree *rl_rot(avl_tree *p, avl_tree *c)
{
	c = ll_rot(c, c->l);
	return rr_rot(p, c);
}

avl_tree *rotation(avl_tree *root, int ret)
{
	printf("rotation = %p\n", root);
	switch(ret)
	{
		case LL:
			return ll_rot(root, root->l);
		case LR:
			return lr_rot(root, root->l);
		case RR:
			return rr_rot(root, root->r);
		case RL:
			return rl_rot(root, root->r);
	}
}

int rot_chk(avl_tree *root, int data)
{
	if(lev_chk(root) < 0)
	{
		if(lev_chk(root->l) > -1 && root->l->data < data)
			return LR;
		return LL;
	}
	else
	{
		if(lev_chk(root->r) < 1 && root->r->data > data)
			return RL;
		return RR;
	}
	return 0;
}

void avl_ins(avl_tree **root, int data)
{
	int abs;
	if(!(*root))
	{
		*root = get_node();
		(*root)->data = data;
		return;
	}
	if((*root)->data > data)
		avl_ins(&(*root)->l, data);
	else
		avl_ins(&(*root)->r, data);


	(*root)->lev = lev_modify(*root);
	abs = lev_chk(*root);
	abs = (abs > 0) ? abs : -abs;
	if(abs > 1){
		*root = rotation(*root, rot_chk(*root, data));
		printf("avl_ins root = %p\n", *root);
	}
}

avl_tree *chg_tree(avl_tree *root)
{
	avl_tree* tmp;
	tmp = root;

	if(!root->l)
		root = root->r;
	else if(!root->r)
		root = root->l;
	free(tmp);
	return root;
}

avl_tree *min_tree(avl_tree *root, int *data)
{
	if(root->l)
	{
		root->l = min_tree(root->l, data);
		root->lev = lev_modify(root);
	}
	else
	{
		*data = root->data;
		root = chg_tree(root);
	}
	return root;

}

void print_tree(avl_tree *root)
{
	if(root)
	{
		printf("data = %4d", root->data);
		if(root->l)
			printf(", left = %4d", root->l->data);
		else
			printf(", left = NULL");
		if(root->r)
			printf(", right = %4d", root->r->data);
		else
			printf(", right = NULL");
		printf("   %p\n", root);
		print_tree(root->l);
		print_tree(root->r);
	}
}

// avl_tree** search_tree(avl_tree **p, avl_tree **c, int data)
// {
	
// 	if(!c) return 0;
// 	if((*c)->data == data)
// 	{
// 		printf("search_tree = %p\n", c);
// 		return c;
// 	} 
// 	*p = c;
// 	if(data < (*c)->data)
// 		search_tree(p, &(*c)->l, data);
// 	else
// 		search_tree(p, &(*c)->r, data);
// }

// void avl_del(avl_tree **root, int data)
// {
// 	int num = data;
// 	int abs;
// 	avl_tree **tmp = root;
	
// 	avl_tree **c = search_tree(&tmp, &tmp, data);
// 	avl_tree **p = &tmp;
// 	tmp = &p;
// 	printf("previous\n");
// 	printf("tmp = %d \n", tmp->data);
// 	printf("p = %p\n", *p);

// 	if((*c)->l && (*c)->r)
// 	{
// 		(*c)->r = min_tree((*c)->r, &num);
// 		(*c)->data = num;
// 	}
// 	else
// 		*c = chg_tree(*c);

// 	printf("print p \n");
// 	print_tree(*p);
// 	(*p)->lev = lev_modify(*p);
// 	abs = lev_chk(*p);
// 	abs = (abs > 0) ? abs : -abs;
// 	if(abs > 1)
// 		*p = rotation(*p, rot_chk(*p, num));
// 	printf("print p \n");
// 	print_tree(*p);
// 	printf("\n\n");
// 	printf("tmp = %p \n", tmp);
// 	printf("p = %p\n", *p);
// }

void avl_del(avl_tree **p, avl_tree **c, int data)
{
	if(!c) return;
	if((*c)->data == data)
	{
		int abs = 0;
		int num = data;
		if((*c)->l && (*c)->r)
		{
			(*c)->r = min_tree((*c)->r, &num);
			(*c)->data = num;
		}
		else
			*c = chg_tree(*c);

		(*p)->lev = lev_modify(*p);
		abs = lev_chk(*p);
		abs = (abs > 0) ? abs : -abs;
		if(abs > 1)
			*p = rotation(*p, rot_chk(*p, num));
	}
	else if(data < (*c)->data)
		avl_del(c, &(*c)->l, data);
	else if(data > (*c)->data)
		avl_del(c, &(*c)->r, data);
}

// void avl_del(avl_tree **root, int data)
// {
// 	int num = data;
// 	int abs;
// 	avl_tree *tmp = *root;
	
// 	avl_tree **c = search_tree(root, root, data);
// 	avl_tree **p = &tmp;
	

// 	if((*c)->l && (*c)->r)
// 	{
// 		(*c)->r = min_tree((*c)->r, &num);
// 		(*c)->data = num;
// 	}
// 	else
// 		*c = chg_tree(*c);

// 	(*root)->lev = lev_modify(*root);
// 	printf("%p\n", (*c));
// 	printf("root -> lev = %d\n", (*root)->lev);
// 	abs = lev_chk(*p);
// 	abs = (abs > 0) ? abs : -abs;
// 	if(abs > 1)
// 		*root = rotation(*root, rot_chk(*root, num));
// 	printf("print p \n");
// 	printf("\n\n");
// 	printf("tmp = %p \n", tmp);
// 	printf("p = %p\n", *p);
// }



int main(void)
{
	int i;
	int data[20] = {10, 11, 12, 13, 14, 15, 9, 8, 7, 6,
			5, 4, 3, 16, 17, 2, 18, 19, 1, 20};
	avl_tree *root = NULL;

	for(i = 0; i < 20; i++)
		avl_ins(&root, data[i]);

	printf("after insertion\n");
	print_tree(root);
	printf("\n\n");
	avl_del(&root, &root, 5);

	printf("\n\n\n");
	print_tree(root);

	return 0;
}

