#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left, *right;
};

struct node* newNode(int item)
{
  struct node* temp=(struct node*) malloc(sizeof(struct node));
  temp->data=item;
  temp->left=temp->right=NULL;
  return temp;
}
struct node* insert(struct node* node, int item)
{
 if(node==NULL)
   return newNode(item);
 if(item< node->data)
   node->left=insert(node->left,item);
 else if(item> node->data)
   node->right=insert(node->right,item);
 return node;
}
void inorder(struct node* temp)
{
 if (temp != NULL) {
		inorder(temp->left);
		printf("%d -->", temp->data);
		inorder(temp->right);
	}
}
int main()
{
  struct node* root = NULL;
  int i,key,n,arr[10];
  printf("Enter the number of elements you want to insert: ");
  scanf("%d",&n);
  printf("Enter the elements: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  root=insert(root,arr[0]);
  for(i=1;i<n;i++)
  {
   insert(root,arr[i]);
  }
  inorder(root);
  printf("\nThe root is: %d",root->data);
  return 0;
}
