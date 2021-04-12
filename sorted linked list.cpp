#include<iostream>
using namespace std;
//Creating template type linked list class
template <class T > class Nodelist
{
private:
	//Making a struct of Node
	template <class T>struct Node
	{
		T data;//data to be store in nodes
		Node* next;//to store address of next node
		Node(T data) //parameterized constructor
		{
			this->data = data;
			this->next = NULL;
		}
	};
	Node<T>* head; //start of the list
	Node<T>* cursor;//current item of the list
public:
	//default constructor
	//stores Null in the private data members of list
	Nodelist() 
	{
		head = NULL;
		cursor = NULL;
	}
	//Insert function takes one template type argument
	//It inserts new node in list and make list sorted
	//it return no value as its total working is done in the function
	void insert(T newItem)
	{
		Node<T>* ptr = new Node<T>(newItem);
		if(head!=NULL && head->next!=NULL)
		{
			Node<T>* prenode = head;
			Node<T>* curnode = head->next;
			while (curnode != NULL)
			{
				if (prenode->data < ptr->data && curnode->data > ptr->data)
				{
					cursor=prenode;
					break;
				}
				else
				{
					prenode = curnode;
					curnode = curnode->next;
				}
			}
			if (curnode != NULL)
			{
				cursor = curnode;
			}

			ptr->next = cursor->next;
			cursor->next = ptr;
			
		}
		else if (head == NULL)
		{
			ptr->next = NULL;
			cursor = ptr;
			head = cursor;
		}
		else
		{
			if (head->data > ptr->data)
			{
				Node<T>* prenode = head;
				head = ptr;
				ptr->next = prenode;
			}
		}

	}
	//showstructure takes no arguments
	//Display the entire list
	//It return no value
	void showStructure()const
	{
		if (head == NULL)
		{
			cout << "    List Is Emptyyyyyyyyyy  " << endl;
		}
		else
		{
			Node<T>* ptr = head;
			do
			{
				cout << ptr->data << endl;
				ptr = ptr->next;
			} while (ptr != NULL);
		}
	}
	//remove function takes no arguments 
	//it remove the item pointed by the cursor from list
	//it return no value
	//after removing node remaining list remains sorted
	void remove()
	{
		if (head == NULL)
		{
			cout << "List is emptyyyyyyyyyyyyyyy" << endl;
		}
		else
		{
			if (cursor == head && cursor->next == NULL)
			{
				delete head;
				cursor = NULL; head = NULL;
			}
			else if (cursor->next == NULL)
			{
				Node<T>* prenode = head;
				Node<T>* curnode = head->next;
				while (curnode->next != NULL)
				{
					prenode = curnode;
					curnode = curnode->next;
				}
				delete curnode;
				prenode->next = NULL;
				cursor = head;
			}
			else if (cursor == head)
			{
				Node<T>* curnode = cursor;
				delete curnode;
				cursor = cursor->next;
				head = head->next;
			}
			else
			{
				Node<T>* prenode = head;
				Node<T>* curnode = head->next;
				while (curnode != cursor)
				{
					prenode = curnode;
					curnode = curnode->next;
				}
				prenode->next = curnode->next;
				cursor = curnode->next;
				delete curnode;
			}

			cout << " node REmoved successfullyyyyyyyyyyyyy" << endl;
		}


	}
	//isEmpty takes no arguments 
	//It checks if the list is empty or not
	//it return true if list is empty and false otherwise
	bool isEmpty() const
	{
		if (head == NULL)
		{
			return true;
		}
		else return false;
	}
	//gotobeginning is a cursor function and takes no arguments
	//it is used to move the cursor at the beginning of list
	//it returns no value
	void gotoBeginning()
	{
		cursor = head;
	}
	//gotoend is a cursor function and takes no arguments
	//it is used to move the cursor at the end of list
	//it returns no value
	void gotoEnd()
	{
		Node<T>* curnode = head->next;
		while (curnode->next != NULL)
		{
			curnode = curnode->next;
		}
		cursor = curnode;
	}
	//gotobeNext is a cursor function and takes no arguments
	//it is used to move the cursor one node foward
	//it returns true if cursor could move next and false otherwise
	bool gotoNext()
	{
		if (cursor->next != NULL && cursor != NULL)
		{
			cursor = cursor->next;
			return true;
		}
		else return false;
	}
	//gotobeNext is a cursor function and takes no arguments
	//it is used to move the cursor one node backward
	//it returns true if cursor could move next and false otherwise
	bool gotoPrior()
	{
		if (cursor != head && cursor != NULL)
		{
			Node<T>* prenode = head;
			Node<T>* curnode = head->next;
			while (curnode != cursor)
			{
				prenode = curnode;
				curnode = curnode->next;
			}
			cursor = prenode;
			return true;
		}
		else return false;
	}
	//getCursor takes no argument
	//it is used to get data of the node pointed by the cursor
	//It returns the template type value of current node
	Node<T> getCursor()
	{
		Node<T> obj1(0, NULL);
		obj1.data = cursor->data;

		return obj1;
	}
	//desctrutor of nodelist
	//delete all the values and pointers
	~Nodelist() //destructor
	{
		if (head == NULL)
		{
			
		}
		else
		{
			Node<T>* prenode = head;
			Node<T>* curnode = head->next;
			while (curnode != NULL)
			{
				delete prenode;
				prenode = curnode;
				curnode = curnode->next;
			}
			delete prenode;
			delete curnode;
			head = NULL;
		}

	}
};

int main()
{

	Nodelist<int> l1;
	//l1.showStructure();
	l1.insert(45);
	//l1.showStructure();
    l1.insert(33);
	l1.showStructure();
	//l1.search("ghgdhh");
	//l1.replace(b1);
	//l1.gotoPrior();
	//l1.remove();
	//b2 = l1.getCursor();
	//l1.showStructure();
	//l1.gotoNext();
	//l1.getCursor();
	//l1.insert(b2);
	//l1.gotoBeginning();
	//l1.insert(b1);
	//l1.getCursor();
	//l1.gotoEnd();
	//l1.insert(b2);
	//l1.getCursor();

	//l1.showStructure();
}