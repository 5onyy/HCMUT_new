#include "main.h"

#define db(x) { cout << #x << " = "; cout << (x) << endl; }

extern int MAXSIZE;

template <typename E> class Link {
public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list
  // Constructors
  Link(E elemval, Link* nextval =NULL)
    { element = elemval;  next = nextval; }
  Link(Link* nextval =NULL) { next = nextval; }
};

template <typename E> class LQueue{
	private:
	Link<E>* front;       
	Link<E>* rear;        
	int sze;               

	public:
	LQueue(int sz = 0) // Constructor 
		{ front = rear = new Link<E>(); sze = 0; }

	~LQueue() {clear(); delete front; }      // Destructor

	void clear() {           // Clear queue
		while (front != rear){
			Link<E>* tmp = front;
			front = front -> next;
			delete tmp;
		}
		delete rear;
		rear = front = NULL;
		sze = 0;
	}

	void push(E it) { // Put element on rear
		if (sze == MAXSIZE)	return;	
		rear->next = new Link<E>(it, NULL);
		rear = rear->next;
		sze++;
	}

	E pop() {         
		E it = front->next->element;  
		Link<E>* ltemp = front->next; 
		front->next = ltemp->next;       
		if (rear == ltemp) rear = front; 
		delete ltemp;                    
		sze --;
		return it;                       
	}

	E fr() { 
		return front->next->element;
	}

	int size() { return sze; }
	void print(){
		if (size() == 0)	return;
				cout<<"waiting line: \n";
		Link<E>* tmp = front->next;
		while (tmp != NULL){
			tmp->element.print();
			tmp = tmp -> next;
		}
	}

	bool check(string s){
		if (size() == 0)	return 0;
		Link<E>* tmp = front->next;
		while (tmp != NULL){
			if (tmp->element.name == s)	return 1;
			tmp = tmp -> next;
		}
		return 0;
	}
};


class imp_res final : public Restaurant
{
	public:	
		LQueue<customer> waiting,order;
		customer *cur, *last, *start;
		int cur_size;
		imp_res() {
			cur = NULL;
			last = NULL;
			start = NULL;
			cur_size = 0;
		};
		~imp_res(){
			delete cur;	delete last;	delete start;
		}
		customer *find (string name){
			customer *tmp = start;
			if (cur_size == 1)	return tmp;
			while (tmp != last){
				if (tmp -> name == name)	return tmp;
				tmp = tmp -> next;
			}
			return last;
		}
		bool check(string name){
			customer *tmp = start;
			if (cur_size == 1)	return (cur->name == name);
			while (tmp != last){
				if (tmp -> name == name)	return 1;
				tmp = tmp -> next;
			}
			return last -> name == name;
			return 0;
		}
		void insert_at_end(string name, int energy){
			customer *new_cus = new customer (name,energy,last,start);
			last -> next = new_cus;
			start -> prev = new_cus;
			last = cur = new_cus;
			return;
		}
		void insert_at_begin(string name, int energy){
			customer *new_cus = new customer (name,energy,last,start);
			last -> next = new_cus;
			start -> prev = new_cus;
			start = cur = new_cus;
			return;
		}
		void insert_left(string name, int energy){
			if (cur == start)	{insert_at_begin(name,energy);	return;}
			customer *new_cus = new customer (name,energy,cur->prev,cur);
			cur -> prev -> next = new_cus;
			cur -> prev = new_cus;
			cur = cur -> prev;
			return;
		}
		void insert_right(string name, int energy){
			if (cur == last)	{insert_at_end(name,energy);	return;}
			customer *new_cus = new customer (name,energy,cur,cur->next);
			cur -> next -> prev = new_cus;
			cur -> next = new_cus;
			cur = cur -> next;
			return;
		}
		void del_at(customer *&tmp){
			if (cur_size == 0)	return;
			if (cur_size == 1)	{delete cur;	cur = start = last = NULL;}
			if (tmp == start){
				last -> next = start -> next;
				start -> next -> prev = last;
				start = start -> next;
				delete tmp;	
			}
			else if (tmp == last){
				start -> prev = last -> prev;
				last -> prev -> next = start;
				last = last -> prev;
				delete tmp;
			}
			else{
				customer *prevv = tmp -> prev, *nxt = tmp -> next;
				prevv -> next = nxt;
				nxt -> prev = prevv;
				delete tmp;
			}
			cur_size --;
		}
		void move_to_cus(string name){
			customer *tmp = start;
			if (cur_size == 1)	return;
			while (tmp != last){
				if (tmp->name == name)	{cur = tmp;	return;}
				tmp = tmp -> next;	
			}
			cur = last;
		}
		void RED(string name, int energy){
			if (cur_size == 0){
				customer *cus = new customer (name, energy, nullptr, nullptr);
				cur = cus;	cur->next = cur->prev = cur;	last = start = cur;	
			}
			else if (energy == 0 || check(name) || waiting.check(name))	{cout<<"Name duplicated!\n\n";	return;}	//BLUE CAN PASS, OF COURSE
			else if (cur_size == MAXSIZE){		//PUSH TO WAITING	//BLUE CAN PASS BC CUR_SIZE AFTER DELETEION ALWAY < MAXSIZE
				customer new_in(name,energy,nullptr,nullptr);
				if (waiting.size() < MAXSIZE)	waiting.push(new_in);	
				waiting.print();
				return;
			}
			else if (cur_size < MAXSIZE/2){	
				if (energy >= cur->energy)			insert_right(name,energy);
				else insert_left(name,energy);
			}
			else{
				customer *tmp = cur;
				int mmax = -1e7, side = 0;
				while (tmp != cur -> prev){
					if (abs(tmp->energy - energy) > mmax){
						cur = tmp;
						mmax = abs(tmp->energy - energy);
						side = tmp->energy - energy;
					}
					tmp = tmp -> next;
				}
				if (abs(cur -> prev -> energy - energy) > mmax){
					cur = cur -> prev;
					side = cur -> prev -> energy - energy;
				}
				if (side > 0)	insert_left(name,energy);	// E_new - E_cur < 0
				else insert_right(name,energy);
			}
			cur_size++;
			db(cur_size);
			debug_cur();
			debug();
			if (cur_size <= MAXSIZE)	order.push(customer(name,energy,nullptr,nullptr));
			return;
		}
		void BLUE(int num){
			int possible = num;
			cout<<"BLUE:\n";
			num = min (num,cur_size);
			while (num--){
				customer cus = order.pop();
				move_to_cus(cus.name);
				del_at(cur);
				cur = start;
			}
			if (order.size() == 0)	cur = start = last = NULL;
			move_to_cus(order.fr().name);
			debug_cur();
			debug();
			if (waiting.size() == 0)	return;
			possible = min(waiting.size(),possible);
			while (possible--)
			{
				customer x = waiting.pop();
				RED(x.name,x.energy);
			}
			
		}
		void PURPLE(){
			cout << "purple"<< endl << endl;
		}
		void REVERSAL(){
			cout << "reversal" << endl << endl;
		}
		void UNLIMITED_VOID(){
			cout<<"UNLIMITED_VOID: ";
			if (cur_size < 4)	{cout<<"Error! \n";	return;}
			int sum = 0, mmin =1e9, cnt = 0;
			customer *ii = cur, *ans = NULL;
			string name_list = "";
			for (int len = 4 ; len <= cur_size; len++){
				for (int i = 0; i < cur_size; i++, ii = ii -> next){
					customer *jj = ii;
					sum = 0;
					string tmp = "";
					for (int j = 0; j < len; j++, jj = jj -> next)  {sum += jj -> energy;	tmp += jj -> name + " ";}
					if (sum < mmin){
						cnt = len;
						ans = ii;
						name_list = tmp;
						mmin = sum;
					}
				}
			}
			for (int i = 0; i < cnt; i++, ans = ans -> next){
				
			}
			name_list = name_list + name_list;
			
		}
		void DOMAIN_EXPANSION(){
			cout << "domain_expansion" << endl << endl;
		}
		void LIGHT(int num){
			cout << "light " << num << endl << endl;
		};
		void debug(){
			cout<<"table: "<<cur_size<<'\n';
			if (cur_size == 1)	{cur->print(); cout<<'\n'; return;}
			customer *tmp = start;
			while (tmp != last)
			{
				tmp->print();	tmp = tmp -> next;
			}
			last->print();
			cout<<endl;
		}
		void debug_cur(){
			cout<<"cur: ";
			cur->print();
		}
};