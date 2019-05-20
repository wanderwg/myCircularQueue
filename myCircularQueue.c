typedef struct {
	int* _array;
	int _capacity;
	int _size;//有效元素的个数
	int _front;//对头
	int _back;//队尾
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (q == NULL) {
		assert(0);
		return NULL;
	}
	q->_array = (int*)malloc(sizeof(int)*k);
	q->_size = 0;
	q->_capacity = k;
	q->_front = 0;
	q->_back = 0;
	return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	assert(obj);
	if (obj->_size == obj->_capacity)
		return false;
	obj->_array[obj->_back++] = value;
	obj->_size++;
	if (obj->_back == obj->_capacity)
		obj->_back = 0;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	assert(obj);
	if (obj->_size == 0)
		return false;
	++obj->_front;
	if (obj->_front == obj->_capacity)
		obj->_front = 0;
	obj->_size--;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	assert(obj);
	if (obj->_size == 0)
		return -1;
	else
		return obj->_array[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	assert(obj);
	if (obj->_size == 0)
		return -1;
	if (obj->_back == 0)
		return obj->_array[obj->_capacity - 1];
	return obj->_array[obj->_back - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	assert(obj);
	if (obj->_size == 0)
		return true;
	return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	assert(obj);
	if (obj->_size == obj->_capacity)
		return true;
	return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_array);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/