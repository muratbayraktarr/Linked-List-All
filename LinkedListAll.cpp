#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct node
{
	int data;
	struct node *next;
}*newNode,*temp,*start,*current, *del, *last;

int main()
{
	setlocale(LC_ALL, "Turkish");
	int data,key,i=0;
	int c = 1;
	
	while(c != 0)
	{
		printf("1 - Link Listed Olustur\n2 - Listeye Eleman Ekle\n3 - Listeden Eleman Sil\n4 - Listeyi G�r�nt�le\n5 - Listeyi Temizle\n6 - Listenin Ba��na Eleman Ekle\n7 - Bir say�dan �nce eleman ekle\n8 - Bir say�dan sonra eleman ekle\n9 - Program Sonland�r�ld�\n");
		scanf("%d",&c);
	
		switch(c)
		{
			case 1:
				start = NULL;
				current = (node *)malloc(sizeof(node));
				temp = (node *)malloc(sizeof(node));
				printf("Linked List Olusturuldu\n");
				break;
			case 2:
				if(start == NULL)
				{ // Diziye eleman ekleme 1. eleman
					start = (node *)malloc(sizeof(node));
					printf("Enter first data :");
					scanf("%d",&data);
					start -> data = data;
					start -> next = NULL;
					current = start;
				
					printf("Dizinin ilk eleman� girildi.\n");
					break;
				}	
				else
				{ // Diziye arka arkaya di�er elemanlar� ekleme
					newNode = (node *)malloc(sizeof(node));
					printf("Enter next data :");
					scanf("%d",&data);
					newNode -> data = data;
					newNode -> next = NULL;
					current -> next = newNode;
					current = newNode;
					printf("%d say�s� diziye eklendi\n",data);
					break;
				}
			
			case 3: // Diziden eleman silme
				printf("Silmek istediginiz eleman� giriniz :");
				scanf("%d",&key);
				temp = start;
				while(temp != NULL)
				{//Diziden Eleman Silme
					if(temp->next->data == key)
					{
						del = temp->next;
						temp->next = temp->next->next;
						printf("Dizinin %d adresindeki %d degeri silinmistir.\n",del,del->data);
						del = NULL;
						free(del);
						break;
					}
					else if(start->data == key)
					{
						del = start;
						start = start -> next;
						printf("Dizinin %d adresindeki %d degeri silinmistir.\n",del,del->data);
						del = NULL;
						free(del);
						break;

					}
					else
					{
						temp = temp -> next;
					}
				}
				break;
			case 4:
				temp = start;
				while(temp != NULL)
				{
					printf("%d. Data : %d, Address : %d, Next Address : %d\n",++i,temp->data,temp,temp->next);
					temp = temp -> next;
				}
				i=0;
				break;
			case 5:
				start = NULL;
				current = NULL;
				temp = NULL;
				free(current);
				free(start);
				free(temp);
				break;
			case 6://L�STEN�N BA�INA ELEMAN EKLEME
				temp = (node *)malloc(sizeof(node));
				printf("Listenin ba��na eklenecek say�y� giriniz:");
				scanf("%d",&data);
				temp -> data = data;
				temp -> next = start;
				start = temp;
				printf("%d Say�s� listenin ba��na eklenmi�tir.\n",data);
				break;
			case 7://SAYIDAN �NCE ELEMAN EKLEME
				temp = (node *)malloc(sizeof(node));
				temp = start;
				newNode = (node *)malloc(sizeof(node));
				printf("Hangi say�dan �ncesine eleman eklenecek ?");
				scanf("%d",&key);
				printf("Eklenecek say�y� giriniz :");
				scanf("%d",&data);
				newNode -> data = data;
				while(temp != NULL)
				{
					if(temp->next->data == key)
					{
						newNode->next = temp->next;
						temp->next = newNode;
						break;
						printf("%d say�s� %d say�s�n�n �ncesine ba�ar�yla eklendi",data,key);
						break;
					}
					else
					{
						temp = temp->next;
					}
				}
				break;
			case 8://SONRASINA ELEMAN EKLEME
				temp = (node *)malloc(sizeof(node));
				temp = start;
				newNode = (node *)malloc(sizeof(node));
				printf("Hangi say�dan sonras�na eleman eklenecek ?");
				scanf("%d",&key);
				printf("Eklenecek say�y� giriniz :");
				scanf("%d",&data);
				newNode -> data = data;
				while(temp != NULL)
				{
					if(temp->data == key)
					{
						newNode->next = temp->next;
						temp->next = newNode;
						printf("%d say�s� %d say�s�n�n sonras�na ba�ar�yla eklendi",data,key);
						break;
					}
					else
					{
						temp = temp->next;
					}
				}
				break;
			case 9:
				c = 0;
				printf("Program sonland�r�ld�.");
				
				
				
		}
	}
	
	
		
}
