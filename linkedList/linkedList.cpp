

#include <iostream>


using namespace std;

class Node {

public:
	int key;
	int data;
	Node* Next;

	//default constructor
	Node()
	{
		key = 0;
		data = 0;
		Next = NULL;
	}
	Node(int data, int key)
	{
		this->key = key;
		this->data = data;
		Next = NULL;
	}
};

class ListNode {
public:
	Node* head;

	ListNode()
	{
		head = NULL;
	}
	ListNode(Node* n)  //passing the address of node
	{
		head = n;
	}

	Node* nodeExists(int key)  // traversing from node to node to match with the node that has the key given
	{
		Node* temp = NULL; // nodes does not exist

		Node* ptr = head;
		while (ptr != NULL)
		{
			if (ptr->key == key)
			{
				temp = ptr;  // node exists
			}
			ptr = ptr->Next;
		}
		return temp;
	}

	void appendNode(Node* n)
	{
		if (nodeExists(n->key) != NULL) // node exists with the same key as the new node being created
		{
			cout << "Node exists with key value: " << n->key << ". Append another node with a different key value" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node Appended" << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr->Next != NULL)
				{
					ptr = ptr->Next;
				}
				ptr->Next = n;
				cout << "Node Appended" << endl;
			}
		}
	}

	void prependNode(Node* n)
	{
		if (nodeExists(n->key) != NULL) // node exists with the same key as the new node being created
		{
			cout << "Node exists with key value: " << n->key << ". Append another node with a different key value" << endl;
		}
		else
		{
			n->Next = head;
			head = n;
			cout << "Node Prepended" << endl;
		}
	}

	void insertNode(int key, Node* n)
	{
		Node* ptr = nodeExists(key); // accessing a node by key value
		if (ptr == NULL)
		{
			cout << "No node exists with key value: " << endl;
		}
		else
		{
			if (nodeExists(n->key) != NULL) // node exists with the same key as the new node being created
			{
				cout << "Node exists with key value: " << n->key << ". Append another node with a different key value" << endl;
			}
			else
			{
				n->Next = ptr->Next;
				ptr->Next = n;
				cout << "Node Inserted" << endl;
			}
		}
	}

	void deleteNode(int key)
	{
		if (head == NULL)
		{
			cout << "list already empty" << endl;
		}
		else if (head != NULL)
		{
			if (head->key == key)
			{
				head = head->Next;
				cout << "Node deleted with key value : " << key << endl;
			}
			else
			{
				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->Next;
				while (currentptr != NULL)
				{
					if (currentptr->key == key)
					{
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr = prevptr->Next;
						currentptr = currentptr->Next;
					}
					if (temp != NULL)
					{
						prevptr->Next = temp->Next;
						cout << "Node deleted with key value: " << key << endl;
					}
					else
					{
						cout << "Node doesnt exist with key value: " << key << endl;
					}
				}
			}
		}
	}

	void updateNode(int key, int data)
	{
		Node* ptr = nodeExists(key);
		if (ptr != NULL)
		{
			ptr->data = data;
			cout << "Node data updated successfully" << endl;
		}
		else
		{
			cout << "Node doesnt exist with key value: " << key << endl;
		}
	}

	void printList()
	{
		if (head == NULL)
		{
			cout << "No nodes in the list" << endl;
		}
		else
		{
			cout << endl << "linked list values: ";
			Node* temp = head;

			while (temp != NULL) {
				cout << "(" << temp->key << ", " << temp->data << ") -->";
				temp = temp->Next;
			}
		}
	}
};





int main() {

	ListNode s;
	int option;
	int key1, k1, data1;
	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl << endl;

		cin >> option;
		Node* n1 = new Node(); // heap memory allocation 


		switch (option) {
		case 0:
			break;

		case 1:
			cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.appendNode(n1);
			//cout<<n1.key<<" = "<<n1.data<<endl;
			break;

		case 2:
			cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.prependNode(n1);
			break;

		case 3:
			cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
			cin >> k1;
			cout << "Enter key & data of the New Node first: " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.insertNode(k1, n1);
			break;

		case 4:

			cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
			cin >> k1;
			s.deleteNode(k1);
			break;

		case 5:
			cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
			cin >> key1;
			cin >> data1;
			s.updateNode(key1, data1);
			break;

		case 6:
			s.printList();
			break;

		case 7:
			system("cls");
			break;

		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);


	return 0;
}