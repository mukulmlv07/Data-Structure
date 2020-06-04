#include<iostream>
using namespace std;
class Array{
	private:
		int *A;
		int size;
		int length;
	public:
		void FillElements();
		void Display();
		
};
void Array::FillElements(){
	cout<<"\nEnter Size of Array\n";
	cin>>size;
	A=new int[size];
	length=0;
	int n,i;
	cout<<"\n Enter total number of elements\n";
	cin>>n;
	cout<<"\nEnter elements of array\n";
	for(i=0;i<n;i++){
		cin>>A[i];
	}
	length=n;
}
void Array::Display(){
	int i;
	cout<<"\nElemets Are:\n";
	for(i=0;i<length;i++){
		cout<<A[i]<<endl;
	}
	
}
//void end(struct Array *p){
//	int x;
//	if(p->length<p->size){
//		printf("\nEnterv element to Append\n");
//		scanf("%d",&x);
//		p->A[p->length++]=x;
//	}
//	else{
//		printf("\nArray is full\n");
//	}
//}
//void Insert(struct Array *p){
//	int index;
//	if(p->length < p->size){
//		printf("\nEnter index to insert\n");
//		scanf("%d",&index);
//		if(index>-1 && index<p->size){
//			int i;
//			for(i=p->length-1;i>=index;i--){
//				p->A[i+1]=p->A[i];
//			}
//			printf("\nEnter Element to insert\n");
//			scanf("%d",&p->A[index]);
//			if(index+1>p->length){
//				p->length+=index+1-p->length;}
//			else{
//			p->length++;
//			}
//		}
//		else{
//			printf("\nIndex out of range\n");
//		}
//	}
//	else{
//		printf("\nArray is full\n");
//	}
//		
//	
//}
//void Delete(struct Array *p){
//	int x,i;
//	printf("Enter elemenent to delete\n");
//	scanf("%d",&x);
//	int index=-1;
//	for(i=0;i<p->length;i++){
//		if(p->A[i]==x){
//			index=i;
//		}
//	}
//	if(index!=-1){
//		for(i=index;i<p->length-1;i++){
//			p->A[i]=p->A[i+1];
//		}
//		p->length--;
//	}
//	else{
//		printf("\nElement isn't available inside array\n");
//	}
//}
//void DeleteByIndex(struct Array *p){
//	
//	int x,i;
//	printf("\nEnter index you want to delete\n");
//	scanf("%d",&x);
//	if(x>-1 && x<p->length){
//		for(i=x;i<p->length;i++){
//			p->A[i]=p->A[i+1];
//		}
//		p->length--;
//		printf("\nSuccesfully Deleted\n");
//	}
//	else{
//		printf("\nIndex out of Range\n");
//	}
//	
//}
//void swap(int *p1,int *p2){
//	int temp;
//	temp=*p1;
//	*p1=*p2;
//	*p2=temp;
//}
//int LinearSearch(struct Array *p){
//	int i,key;
//	printf("\enter key value\n");
//	scanf("%d",&key);
//	for(i=0;i<p->length;i++){
//		if(p->A[i]==key){                      //this is transposition method
//			if(i>0){
//				swap(&p->A[i],&p->A[i-1]);   //or 	swap(&p->A[i],&p->A[0]) this is move to front/head
//				i=i-1;                       // i=0   
//			}
//			return i;
//		}
//	}
//	return -1;
//
//}
//int BinSearch(struct Array p){
//	int low=0,high=p.length-1;
//	int key;
//	printf("\enter key value\n");
//	scanf("%d",&key);
//	while(low<=high){
//		int mid=(low+high)/2;
//		if(key==p.A[mid]){
//			return mid;
//		}
//		else if(key<p.A[mid]){
//			high=mid-1;
//		}
//		else{
//			low=mid+1;
//		}
//	}
//	return -1;
//}
//int RBinSearch(struct Array p,int low,int high,int key){
//	if(low<=high){
//		int mid=(low+high)/2;
//		if(p.A[mid]==key){
//			return mid;
//		}
//		else if(p.A[mid]>key){
//			RBinSearch(p,low,mid-1,key);
//		}
//		else{
//			RBinSearch(p,mid+1,high,key);
//		}
//	}
//}
//int Get(struct Array p){
//	int index;
//	printf("\nEnter Inder\n");
//	scanf("%d",&index);
//	if(index<p.length && index>-1){
//		return p.A[index];
//	}
//	else{
//		printf("\nInvalid Index\n");
//	}
//}
//int Set(struct Array *p,int index,int value){
//	if(index<p->length && index>-1){
//		p->A[index]=value;
//	}
//	else{
//		printf("\nInvalid Ixdex\n");
//	}
//}
//int Max(struct Array p){
//	int i,max=p.A[0];
//	for(i=1;i<p.length;i++){
//		if(p.A[i]>max){
//			max=p.A[i];
//		}
//	}
//	return max;
//}
//int Min(struct Array p){
//	int i,min=p.A[0];
//	for(i=1;i<p.length;i++){
//		if(p.A[i]<min){
//			min=p.A[i];
//		}
//	}
//	return min;
//}
//int Sum(struct Array p,int length){
//	if(length<0){
//		return 0;
//	}
//	return Sum(p,length-1)+p.A[length-1];
//}
//void Reverse(struct Array *p){
//	int i,j;
//	for(i=0,j=p->length-1;i<j;i++,j--){
//		int temp=p->A[i];
//		p->A[i]=p->A[j];
//		p->A[j]=temp;
//	}
//}
//void InsertInSorted(struct Array *p,int e){
//	int index=0;
//	while(e>p->A[index] && index < p->length){
//		index+=1;
//	}
//	if(index==p->length){
//		p->A[p->length]=e;
//	
//	}
//	else{
//		int i;
//		for(i=p->length-1;i>=index;i--){
//			p->A[i+1]=p->A[i];
//		}
//		p->A[index]=e;
//	}
//	p->length++;
//}
//int SortorNot(struct Array p){
//	int i;
//	for(i=0;i<p.length-1;i++){
//		if(p.A[i]>p.A[i+1]){
//			return 0;
//		}
//	}
//	return 1;
//}
//void SeperateSign(struct Array *p){
//	int i=0,j=p->length-1;
//	while(i<j){
//		while(p->A[i]>=0){
//			i++;
//		}
//		while(p->A[j]<0){
//			j--;
//		}
//		if(i>j){
//			break;
//		}
//		swap(&p->A[i],&p->A[j]);
//	}
//}
//struct Array *Merge(struct Array a1,struct Array a2){
//	struct Array a5;
//	struct Array*p=&a5;
////	p=(struct Array *)malloc(sizeof(struct Array));
//	int i=0,j=0,index=0;
//	while(i<a1.length && j<a2.length){
//		if(a1.A[i]<a2.A[j]){
//			p->A[index++]=a1.A[i++];
//		}
//		else{
//			p->A[index++]=a2.A[j++];
//		}
//	}
//	for(;i<a1.length;i++){
//		p->A[index++]=a1.A[i];
//	}
//	for(;j<a2.length;j++){
//		p->A[index++]=a2.A[j];
//	}
//	p->length=a1.length+a2.length;
//	p->size=10;
//	return p;
//	
//}
//struct Array *Union(struct Array a1,struct Array a2){
//	int i=0,j=0,index=0,l=0;
//	struct Array *p=(struct Array *)malloc(sizeof(struct Array));
//	while(i<a1.length && j<a2.length){
//		if(a1.A[i]<a2.A[j]){
//			p->A[index++]=a1.A[i++];
//		}
//		else if(a1.A[i]==a2.A[j]){
//			p->A[index++]=a1.A[i++];
//			j++;
//		}
//		else{
//			p->A[index++]=a2.A[j++];
//		}
//		l++;
//	}
//	for(;i<a1.length;i++){
//		p->A[index++]=a1.A[i];
//		l++;
//	}
//	for(;j<a2.length;j++){
//		p->A[index++]=a2.A[j];
//		l++;
//	}
//	p->length=l;
//	p->size=10;
//	return p;
//}
//struct Array *Intersection(struct Array a1,struct Array a2){
//	int i=0,j=0,index=0,l=0;
//	struct Array *p=(struct Array *)malloc(sizeof(struct Array));
//	while(i<a1.length && j<a2.length){
//		if(a1.A[i]<a2.A[j]){
//			i++;
//		}
//		else if(a1.A[i]==a2.A[j]){
//			p->A[index++]=a1.A[i++];
//			j++;
//			l++;
//		}
//		else{
//			j++;
//		}	
//	}
//	p->length=l;
//	p->size=10;
//	return p;
//
//}
//struct Array *Difference(struct Array a1,struct Array a2){
//	int i=0,j=0,index=0,l=0;
//	struct Array *p=(struct Array *)malloc(sizeof(struct Array));
//	while(i<a1.length && j<a2.length){
//		if(a1.A[i]<a2.A[j]){
//			p->A[index++]=a1.A[i++];
//			l++;
//		}
//		else if(a1.A[i]==a2.A[j]){
//			j++;
//			i++;
//		}
//		else{
//			j++;
//		}	
//	}
//	for(;i<a1.length;i++){
//		p->A[index++]=a1.A[i];
//		l++;
//	}
//	p->length=l;
//	p->size=10;
//	return p;
//
//}
//

int main(){
	Array a1;
	a1.FillElements();
	a1.Display();
//	do{
//	printf("Menu:\n");
//	printf("1-Display:\n");
//	printf("2-Append:\n");
//	printf("3-Insert:\n");
//	printf("4-Delete:\n");
//	printf("5-DeleteByIndex:\n");
//	printf("6-LinearSearch:\n");
//	printf("7-BinarySearch:\n");
//	printf("8-RbinarySearch:\n");
//	printf("9-Get:\n");
//	printf("10-Set:\n");
//	printf("11-Max:\n");
//	printf("12-Min:\n");
//	printf("13-Sum:\n");
//	printf("14-Menu:\n");
//	printf("15-Reverese:\n");
//	printf("16-Inverse:\n");
//	printf("17-InsertInSort:\n");
//	printf("18-SortorNot:\n");
//	printf("19-SeperateSign:\n");
//	printf("-1:For Exit\n");
//	printf("\nEnter Your Choice:\n");
//	scanf("%d",&ch);
//	switch(ch){
//		case 1: 
//			Display(a);
//			break;
//		case 2:
//			Append(&a);
//			break;
//		case 3:
//			Insert(&a);
//			break;
//		case 4:
//			Delete(&a);
//			break;
//		case 5:
//			DeleteByIndex(&a);
//			break;
//		case 6:
//			LinearSearch(&a);
//			break;
//		case 7:
////			BinarySearch(a);
//			break;
//		case 8:
////			RBinSearch(a);]
//			break;
//		case 9:
//			Get(a);
//			break;
//		case 10:
//			//Set(&a);
//			break;
//		case 11:
//			Max(a);
//			break;
//		case 12:
//			Min(a);
//			break;
//		case 13:
////			Sum(a);
//			break;
//		case 14:
//			break;
//		case 15:
//			Reverse(&a);
//			break;
//		case 16:
////			InsertInSort(&a);
//			break;
//		case 17:
//			SortorNot(a);
//			break;
//		case 18:
//			SeperateSign(&a);
//			break;
//		case -1:
//			break;
//	}
//	}while(ch!=-1);
			
}
