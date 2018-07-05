#include<stdio.h>
#include<stdbool.h>

typedef struct __s_block{
    struct __s_block *next;
    bool isfree;
    size_t size;
    void *memoryAddress;
}BLOCK;

#define BLOCK_SIZE sizeof(BLOCK)

BLOCK *allocateMemBlock(size_t size)
{
    BLOCK *block = (_SBLOCK *)sbrk(0);
    void *memadr = (void*)sbrk(0);
    void *allocate_mem = (void*)sbrk(BLOCK_SIZE + size);

    if(allocate_mem == (void*)-1){
        return NULL;
    }else{
        block->next = NULL;
        block->isfree = false;
        block->size = size;
        block->memoryAddress = memadr+BLOCK_SIZE;
        return block;
    }
}

//allocate next memory block
void allocateNextMemBlock(size_t size, BLOCK **head)
{
    BLOCK *current = *head;
    void *allocate_mem = NULL;
    void *memadr = (void*)sbrk(0);

    if(current==NULL){
        *head = allocateMemBlock(size);
    }else{
        while(current->next != NULL){
            current = current->next;
        }
        BLOCK *newblock = sbrk(0);

        allocate_mem = (void*)sbrk(BLOCK_SIZE + size);      
        if(allocate_mem == (void*) - 1){ }
        else{
            newblock->next = NULL;
            newblock->isfree = false;
            newblock->size = size;
            newblock->memoryAddress = memadr+BLOCK_SIZE;
            current->next = newblock;
      }
    }
}

void freeMemBlock(BLOCK **head)
{
    if(*head == NULL){}
    else{
        (*head)->isfree = true;
    }
}

void printMemBlocks(BLOCK *current)
{
    while(current != NULL){
        printf("isfree = %d, size = %d, memoryAddress = %p, current = %p, next-node = %p\n",
                current->isfree, current->size, current->memoryAddress, current, current->next);
        current = current->next;
    }
}

int main()
{
    BLOCK *sMemBlock = NULL;
    allocateNextMemBlock(10,&sMemBlock);
    allocateNextMemBlock(35,&sMemBlock);
    allocateNextMemBlock(62,&sMemBlock);
    printMemBlocks(sMemBlock);
    
    printf("\nAfter freeing second node\n");
    freeMemBlock(&(sMemBlock->next));
    printMemBlocks(sMemBlock);

    return 0;
}
