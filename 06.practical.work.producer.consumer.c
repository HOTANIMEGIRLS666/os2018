#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 100

typedef struct{
	char type;
	int amount;
	char unit;
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

item *consume() {
	item *i = malloc(sizeof(item));
	while(first == last) {
	}
	memcpy(i, &buffer[last],sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void produce(item *i) {
	while((first + 1) % BUFFER_SIZE == last) {
	}
	memcpy(&buffer[first], i,sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

int main(){
	item i1, i2;

	i1.type=0;
	i1.amount=50;
	i1.unit=0;

	i2.type=1;
	i2.amount=100;
	i2.unit=1;

	produce(&i1);
	printf("After produce:\nType: %d, Amount: %d, Unit: %d, 1st: %d, Last: %d \n", i1.type, i1.amount, i1.unit, first, last);
	produce(&i2);
	printf("Type: %d, Amount: %d, Unit: %d, 1st: %d, Last: %d \n", i2.type, i2.amount, i2.unit, first, last);

	item *serveFood=consume();
	printf("After consume:\nType: %d, Amount: %d, Unit: %d, 1st: %d, Last: %d \n", serveFood->type, serveFood->amount, serveFood->unit, first, last);
	return 0;
}














