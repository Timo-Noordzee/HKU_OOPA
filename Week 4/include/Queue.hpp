#include <iostream>

// Template Declaration
template <typename T>
class Queue {
   public:
    Queue();
    ~Queue();
    void push(T e);
    T pop();
    int size();

   private:
    typedef struct _node {  //Create a struct containing the date value and a pointer to the next object in the queue
        T data;
        _node *next;
    } node;
    node *root;
};

template <typename T>
Queue<T>::Queue() : root(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    node *tmp;              //Create a placeholder node for iteration
    while (root) {          //While the root node isn't null
        tmp = root;         //Assign the root node to the placeholder node
        root = root->next;  //Assign the root node to it's next value
        delete tmp;         //Delete the previous root node
    }
}

template <typename T>
void Queue<T>::push(T value) {
    node *ptr = new node;   //Create a new node for the new value
    ptr->data = value;      //Assign the given value to the node's data field
    ptr->next = nullptr;    //Set the node's next pointer to null since it's the last node in the queue
    if (root == nullptr) {  //Check if the root pointer is null (meaning the queue is empty)
        root = ptr;         //Make the newly created node the root node of the queue
        return;
    }

    node *current = root;                //If the root node isn't null (meaning the queue isn't empty) create a placeholder node for iteration
    while (current) {                    //While the current node isn't null
        if (current->next == nullptr) {  //Check if the next node is null (meaning it's currently the last node in the queue)
            current->next = ptr;         //Assign the newly added node as it's next value
            return;
        }
        current = current->next;  //Set the current node to it's next value for iteration
    }
}

template <typename T>
T Queue<T>::pop() {
    if (root == nullptr) return NULL;  //Return null if the queue is empty
    node *tmp = root;                  //Store the root node in a temp node
    T value = root->data;              //Assign the return value to the root's node data value
    root = root->next;                 //Set the root's node equal to it's next value
    delete tmp;                        //Delete the previous root node
    return value;
}

template <typename T>
int Queue<T>::size() {
    node *current = root;         //Create a placeholder node for iteration;
    int size = 0;                 //Create an int for the size
    while (current) {             //While the current node isn't null (meaning it is a node in the queue)
        current = current->next;  //Set the current node equal to it's next value for iteration
        size++;                   //Increate the size by one
    }
    return size;
}