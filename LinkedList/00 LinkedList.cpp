struct Node{
	int data;
	Node* next;
};

Node* head;

void Insert(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return;
	}
	Node* temp1 = head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;
}

void Insert_front(ll data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

void Insert_at_pos(ll data, ll n){
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(n==1){
		temp->next = head;
		head = temp;
		return;
	}
	Node *temp2 = head;
	for(ll i=1; i<=n-2; i++){
		temp2 = temp2->next; // after loop temp2 point to (n-1)th node
	}
	temp->next = temp2->next; // temp2->next point to (n)th node
	temp2->next = temp;
}

void Reverse(){
	Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void Delete(ll n){
	Node *temp1 = head;
	if(n==1){
		head = temp1->next; // (2)nd node
		delete temp1;
		return;
	}
	for(ll i=1; i<=n-2; i++){
		temp1 = temp1->next; // after loop temp1 point to (n-1)th node
	}
	Node *temp2 = temp1->next; // (n)th node
	temp1->next = temp2->next; // (n+1)th node
	delete temp2;
}

void Print(){
	Node* ptr = head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

 
int32_t main(){
	IOS
	head = NULL;
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Print();
	Reverse();
	Print();
	Insert(6);
	Insert(7);
	Print();
	Insert_front(8);
	Insert_front(9);
	Print();
	Insert_at_pos(10, 3);
	Print();
	Insert_at_pos(11, 5);
	Print();
	Delete(3); // delete node at 3rd position
	Print();
}
