#include <stdio.h>
#include <conio.h>
#include <malloc.h>

// Cau truc du lieu cua bai toan
typedef struct node{
	
	int data;
	struct node *next;
	
}*Node ;

// Khoi tao first, last la con tro tro den phan tu dau tien va cuoi cung cua list
Node first, last;

// Ham them phan tu vao list
void add( int dulieu )
{
	Node temp;
	temp = ( Node )malloc(sizeof( struct node )); // cap phat vung nho cho node moi
	
	temp->data = dulieu; // gan gia tri data cua node moi
	
	temp->next = first; // node moi tro ve phan tu dau tien
	
	last->next = temp; // con tro next cua phan tu cuoi cung tro den node moi
	
	last = temp; // node moi tro thanh phan tu cuoi cung moi
}
int main(){
	/* Khoi tao N: so nguoi choi
	M: so dem
	i: bien chay
	size: so luong nguoi choi hien tai*/
	
	int N, M, i, size;
	printf(" So nguoi : ");
	scanf("%d", &N);
	printf(" So M: ");
	scanf("%d", &M);
	
	if( N < 1 || M < 1) printf(" Khong co ai chien thang "); // Neu khong co nguoi nao thi khong co ai chien thang
	
	else{
	first = ( Node )malloc(sizeof( struct node ));	// cap phat vung nho cho phan tu dau tien
	
	first->data = 1; 
	
	last = first; // phan tu dau tien cung chinh la phan tu cuoi cung
	
	for( i = 2; i <= N; i++){ // them cac phan tu con lai tu 2 den n
		add( i );
	}
	
	size = N; // ban dau co N nguoi
	Node ptr = last; // dat con tro chay la nguoi cuoi cung
	// Khi bat dau dem thi dem tu nguoi dau tien
	while( size > 1 ){ // neu con hon 1 nguoi
		
		i = 1;
		// tim nguoi choi thu M theo luat
		while( i < M ){ // dem tu 1 den M-1
			
			ptr = ptr->next; // truyen den nguoi tiep theo
			i++;
		}
		ptr->next = ptr->next->next; // nguoi thu M bi loai
		// nguoi sau nguoi thu M-1 la nguoi thu M+1
		size--; // so nguoi hien tai giam di 1

	}
	printf(" Nguoi thu %d la nguoi chien thang", ptr->data); // in ra nguoi choi cuoi cung
    }
    return 1;
}
