#include <iostream>
using namespace std;

// create a class for grocery
class Grocery{
	public:
		int id;
		string name;
		string catagory;
		int price;
		string exp;
};

// create linked list
class Node{
	public:
		Grocery data;
		Node* next;
		
		// constructor that takes gorcery data
		Node(Grocery data){ 
			this->data = data;
			this->next = NULL;
		}
};


class LinkedList{
	    public:
	    // insert into the list
		// i take reference &head coz i want to change in original list
		void insert(Grocery g, Node* &head){
			Node* node = new Node(g);
			if(head == NULL){
				head = node;
				return;
			}
			Node* itr = head;
			while(itr->next != NULL){
				itr = itr->next;
			}
			itr->next = node;
		}
		
		//delete method
		void deleteFromList(Node* &head, string nm){
			Node* itr = head;
			Node* prev = NULL;
			if(head->data.name == nm){
				head = head->next;
			}
			else{
				while(itr != NULL){
					if(itr->data.name == nm){
						prev->next = itr->next;
					}
					prev = itr;
					itr = itr->next;
				}
		    }
		}
		
		//search method
		void search(Node* &head, string nm){
			Node* itr = head;
			bool f = false;
			while(itr != NULL){
				if(itr->data.name == nm){
					cout << "Item found " << nm << endl;
					cout << "\n";
					f = true;
				}
				itr = itr->next;
			}
			if(f == false){
				cout << "Item not found" << endl;
				cout << "\n";
			}
		}
		
		
		//Empty or not
		void isEmpty(Node* &head){
			if(head == NULL){
				cout << "The list is Empty" << endl;
				cout << "\n";
				return;
			}
			cout << "The list is Not Empty" << endl;
			cout << "\n";
		}
		
		
		//make the whole list NULL
		void makeNull(Node* &head){
			head = NULL;
		}
		
		//retrive a particular data
		void retrive(Node* &head, string nm){
			Node* itr = head;
			
			while(itr != NULL){
				if(itr->data.name == nm){
					cout << "Id: " << itr->data.id << endl;
					cout << "Name: "<< itr->data.name << endl;
					cout << "Catagory: "<< itr->data.catagory << endl;
					cout << "Price: "<< itr->data.price << endl;
					cout << "Exp: "<< itr->data.exp << endl;
					cout << "\n";
					break;
				}
				itr = itr->next;
			}
			
		}
		
		void insertInLL(Node* &head){
		    Grocery myGrocery;
			cout << "Type Id: ";
			cin >> myGrocery.id;
			cout << "Type name: ";
			cin >> myGrocery.name;
			cout << "Type catagory: ";
			cin >> myGrocery.catagory;
			cout << "Type price: ";
			cin >> myGrocery.price;
			cout << "Type exp: ";
			cin >> myGrocery.exp;
			
		    insert(myGrocery, head);
		    
		    cout << "\n";
        }
		
		//print method
		void print(Node* &head){
			Node* itr = head;
			
			while(itr != NULL){
				
				cout << "Id: " << itr->data.id << endl;
				cout << "Name: "<< itr->data.name << endl;
				cout << "Catagory: "<< itr->data.catagory << endl;
				cout << "Price: "<< itr->data.price << endl;
				cout << "Exp: "<< itr->data.exp << endl;
				cout << "\n";
				itr = itr->next;
			}
		}
};


int main(){
	
	//head initially points to NULL
	Node* head = NULL;
	
	LinkedList ll;

    cout << "Choose an option..." << endl;
    	 cout << '\n';
    	 cout << " 1 : insert" << endl;
    	 cout << '\n';
	     cout << " 2 : print" << endl;
	     cout << '\n';
	     cout << " 3 : delete" << endl;
	     cout << '\n';
	     cout << " 4 : search" << endl;
	     cout << '\n';
	     cout << " 5 : check empty" << endl;
	     cout << '\n';
	     cout << " 6 : retrive" << endl;
	     cout << '\n';
	     cout << " 7 : makeNULL" << endl;
	     cout << '\n';
	     cout << " 0 : exit" << endl;
	     cout << '\n';
    int x;
    while(true){
    	 cin >> x;
	    switch (x) {
	    case 1:
	        cout << "Insert items " << endl;
	        ll.insertInLL(head);
	        break;
	    case 2:
	        cout << "Printing the items in List " << endl;
	        ll.print(head);
	        break;
	    case 3:{
	    	string nm;
	        cout << "Type name which You want to delete " << endl;
	        cin >> nm;
	        ll.deleteFromList(head, nm);
	        break;
	    }
	    case 4:{
	        cout << "Enter which you want to search " << endl;
	        string a;
	        cin >> a;
	        ll.search(head, a);
	        break;
	    }
	    case 5:
	        ll.isEmpty(head);
	        break;
	    case 6:{
	    	cout << "Enter which you want to retrive " << endl;
	        string r;
	        cin >> r;
	        ll.retrive(head,r);
	        break;
	    }
	    case 7:
	    	cout << "Make list NULL" << endl;
	    	ll.makeNull(head);
	    	break;
	    default:
	        exit(false);
	        break;
	    }
	}
   
	    
}

