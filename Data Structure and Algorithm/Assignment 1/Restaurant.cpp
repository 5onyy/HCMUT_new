#include "main.h"

#define db(x) { cout << #x << " = "; cout << (x) << endl; }

template <typename E> class Link {
public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list
  // Constructors
  Link(E elemval, Link* nextval =NULL)
    { element = elemval;  next = nextval; }
  Link(Link* nextval =NULL) { next = nextval; }
};

template <typename E> class LQueue{		//dummy head (nullptr)
	private:
	Link<E>* front;       
	Link<E>* rear;        
	int sze;               

	public:
	LQueue(int sz = 0) // Constructor 
		{ front = rear = new Link<E>(); sze = 0; }

	~LQueue() {/* print();  */ clear(); delete front; }      // Destructor

	void swap(Link<E> *&x, Link<E> *&y){
		Link<E>* z = new Link<E>();
		z -> element.name = x -> element.name;
		z -> element.energy = x -> element.energy;
		x -> element.name = y->element.name;
		x -> element.energy = y->element.energy;
		y -> element.name = z -> element.name;
		y -> element.energy = z->element.energy;
	}

	void swap(int i,int j) {
		Link<E>* x = front -> next;		for (int k=0;k<i;k++,x=x->next);
		Link<E>* y = front -> next;		for (int k=0;k<j;k++,y=y->next);
		swap(x,y);
	}

	int index_of(E x){
		Link<E> *tmp = front -> next;
		int i = 0;
		for (; i < sze && tmp->element.name != x.name; i++, tmp = tmp -> next);
		return i;
	}

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
		//if (sze == MAXSIZE)	return;	
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

	int sum_of_type(bool typ){	// 0 for cursed, 1 for magician
		Link<E>* tmp = front -> next;
		int ans = 0;
		for (int i=0; i < sze; i++, tmp = tmp -> next){
			if (typ == 1)	ans += (tmp -> element.energy > 0 ? tmp -> element.energy : 0) ;
			else if (typ == 0) ans += (tmp -> element.energy < 0 ? tmp -> element.energy : 0);
		}
		return ans;
	}

	void delr(Link<E>* cur){
		if (sze == 1 || sze == 0)	{clear();	return;}
		Link<E>* tmp = cur -> next;
		if (tmp == rear)	rear = cur;
		cur -> next = tmp -> next;
		sze--;
		delete tmp;
	}

	void del_at(string name){
		Link<E>* tmp = front;
		for (int i=0; i < sze; i++, tmp = tmp -> next){
			if (tmp -> next->element.name == name)	delr(tmp);
		}
	}

	E at(int index){
		Link<E>* tmp = front -> next;
		for (int i = 0; i < index; i++, tmp = tmp -> next);
		return tmp->element;
	}

	void del_type(bool typ){
		Link<E>* tmp = front;
		if (sze == 1){
			if (typ == 1 && fr().energy > 0)		clear();
			else if (typ == 0 && fr().energy < 0)		clear();
			return;
		}
		while (tmp != rear){
			if (typ == 1 && tmp -> next -> element.energy > 0){
				if (tmp == front)	pop();
				else delr(tmp);	//del after tmp
			}
			else if (typ == 0 && tmp -> next -> element.energy < 0){
				if (tmp == front)	pop();
				else delr(tmp);
			}
			else tmp = tmp -> next;
		}
	}

	string name_list(bool typ){
		Link<E> *tmp = front -> next;
		string ans="";
		while (tmp != NULL){
			if (typ == 1 && tmp -> element.energy > 0)	ans = tmp -> element.name + "-" + to_string(tmp -> element.energy) + "\n" + ans;	
			else if (typ == 0 && tmp -> element.energy < 0)	ans = tmp -> element.name + "-" + to_string(tmp -> element.energy) + "\n" + ans;	
			tmp = tmp -> next;
		}
		return ans;
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
		customer *find_type (bool typ){
			customer *tmp = start;
			for (int i = 0; i < cur_size; i++, tmp = tmp -> next){
				if (typ == 0 && tmp -> energy < 0)	return tmp;
				if (typ == 1 && tmp -> energy > 0)	return tmp;
			}
			return NULL;
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
			if (cur_size == 1)	{delete cur;	cur = start = last = NULL; cur_size = 0;	return;}
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
		void swap(customer *&x, customer *&y){
			customer z(x->name, x->energy,nullptr,nullptr);
			x->name = y->name;
			x->energy = y->energy;
			y->name = z.name;
			y->energy = z.energy;
 			if (x == cur)	cur = y;
			else if (y == cur)	cur = x; 
		}
		int num_of_type(bool typ){		//typ = 0 for cursed, else magician
			customer *tmp = start;
			int ans = 0;
			for (int i = 0; i < cur_size; i++, tmp = tmp -> next){
				if (typ == 0)	ans += (tmp -> energy < 0);
				else if (typ == 1)	ans += (tmp -> energy > 0);
			}
			return ans;
		}
		void RED(string name, int energy){
			if (cur_size == 0){
				if (energy == 0)	return;
				customer *cus = new customer (name, energy, nullptr, nullptr);
				cur = cus;	cur->next = cur->prev = cur;	last = start = cur;	
			}
			else if (energy == 0 || check(name) || waiting.check(name))	{/* cout<<"Name duplicated!\n\n";	 */return;}	//BLUE CAN PASS, OF COURSE
			else if (cur_size == MAXSIZE){		//PUSH TO queue	//BLUE CAN PASS BC CUR_SIZE AFTER DELETEION ALWAY < MAXSIZE
				customer new_in(name,energy,nullptr,nullptr);
				if (waiting.size() < MAXSIZE)	{waiting.push(new_in);	if (!order.check(name))	order.push(new_in);}	
				//waiting.print();	cout<<'\n';
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
				//db(side);
				if (side > 0)	insert_left(name,energy);	// E_new - E_cur < 0
				else insert_right(name,energy);
			}
			cur_size++;
			//db(cur_size);
			//debug_cur();
			//debug();
			if (cur_size <= MAXSIZE)	if (!order.check(name)) order.push(customer(name,energy,nullptr,nullptr));
			return;
		}
		void BLUE(int num){
			int possible = num;
			//cout<<"BLUE: "<<num<<'\n';
			num = min (num,cur_size);
			while (num--){
				customer cus = order.at(0);
				for (int i = 0; i < order.size() && !check(cus.name); i++, cus=order.at(i));
				move_to_cus(cus.name);
				customer *tmp = (cur -> energy < 0) ? cur -> prev : cur -> next;
				del_at(cur);
				cur = tmp;
				//order.del_at(cus.name);
				//order.print();
				//cout<<'\n'; 
			}
			//cout<<"okok\n";
			//order.print();
			//debug();
			//debug_cur();
			if (cur_size == 0)	start = last = NULL;
			possible = min(waiting.size(),possible);
			if (waiting.size() == 0)	return;
			while (possible--)
			{
				customer x = waiting.pop();
				RED(x.name,x.energy);
			}
		}
		bool cmp (customer x, customer y){
			if (abs(x.energy) == abs(y.energy))	return order.index_of(x) < order.index_of(y);
			else return x.energy > y.energy;
		}

		int inssort(int base, int n, int incr){
			int cnt = 0;
			for (int i = incr + base; i < n; i+= incr){
				for (int j = i; j >= incr; j-=incr){
					customer x = waiting.at(j);
					customer y = waiting.at(j-incr);
					if (cmp(x,y))	continue;
					waiting.swap(j,j-incr);
					cnt ++;
				}
			}
			return cnt;
		}

		int shellsort(int n){
			int ans = 0;
			for (int gap = n/2; gap > 2; gap/=2){
				for (int j = 0; j < gap; j++){
					ans += inssort(j,n-j,gap);
					//db(ans);
				}
			}
			ans += inssort(0,n,1);
			return ans;
		}

		void PURPLE(){
			//cout << "purple"<< endl;
			//waiting.print();
			int pos = 0;
			customer ans = waiting.at(0);
			for (int i = 1; i < waiting.size(); i++){
				customer x = waiting.at(i);
				if (!cmp(x,ans)){
					pos = i;
					ans = x;
				}
			}
			pos+=1;
			//db(pos);
			//db(shellsort(pos));
			//waiting.print();
			cout<<shellsort(pos)<<'\n';
			//cout<<'\n';
		}
		void REVERSAL(){
			//cout << "REVERSAL: \n";
			//db(num_of_type(0));	db(num_of_type(1));
			//debug_cur();
			int cnt0 = num_of_type(0),	cnt1 = num_of_type(1);
			customer *t1 = cur, *t2 = cur -> next, *t3 = cur, *t4 = cur -> next;
			for (int i = 0; i < cur_size; i++, t3 = t3 -> prev)	if (t3 -> energy * cur -> energy < 0)	break;
			for (int i=0; i < cnt0 / 2; i++, t1 = t1 -> prev,	t2 = t2 -> next){
				while ( t1 -> energy * t2 -> energy < 0)	t2 = t2 -> next;
				swap(t1,t2);
			}
			for (int i=0; i< cnt1 / 2; i++, t3 = t3 -> prev, t4 = t4 -> next){
				while ( t3 -> energy * t4 -> energy < 0)	t4 = t4 -> next;
				swap(t3,t4);
			}
			//debug();
		}
		void UNLIMITED_VOID(){
			//cout<<"UNLIMITED_VOID: ";
			if (cur_size < 4)	{/* cout<<"Error! \n"; */	return;}
			int sum = 0, mmin =1e9, cnt = 0;
			customer *ii = cur, *ans = NULL;
			string name_list = "";
			for (int len = 4 ; len <= cur_size; len++){
				for (int i = 0; i < cur_size - 1; i++, ii = ii -> next){
					customer *jj = ii;
					sum = 0;
					string tmp = "";
					for (int j = 0; j < len; j++, jj = jj -> next)  {sum += jj -> energy;	tmp += jj -> name + " "; }
					if (sum <= mmin){
						ans = ii;
						cnt = len;
						name_list = tmp;
						mmin = sum;
					}
				}
			}
			name_list = name_list + name_list;
			//db(cnt);
			int min_energy = 1e7;
			string _name;
			for (int i=0; i<cnt; i++, ans = ans -> next){
				if (min_energy > ans -> energy){
					min_energy = ans -> energy;
					_name = ans -> name;
				}
			}
			//db(_name);
			size_t t2 = name_list.find(_name) + _name.size(), t1 = t2;
			for (; cnt > 0; cnt--, t2 = name_list.find(' ',t2 + 1)){
				t1 = t2 - 1;
				while (t1 > 0 && name_list.at(t1-1) != ' ')	t1--;
				string s = name_list.substr(t1,t2-t1);
				customer* p = find(s);
				p->print();
			}
			//cout<<'\n';
		}
		void DOMAIN_EXPANSION(){
			//cout << "domain_expansion" << endl;
			//db(order.sum_of_type(0));	db(order.sum_of_type(1));
			int s1 = abs(order.sum_of_type(0)), s2 = order.sum_of_type(1);
			/*cout<<"order.name_list(1): \n"<< order.name_list(1)<<'\n';
			cout<<"order.name_list(0): \n"<< order.name_list(0)<<'\n';*/
			bool decision = (s2 < s1);
			string res = order.name_list(decision);
			waiting.del_type(decision);
			order.del_type(decision);
			size_t f2 = res.find('-');
			for (;f2 != string::npos; f2 = res.find('-',f2+2)){
				int f1 = f2 - 1;
				while (f1 > 0 && res.at(f1 - 1) != '\n')	f1--;
				string name = res.substr(f1,f2-f1);
				if (!check(name))	continue;
				move_to_cus(name);
				customer *back_up = NULL;
				if (decision == 0) back_up = cur -> prev;
				else back_up = cur -> next;
				del_at(cur);
				cur = back_up;
			}
			//debug();
			int possible = min(MAXSIZE - cur_size, waiting.size());
			while (possible -- ){
				customer cus = waiting.pop();
				RED(cus.name,cus.energy);
			}
			cout<<res;
		}
		void LIGHT(int num){
			//cout << "light " << num << endl;
			if (num == 0)	waiting.print();
			else if (num > 0) print_from_cur(true,num);
			else print_from_cur(false,-num);
		}
		void print_from_cur(bool clockwise, int cnt){
			//db(cur_size);
			if (cur_size == 0)	return;
			customer *tmp = cur;
			for (int i = 0; i < cur_size; i++){
				tmp -> print();
				if (clockwise)	tmp = tmp -> next;
				else tmp = tmp -> prev;
			}
		}
		void debug(){
			cout<<"table: "<<cur_size<<'\n';
			if (cur_size == 0)	return;
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