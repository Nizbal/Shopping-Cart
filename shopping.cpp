#include<iostream>
#include<string>
#include<sstream>
#include<windows.h>

using namespace std;


// Customer Stack
struct stack									// Stack stack
{ 
	int data; 
   	stack* link; 
};

struct stack* top;

void push(int data) 
{  
	struct stack *temp = new stack(); 

	if (!temp) 
	{ 
		cout << "\nHeap Overflow"; 
		exit(1); 
	} 

	temp->data = data;
	temp->link = top;
	top = temp; 
} 
 
int Empty() 
{ 
	return top == NULL; 
} 
 
int peek() 
{ 
	 
	if (!Empty()) 
		return top->data; 
	else
		exit(1); 
} 

void pop() 
{ 
	struct stack* temp; 
	if (Empty())
	{ 
		cout << "\nStack Underflow" << endl; 
		exit(1); 
	} 
	else
	{
		
		temp = top; 
		top = top->link;  
		temp->link = NULL; 
		delete temp;		
	}
	
	cout<<"Your Trolli No is :"<<top->data<<endl; 
    cout<<"                  ___"<<endl;
	cout<<"                 /  |"<<endl;
	cout<<"  ______________/   --"<<endl;
	cout<<" |___/__ /___/_|     "<<endl;     
	cout<<" |__/___/___/__|     "<<endl;     
	cout<<" |_/___/___/___|     "<<endl;     
	cout<<"    _______/         "<<endl;
	cout<<"     O   O           "<<endl;

} 
// End of Customer Stack




// Console Animation
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 	COORD coord;
 	coord.X = x;
 	coord.Y = y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void animation()
{
	for (int i=45; i>=1; i--)
	{
		Sleep(30);
		gotoxy(1,i);
		//clreol();
	}
	for (int i=1; i<=20; i++)
	{
		//clreol();
		Sleep(40);
		gotoxy(1,i);
	}
}
// End of console Animation




// Queue1
struct QNode													// Queue Structure
{
    string cname;
    QNode *link;
};

QNode *front = NULL;
QNode *rear = NULL;

bool isempty()													//Function to check if queue is empty or not
{
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

void enqueue ( string name )									//function to enter elements in queue
{
    QNode *ptr = new QNode();
    ptr->cname= name;
    ptr->link = NULL;

    if( front == NULL )											//If inserting the first element/node
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear ->link = ptr;
        rear = ptr;
    }
}

void dequeue ()													//function to delete/remove element from queue
{
    if( isempty() )
        cout<<"Queue is empty\n";
    else
    
    if( front == rear)											//only one element/node in queue.
    {
        delete front;
        front = rear = NULL;
    }
    else
    {
        QNode *ptr = front;
        front = front->link;
        delete ptr;
    }
}

void showfront()												//function to show the element at front
{
    if( isempty())
    cout<<"Queue is empty\n";
    else
    cout<<"element at front is:"<<front->cname<<"\n";
}

void displayQueue()												//function to display queue
{  
    if (isempty())
        cout<<"Queue is empty\n";
    else
    {
        QNode *ptr = front;
        while( ptr !=NULL)
        {
            cout<<"\t"<<ptr->cname<<"\t  "<<endl;
            ptr= ptr->link;
        }
    }
}
// end of Queue




int search(int);											// 	 To search the store list
int display();												// 	 To display the items in the store list
string check(int);       									//   for checking quantity

struct LLNode												// 	 Store list structure
{
	int ID;
	string proName;											// Product name
	double proPrice;										// Price
	int quantity;											// Quantity
    struct LLNode* next;
};

struct LLNode *head=NULL;									// Head pointer to locate the beginning of the list.

void insert()												// This function inserts new items in the store
{
	system("cls");
	int id,quant;           								// id - for product id, quant - for quantity
	string name;											// Product name
	double pre;             								// pre for price
	struct LLNode *t=new LLNode;
	struct LLNode *p=head;

	cout<<"\t\t\tEnter product ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\tEnter product Name (Without spaces):- ";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	t->proPrice=pre;
	cout<<"\t\t\tEnter product quantity:-";
	cin>>quant;
	t->quantity=quant;
	
	if(head==NULL)
	{
		t->next=head;
		head=t;
	}
	else
	{
		while(p->next!=NULL)
    	{
			p=p->next;
		}
        p->next=t;
        t->next=NULL;
	}
	system("cls");
    cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}


int search(int id)                  			   			// For searching item from the list.
{
 	int count=1;
 	struct LLNode *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
			return count;
 		else
 			count++;
 		p=p->next;
	}
 	return 0;
}


void delPro()												// This function deletes a product from the list.
{
	system("cls");
	if(head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
		return;
    }
	display();
	int id;
	struct LLNode *cur=head;
	struct LLNode *pre=head;
	cout<<"\n\nEnter ID to delete that product:\n\n";
	cin>>id;
	int pos=0;
	int count=display();               
	pos=search(id);   
	
	if(pos)
	{
		if(pos==1)
		{
			head=head->next;			
			delete cur;										// To delete the List item.
		}
		else
		{
			while(cur->ID!=id)
			{            
				pre=cur;
				cur=cur->next;
			}	
			pre->next=cur->next;
			delete cur;
		}
		system("cls");
		cout<<"\n<<item is deleted>>\n";
	}
	else
	{
		system("cls");
		cout<<"\n<<<Not found>>\n\n";
	}
		
}


void modify()													// To modify the List
{
	if (head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
		return;
    }

	int id;										
	double pre;
	string pName;
	int nid; int nq;    										// pName for new name    
	
	display();
	cout<<"\n\nEnter ID to modify product Name and its price:\n";
	cin>>id;
	struct LLNode *cur=head;
	int pos=0,f=1;
	int count=display();               							//   for load no of nodes
	pos=search(id);                    							//   for check weather desire node is exist or not
	if(pos)
    {
		while(cur->ID!=id)
		{
			f=0;
			cur=cur->next;
		}
		cout<<"\nID : "<<cur->ID<<endl;
		cout<<"\nOld Name : "<<cur->proName<<endl;
		cout<<"\nOld Price : "<<cur->proPrice<<endl;
		cout<<"\nOld Quantity : "<<cur->quantity<<endl;
		cout<<endl<<endl;
		cout<<"Enter new Name:";
		cin>>pName;
		cur->proName=pName;
		cout<<"Enter new Price:";
		cin>>pre;
		cur->proPrice=pre;
		cout<<"Enter new Quantity:";
		cin>>nq;
		cur->quantity=nq;
	}
	else
		cout<<id<<" is <<<Not found>>\n\n";
}


int display()
{
	system("cls");
	int c=0;             
	struct LLNode *p=head;
	cout<<"Existing products are:\n";
	cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
	cout<<"=================================================================|\n";
	while(p!=NULL)
	{
		cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->proPrice<<"\t\t\t"<<check(p->quantity)<<endl;
		p=p->next;
		c=c+1;
	}
	cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
	return c;
}


string check(int quant)
{
	int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();

	if(quant<=0)
		return "out of stock!";
	else
		return quantity;
}


void buy()
{
    system("cls");
    display();
	string products[50];										// for display sold items
	int pay=0,no,c=0,price,id,i=1;

    if(head==NULL)
    {
		cout<<"\n<<<<There is no items to buy>>>>\n\n";
    }
	else
    {
		cout<<"How many items you wanna to buy!\n";
		cin>>no; 
        int count=display();           						// for store no of nodes in c
		if(no>count)
		{
			system("cls");
			cout<<"There are not enough products for your need"<<endl;
			return;
		}
		while (i<=no)
        {
			struct LLNode *cur=head;
            int quant,cho;   
			a:           									// quant   for quantity  and cho for choice
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            if(id==-1)
			{
				system("cls"); 
				return;
			}
	        pos=search(id);
	        if(pos)
        	{
	                        								// item is available in store
				while(cur->ID!=id)
				{
					cur=cur->next;
				}
				cout<<"How many quantities you want:";
				cin>>quant;
				if(cur->quantity<quant)
				{
					cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
					cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
					goto a;
				}
				products[c]=cur->proName;   				// this will conatin the items buy names in array; 
				c++;   
				
				pay=pay+(cur->proPrice*quant);         		// calculate Bill
				cur->quantity=cur->quantity-quant;          // change quantity
				i++;
			}
	    	else
        	{     
				cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
	    	}
		}
        string customer;
        cout<<"\n\t\t Enter Your First Name :"; 
		cin>>customer;
        enqueue(customer);
	    system("cls");
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      	{              										// show that item you have bought
        	cout<<products[i]<<"	";
       	}
        price=pay*(0.90);
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 10% discount: "<<price<<"\nThank you! for the shopping\n\n";
	}
}


void admin()
{
	system("cls");
	int ch; 
	do
	{                 										// choice for below message
		cout<<"\t\t============================================"<<endl;
		cout<<"\t\t|          Administator Portal              |"<<endl;
		cout<<"\t\t============================================"<<endl;
		cout<<"\t\t     Enter 1 for ADD a new product    "<<endl;
		cout<<"\t\t     Enter 2 to display all products   "<<endl;
		cout<<"\t\t     Enter 3 for MODIFY Existing product"<<endl;
		cout<<"\t\t     Enter 4 for Delete a particular product item"<<endl;
		cout<<"\t\t     Enter 5 for Customers List "<<endl;
		cout<<"\t\t     Enter 6 for Dequeue customer"<<endl;
		cout<<"\t\t     Enter 0 for Main Menu"<<endl;
		cout<<"\nEnter Your choice >>>";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				system("cls");
				display();
				break;
			case 3:
				modify();
				system("pause");
				system("cls");
				break;
			case 4:
				delPro();
				cout<<"\n-------Product is Deleted-------\n";
				break;
			case 5:
				system("cls");
				cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
				displayQueue();
				break;
			case 6:
				system("cls");
				cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
				dequeue();
				displayQueue();
				break;

			default: 
				system("cls");
		}
}
while(ch!=0);
}


int main() 										//  Main function
{
	for(int i=1;i<=100;i++)						//  This loop pushes 100 trollies into the stack.			
	{
		push(i);
	}

	gotoxy(17,7);
	cout<<"--------------------------------------------------"<<endl;
	gotoxy(17,8);
	cout<<"||            Shopping Club System                ||"<<endl;
	gotoxy(17,9);
	cout<<"||         Created by: Nilay Chatterjee           ||"<<endl;
	gotoxy(17,10);
	cout<<"||               Roll no: 20223062                ||"<<endl;
	gotoxy(17,11);
	cout<<"--------------------------------------------------"<<endl;
   	gotoxy(17,12);
	system("pause");
	system("cls");

    int ch;
	while(ch!=3)
	{
		cout<<"\n\t\t|--------<Main Menu>-----------|";
		cout<<"\n\n";
		cout<<"\t\t 1)Administator of Market\n";
		cout<<"\t\t 2)Customer\n";
		cout<<"\t\t 3)Exit\n";
		cout<<"\nEnter Your choice >>>";
		cin>>ch;
		switch(ch)
		{
			case 1:
				admin();
				break;

			case 2:
				cout<<endl<<endl;
				pop();
				system("pause");
				buy();
				break;

			case 3:
				cout<<"\n\n\t\tThank You";
				break;  
		}
	}
	return 0;
}