#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <stdbool.h>


#define SIZE 20


struct DataItem
{
	int data;
	
	int key;

};


struct DataItem* hashArray[SIZE];

struct DataItem* dummyItem;

struct DataItem* item;


int hashCode(int key) 
{
	return key % SIZE;

}


struct DataItem *search(int key) 
{

         //get the hash

         int hashIndex = hashCode(key);


         //move in array until an empty

         while(hashArray[hashIndex] != NULL)
	 {


             if(hashArray[hashIndex]->key == key)
	      
		 return hashArray[hashIndex];


            //go to next cell

             ++hashIndex;


           //wrap around the table

            hashIndex %= SIZE;

        }


       return NULL;

}


void insert(int key,int data) 
{


      struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));

      item->data = data;

      item->key = key;


      //get the hash

      int hashIndex = hashCode(key);


      //move in array until an empty or deleted cell

       while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) 
       {

          //go to next cell

          ++hashIndex;


          //wrap around the table

          hashIndex %= SIZE;

     }


     hashArray[hashIndex] = item;

}


struct DataItem* delete(struct DataItem* item) {

     int key = item->key;


    //get the hash

    int hashIndex = hashCode(key);


    //move in array until an empty

    while(hashArray[hashIndex] != NULL) {


    if(hashArray[hashIndex]->key == key) {

     struct DataItem* temp = hashArray[hashIndex];


     //assign a dummy item at deleted position

     hashArray[hashIndex] = dummyItem;

      return temp;

     }


      //go to next cell

     ++hashIndex;


      //wrap around the table

     hashIndex %= SIZE;

    }


    return NULL;

}


void display() {
printf("KEY AND ELEMENTS ARE \n");
int i = 0;


for(i = 0; i<SIZE ; i++) {


if(hashArray[i] != NULL)
{
	if(hashArray[i]->key==-1)
		i++;
	else
                printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
}

else

printf(" ~~ ");

}


printf("\n");

}


int main() {

dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));

dummyItem->data = -1;

dummyItem->key = -1;

int n, key,i,k;
while (1)
{
	printf("Enter 1. to insert 2. for display 3. for searching 4. for delete 5.exit\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:/*printf("HOW MANY ELEMENTS YOU WANT TO INSERT\n");
		       scanf("%d",&n);*/
		      // while(n!=0)
		      // {
			       printf("Enter the key and element you want to insert\n");
		       	       scanf("%d%d",&key,&i);
			       insert(key,i);
			       n--;
		      // }
		       break;
		case 2:display();
		       break;
		case 3:printf("Enter the key to be searched\n");
		       scanf("%d",&k);
		       item = search(k);
		       printf("Element corresponding to key %d searched \n",k);
		       if(item != NULL) 
		       {
			       printf("Element found: %d\n", item->data);
		       } 
		       else
		       {
			       printf("Element not found\n");
		       }
                      break;
               case 4:printf("Enter the key corrresponding to which  to be deleted \n");
		      scanf("%d",&k);
		      item=search(k);
		      delete(item);
		      break;

/*item = search(k);
printf("After deleting this item  \n");

if(item != NULL) {

printf("Element found: %d\n", item->data);

} else {

printf("Element not found\n");

}*/
		      case 5:printf("OPERATION COMPLETE\n");
		             exit(0);
		      default:printf("Wrong entry try again\n");
		              break;

              }

}
}
