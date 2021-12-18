//https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-1-7-months-experienced/


struct MyList{
	struct Node{
		int val;
		Node *next[2];
		Node(int val){
			this->val = val;
			next[0] = next[1] = NULL;
		}
	};

	Node * head, *tail;
	int direction;

	MyList(){
		head = tail = NULL;
		direction = 0;
	}

	// reverse all the numbers
	void reverseAll(){
		swap(head,tail);
		direction ^= 1;
	}

	// insert a number in back side
	void insertBack(int val){
		if( tail ){
			Node * node = new Node(val);
			tail->next[direction] = node;
			node->next[direction^1] = tail;
			tail = node;
		}else{
			head = tail = new Node(val);
		}
	}

	// insert a number in front side
	void insertFront(int val){
		if( head ){
			Node * node = new Node(val);
			node->next[direction] = head;
			head->next[direction^1] = node;
			head = node;
		}else{
			head = tail = new Node(val);
		}
	}

	// print all the numbers
	void printAll(){
		Node * ptr = head;
		while( ptr ){
			cout << ptr->data <<" ";
			ptr = ptr->next[direction];
		}
	}

};



