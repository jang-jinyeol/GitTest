#include <stdio.h>
#define MAX_N 1024
typedef struct heap {
	int arr[MAX_N];
	int size;
} heap;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void initHeap(heap* hp) {
	hp->size = 0;
}
void insert(heap* hp, int data) {
	int here = ++hp->size;

	while ((here != 1) && (data < hp->arr[here / 2])) {
		hp->arr[here] = hp->arr[here / 2];
		here /= 2;
	}
	hp->arr[here] = data;
}

int deleteData(heap* hp) {
	if (hp->size == 0) return -1;
	int ret = hp->arr[1];
	hp->arr[1] = hp->arr[hp->size--];
	int parent = 1;
	int child;

	while (1) {
		child = parent * 2;
		if (child + 1 <= hp->size && hp->arr[child] > hp->arr[child + 1])
			child++;

		if (child > hp->size || hp->arr[child] > hp->arr[parent]) break;

		swap(&hp->arr[parent], &hp->arr[child]);
		parent = child;
	}

	return ret;

}
int main() {
	heap hp;
	initHeap(&hp);

	insert(&hp, 1);
	insert(&hp, 2);
	insert(&hp, 6);
	insert(&hp, 4);
	insert(&hp, 7);
	insert(&hp, 9);
	insert(&hp, 10);
	insert(&hp, 5);
	deleteData(&hp);


}