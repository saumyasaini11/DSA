//linked list questions on geeks for geeks

//Q1 create a function to Remove loop in Linked List
void removeLoop(Node* head) 
{
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    bool isLoopFound = false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            isLoopFound = true;
            break;
        }
    }

    if (isLoopFound) {
        slow = head;

        if (slow != fast) {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = nullptr;
        } else {
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = nullptr;
        }
    }
}


 //Q2: create a function to Detect Loop in linked list
 bool detectLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head;

        while ((fast != nullptr) && (fast->next != nullptr)) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
    }

//Q3: create a function to Delete a Node in Single Linked list
Node* deleteNode(Node *head, int x) 
{
    if (x == 1) {
        return head->next;
    }

    int a = 1;
    Node* temp = head;

    while (a != x - 1) {
        temp = temp->next;
        a++;
    }

    temp->next = temp->next->next;

    return head;
}
//Q4: create  a function to Linked List Insertion . Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) 
{
       if(head==NULL)
    {
    Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->data=x;
	new_node->next=NULL;
	return new_node;
    }

	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->data=x;
	new_node->next=head;
	return new_node;

}
//Q5: Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  
{
       if(head==NULL)
    {
        Node *new_node=(Node*)malloc(sizeof(Node));
	    new_node->data=x;
	    new_node->next=NULL;
	    return new_node;
    }
    
    Node *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    
	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->data=x;
	new_node->next=NULL;
	temp->next=new_node;
	return head;

}

//Q6:create a function to Count nodes of linked list
int getCount(struct Node* head)
{
    
        int len=0;
        if(head==NULL)
        return 0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;

}

//Q7: create a function to Check If Circular Linked List
bool isCircular(Node *head)
{
   if(head==NULL)
    return 0;
    
    struct Node* temp=head->next;
    
    while(temp!=NULL)
    {
        if(temp->next==head)
        return 1;
        
        temp=temp->next;
    }
    
    
    return 0;

}

//Q8: create a function to Find length of Loop
Node* detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while ((fast != nullptr) && (fast->next != nullptr)) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return slow;
        }
    }

    return nullptr;
}

int countNodesinLoop(Node* head) {
    if (head == nullptr)
        return 0;
    Node* p = detectLoop(head);
    if (p == nullptr)
        return 0;
    int count = 0;
    Node* temp = p;
    while (temp->next != p) {
        count++;
        temp = temp->next;
    }
    return count + 1;
}

//Q9: create a function to Print Linked List elements
void display(Node *head)
{
      Node *temp = head;
    
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Q10 :create a function to Reverse a Doubly Linked List
Node* reverseDLL(Node * head)
{
         Node* currptr = head;
    Node* prevptr = NULL;
    Node* nextptr;
        
    while(currptr != NULL) {
        nextptr = currptr -> next;
        currptr -> prev = nextptr;
        currptr -> next = prevptr;
            
        prevptr = currptr;
        currptr = nextptr;
    }
     return prevptr;

}

//Q11: create a function to Linked List Length Even or Odd..
int isLengthEvenOrOdd(struct Node* head) 
{
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return(count%2);
}

//Q12: create a function to find Nth node from end of linked list
int getNthFromLast(Node *head, int n)
{
        if(head==NULL)
    return -1;
    int len=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    temp=head;
    if(len-n<0)
    return -1;
    
    int i=0;
    while(i<len-n){
    temp=temp->next;
    i++;}
    
    return temp->data;

}
