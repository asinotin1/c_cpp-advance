#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 5

typedef struct {
    int8_t rear;
    int8_t front;
    int8_t arry[SIZE];
} Queues;

void QueuesInit(Queues *queue)
{
    queue->rear = -1;
    queue->front = -1;
}

// kiểm tra xem hàng đợi có rỗng hay không
bool isEmpty(Queues *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// kiểm tra xem hàng đợi đã đầy hay chưa
bool isFull(Queues *queue)
{
    return (queue->rear + 1) % SIZE == queue->front;
}

// chèn phần tử vào hàng đợi queue
void enqueue(Queues *queue, uint8_t value)
{
    if (isFull(queue))
    {
        printf("\n Hang doi da day.");
        return;
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            queue->rear = (queue->rear + 1) % SIZE;
        }
        queue->arry[queue->rear] = value;
    }
}

// loại bỏ phần tử đầu tiên của hàm queue
int8_t dequeue(Queues *queue)
{
    if (isEmpty(queue))
    {
        printf("\n Hang doi rong.");
        return -1;
    }
    else
    {
        int8_t item = queue->arry[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % SIZE;
        }
        return item;
    }
}

// lấy phần tử ở phía trước hàng đợi
int8_t front(Queues *queue)
{
    if (isEmpty(queue))
    {
        printf("\n Hang doi rong.");
        return -1;
    }
    else
    {
        return queue->arry[queue->front];
    }
}

// trả về phần tử ở cuối và không xóa phần tử đó 
int8_t rear(Queues *queue)
{
    if (isEmpty(queue))
    {
        printf("\n Hang doi rong.");
        return -1;
    }
    else
    {
        return queue->arry[queue->rear];
    }
}

// trả về kích thước hàng đợi
int8_t size(Queues *queue)
{
    if (isEmpty(queue))
    {
        printf("\n Hang doi rong.");
        return -1;
    }
    else
    {
        return (queue->rear - queue->front + SIZE) % SIZE + 1;
    }
}

int main(int argc, char const *argv[])
{
    Queues queue;
    QueuesInit(&queue);
    enqueue(&queue, 7);
    enqueue(&queue, 8);
    enqueue(&queue, 6);
    printf("front: %d, rear: %d, size: %d\n", queue.front, queue.rear, size(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("front: %d, rear: %d, size: %d\n", queue.front, queue.rear, size(&queue));
    printf("Front item: %d, Rear item: %d\n", front(&queue), rear(&queue));
    return 0;
}
