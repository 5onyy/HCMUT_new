#include "main.h"

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x)         x.begin(),x.end()

template<typename T> using vt = vector<T>;
using vi = vt<int>;
using ll = long long;
using ii = pair<int, int>;
using vii = vt<ii>;
template<typename T> using sptr = shared_ptr<T>;
template<typename T> using minpq = priority_queue<T, vt<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

/*-------------------------------FOR DEBUGGING --------------------------------------*/
#define DEBUG(X) { auto _X = (X); std::cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << std::endl; }
#define db(x) { std::cerr << "[" << #x << " = "; std::cerr << (x) << "] "; }
#define debug(x) { std::cerr << "[" << #x << " = "; std::cerr << (x) << "] " << endl; }

// For printing std::pair, container, etc.
template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

template<class Con, class = decltype(begin(std::declval<Con>()))>
typename std::enable_if < !std::is_same<Con, std::string>::value, std::ostream& >::type
operator << (std::ostream& out, const Con& con) {
	out << '{';
	for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
		out << (it == beg ? "" : ", ") << *it;
	}
	return out << '}';
}
template<size_t i, class T> std::ostream& print_tuple_utils(std::ostream& out, const T& tup) {
	if (i == std::tuple_size<T>::value) return out << ")";
	else return print_tuple_utils < i + 1, T > (out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U> std::ostream& operator << (std::ostream& out, const std::tuple<U...>& t) {
	return print_tuple_utils<0, std::tuple<U...>>(out, t);
}
/*-----------------------------------------------------------------------------------*/

static int MAXSIZE;

class Name {
private:
	vi freq;
	vi compress;
	vi char_list;
	vi first_appear;
	int result = 0;
	bool invalid = 1;
public:
	Name() = default;
	Name(string s) {
		freq.assign(500, 0);	first_appear.assign(500, 0);
		vi cnt(500, 0);
		for (auto x : s) {
			if (!cnt[x])	compress.pb(x);
			cnt[x]++;
		}
		if (sz(compress) < 3)	{ return;}
		result = 1;
		invalid = 0;

		for (auto i : compress) {
			if (!freq[encode(i, cnt)])	char_list.pb(encode(i, cnt));
			freq[encode(i, cnt)] += cnt[i];
		}
		for (auto &x : s) {
			x = encode(x, cnt);
		}
		compress.clear();	compress.assign(all(s));
		sort(all(char_list), [&] (int x, int y) {
			if (freq[x] == freq[y]) {
				if ((x >= 'a' && x <= 'z' && y >= 'a' && y <= 'z')
				            || (x >= 'A' && x <= 'Z' && y >= 'A' && y <= 'Z'))	return x < y;
				else return x > y;
			}
			return freq[x] < freq[y];
		});

		for (int i = 0; i < sz(char_list); i++)	first_appear[char_list[i]] = i;
	}
	char encode(char x, vi cnt) {
		char tmp = x;
		if (x >= 'a' && x <= 'z')	x -= 'a';
		else x -= 'A';
		x += cnt[tmp];	x %= 26;
		if (tmp >= 'a' && tmp <= 'z')	x += 'a';
		else x += 'A';
		return x;
	}
	vi get_char_list()		{return char_list;}
	vi get_freq()	{return freq;}
	vi get_first_appear() {return first_appear;}
	vi getName() {return compress;}
	int get_result() 	{return result;}
	bool isValid()	{return !invalid;}
};

class HuffTree {
private:
	class HuffTreeNode {
	public:
		char key;
		int freq;
		int first_appear;
		int height;
		sptr<HuffTreeNode> left;
		sptr<HuffTreeNode> right;
		HuffTreeNode(char _key, int _freq, int _first_appear)
			: key(_key), freq(_freq), first_appear(_first_appear), height(0), left(NULL), right(NULL) {};
		HuffTreeNode(char _key, int _freq, int _first_appear, int _height, sptr<HuffTreeNode> _left, sptr<HuffTreeNode> _right)
			: key(_key), freq(_freq), first_appear(_first_appear), height(_height), left(_left), right(_right) {};
	};
	struct Compare_Node {
		bool operator () (sptr<HuffTreeNode> l, sptr<HuffTreeNode> r) {
			if (l -> freq == r -> freq)	return l -> first_appear > r -> first_appear;
			else return l -> freq > r -> freq;
		}
	};

	vi char_list;
	vi freq_list;
	vi first_appear;
	sptr<HuffTreeNode> root;
	unordered_map<char, string> huffmanCode;
	bool isValid = 1;

	sptr<HuffTreeNode> rightRotation(sptr<HuffTreeNode> root) {
		sptr<HuffTreeNode> newroot = root->left;
		root->left = newroot->right;
		newroot->right = root;
		root->height = 1 + max(depth(root->left), depth(root->right));
		newroot->height = 1 + max(depth(newroot->left), depth(newroot->right));
		return newroot;
	}

	sptr<HuffTreeNode> leftRotation(sptr<HuffTreeNode> root) {
		sptr<HuffTreeNode> newroot = root->right;
		root->right = newroot->left;
		newroot->left = root;
		root->height = 1 + max(depth(root->left), depth(root->right));
		newroot->height = 1 + max(depth(newroot->left), depth(newroot->right));
		return newroot;
	}
	void printTree(sptr<HuffTreeNode> root) {
		if (!root)	return;
		if (!root -> left && !root -> right) {cerr << root -> key;	return;}
		cerr << root -> key << "(";
		printTree(root -> left);
		cerr << ',';
		printTree(root -> right);
		cerr << ')';
	}
	void InOrder(sptr<HuffTreeNode> root) {
		if (!root)	return;
		if (!root -> left && !root -> right) {
			cout << root -> key << '\n';	return;
		}
		InOrder(root -> left);
		cout << root -> freq << '\n';
		InOrder(root -> right);
	}

public:
	int TREE_SIZE;
	HuffTree() = default;
	// input 3 list, minimum number of char_lists is 3 -> build the huffman tree
	HuffTree(vi char_lists, vi freq_lists, vi first_appears) : char_list(char_lists), freq_list(freq_lists), first_appear(first_appears) {
		priority_queue< shared_ptr<HuffTreeNode>, vt<shared_ptr<HuffTreeNode>>, Compare_Node> pq;
		for (auto x : char_list) {
			//db(char(x)); db(freq_list[x]); debug(first_appear[x]);
			pq.push(make_shared<HuffTreeNode>(x, freq_list[x], first_appear[x]));
		}
		int appear_counter = sz(char_list) - 1;
		while (sz(pq) != 1) {
			sptr<HuffTreeNode> left = pq.top();		pq.pop();
			sptr<HuffTreeNode> right = pq.top();	pq.pop();
			int sum = left -> freq + right -> freq;
			appear_counter++;
			int hi = 1 + max(depth(left), depth(right));
			sptr<HuffTreeNode> newRoot (new HuffTreeNode ('?', sum, appear_counter, hi, left, right));
			//cerr << "NewRoot:" << newRoot -> key << " " << newRoot -> freq << "    ";
			//printTree(newRoot);
			//cerr << '\n';
			for (int attempt = 2; attempt >= 0;) {
				int prev_attempt = attempt;
				//db(prev_attempt);
				newRoot = DfsAndBalance(newRoot, attempt);
				//debug(attempt);
				if (prev_attempt == attempt)	attempt--;
			}
			//cerr << '\n';
			//cerr << "Tree after some balancing: "; printTree(newRoot);	cerr << '\n';
			pq.push(newRoot);
		}
		root = pq.top();
		TREE_SIZE = getSize(root);
		//cerr << "Tree initialization successful\n";
		isValid = (root -> key == '?');
		//printTree(root);
		encode(root, "", huffmanCode);
		//cerr << '\n';
		//debug(huffmanCode);
	}
	sptr<HuffTreeNode> DfsAndBalance(sptr<HuffTreeNode> root, int &attempt) {
		if (!root -> left && !root -> right)	return root;
		auto Balacing = balance(root, attempt);
		attempt -= Balacing.fi;
		root = Balacing.se;
		if (Balacing.fi)	return root;
		if (root -> left) {
			root -> left = DfsAndBalance(root -> left, attempt);
			auto LeftBalance = balance(root, attempt);
			attempt -= LeftBalance.fi;
			root = LeftBalance.se;
			if (LeftBalance.fi) return root;
		}
		if (root -> right) {
			root -> right = DfsAndBalance(root -> right, attempt);
			auto RightBalance = balance(root, attempt);
			attempt -= RightBalance.fi;
			root = RightBalance.se;
			if (RightBalance.fi) return root;
		}
		return root;
	}
	pair<int, sptr<HuffTreeNode>> balance(sptr<HuffTreeNode> root, int cnt) {
		int bal = getBalanceFactor(root);
		if (bal > 1) {
			if (getBalanceFactor(root -> left) >= 0) {
				root = rightRotation(root);	return {1, root};
			}
			else {
				auto tmp = root -> left;
				root -> left = leftRotation(tmp);
				if (cnt == 0)	return {1, root};
				root = rightRotation(root);
				return {2, root};
			}
		}
		else if (bal < -1) {
			if (getBalanceFactor(root -> right) <= 0) {
				root = leftRotation(root);	return {1, root};
			}
			else {
				auto tmp = root -> right;
				root -> right = rightRotation(tmp);
				if (cnt == 0)	return {1, root};
				root = leftRotation(root);
				return {2, root};
			}
		}
		return {0, root};
	}
	int getSize(sptr<HuffTreeNode> root) {
		if (!root) return 0;
		return getSize(root -> left) + getSize(root -> right) + 1;
	}
	int depth(sptr<HuffTreeNode> root) {
		if (root == NULL)		return 0;
		return root -> height;
	}
	int getBalanceFactor(sptr<HuffTreeNode> root) {
		if (!root)	return 0;
		return depth(root->left) - depth(root->right);
	}
	// traverse the Huffman Tree and store Huffman Codes
	// in a map.
	void encode(sptr<HuffTreeNode> root, string str,
	            unordered_map<char, string> &huffmanCode) {
		if (TREE_SIZE == 1)	{huffmanCode[root->key] = "0";	return;}
		if (root == nullptr)	return;
		if (root -> key != '?') {	// Modify from huffmann tree (!root->left && !root->right)
			huffmanCode[root->key] = str;
		}
		encode(root->left, str + "0", huffmanCode);
		encode(root->right, str + "1", huffmanCode);
	}
	void getTree() {return void(printTree(root));}
	// Get Result based on Name//input a class Name
	int getResult(Name name) {
		if (getSize(root) == 1)	return 0;
		if (!isValid)	return -1;
		vi ch_list(name.getName());
		if (!sz(ch_list)) return -1;
		vt <char> CustomerName;	for (auto x : ch_list) CustomerName.pb(char(x));
		//cerr << "Customer's Name: " ;	debug(CustomerName);
		string res = "";
		for (auto x : ch_list) {
			res += huffmanCode[x];
		}
		//debug(res);
		int end_idx = sz(res), start_idx = max (0, end_idx - 10);
		string rv(res, start_idx, end_idx - start_idx);		reverse(all(rv));
		bitset<20> bit(rv);
		return (int) bit.to_ulong();
	}
	void printInOrder() {
		return void(InOrder(root));
	}
};

class Customer {
private:
	Name Customer_Name;
	sptr<HuffTree> huff;
	int RESULT;

public:
	Customer() = default;
	Customer(Name _name) : Customer_Name(_name) {
		if (!Customer_Name.isValid()) {RESULT = -1; 	return;}
		huff = make_shared<HuffTree>(Customer_Name.get_char_list(), Customer_Name.get_freq(), Customer_Name.get_first_appear());
		RESULT = huff -> getResult(Customer_Name);
	}
	Name getName() {return Customer_Name;}
	int getType() {return RESULT == -1 ? -1 : RESULT % 2;}	//return the TYPE OF RESTAURANT (1: Gojo Restaurant, 0: Sukuna Restaurant)
	int getResult () {return RESULT;}
	int getID(int MAXSIZE) {return (int)(RESULT % MAXSIZE + 1);}
	void getCustomerTree() {return void(huff -> getTree());}
	void Hand() {return void(huff -> printInOrder());}
	void printCustomerInfo(int MAXSIZE) {return void(cout << getID(MAXSIZE) << "-" << getResult() << '\n');}
};

class BSTNode {
public:
	int value;
	sptr<BSTNode> left;
	sptr<BSTNode> right;
	BSTNode() = default;
	BSTNode(int _val) : value(_val), left(NULL), right(NULL) {};
	BSTNode(int _val, sptr<BSTNode> _left, sptr<BSTNode> _right) : value(_val), left(_left), right(_right) {};
};

class BST {
private:
	void addHelper(shared_ptr<BSTNode> &root, shared_ptr<BSTNode> node) {
		if (!root) {dummy -> right = root = node;		return;}
		if (root -> value > node -> value) {
			if (!root->left) {
				root->left = node;
			} else {
				addHelper(root->left, node);
			}
		} else {
			if (!root -> right) {
				root -> right = node;
			} else {
				addHelper(root->right, node);
			}
		}
	}
	//delete by address
	bool deleteNodeHelper(shared_ptr<BSTNode> parent, shared_ptr<BSTNode> current, shared_ptr<BSTNode> node) {
		if (!current) return false;
		if (current -> value == node -> value) {
			if (current->left == NULL || current->right == NULL) {
				shared_ptr<BSTNode> temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					} else {
						parent->right = temp;
					}
				} else {
					this->root = temp;
					//debug(this->root);
				}
			} else {	// General case
				shared_ptr<BSTNode> validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				swap(current -> value, validSubs -> value);
				return deleteNodeHelper(current, current->right, validSubs);
			}
			//current.reset();
			return true;
		}
		return deleteNodeHelper(current, current->left, node) ||
		       deleteNodeHelper(current, current->right, node);
	}
	vi PostOrder(sptr<BSTNode> root) {
		if (!root)	return {};
		if (!root -> left && !root -> right)	return {root -> value};
		vi lhs = PostOrder(root -> left);
		vi rhs = PostOrder(root -> right);
		vi concat = lhs;
		concat.insert(concat.end(), all(rhs));
		concat.pb(root -> value);
		return concat;
	}
	vi PreOrder(sptr<BSTNode> root) {
		if (!root)	return {};
		if (!root -> left && !root ->right)	return {root -> value};
		vi lhs = PreOrder(root -> left);
		vi rhs = PreOrder(root -> right);
		vi concat;	concat.pb(root -> value);
		concat.insert(concat.end(), all(lhs));
		concat.insert(concat.end(), all(rhs));
		return concat;
	}
	ll NumsOfBST(vt<vt<ll>> C, vi nums, ll mod) {			// Calculate num of BST moulod mod
		if (sz(nums) <= 1)   return 1;
		vi lhs, rhs;
		for (int i = 1 ; i < sz(nums); i++) {
			if (nums[i] >= nums[0]) rhs.push_back(nums[i]);
			if (nums[i] < nums[0])  lhs.push_back(nums[i]);
		}
		int n = sz(lhs), m = sz(rhs);
		ll ans = NumsOfBST(C, lhs, mod) * NumsOfBST(C, rhs, mod);  ans %= mod;
		ans *= C[m + n][n];    ans %= mod;
		return ans;
	}
	void InOrder(sptr<BSTNode> root) {
		if (!root)	return;
		InOrder(root -> left);
		cout << root -> value << '\n';
		InOrder(root -> right);
	}
	int SIZE;
	sptr<BSTNode> dummy;
	sptr<BSTNode> root;
public:
	BST () : SIZE(0), dummy(new BSTNode(-1, NULL, NULL)) {};
	int getSize() {return SIZE;}
	void add(sptr<BSTNode> node)	{SIZE++; addHelper(root, node);		/*cerr << "Add successfully, tree: ";*/ /*printTree(root); cerr << '\n';*/ return;}
	bool deleteNode(sptr<BSTNode> node) {
		/*cerr << "Tree before applying deletion: ";*/ //printTreeByAddress(root);	/*cerr << "\n";*/
		//debug(node);
		bool can = deleteNodeHelper(dummy, this->root, node);	 SIZE -= can;
		/*cerr << "After deletion tree becomes ";*/	//printTreeByAddress(root);	/*cerr << '\n'*/;
		return can;
	}
	void printTree(sptr<BSTNode> root) {
		if (!root)	return;
		if (!root -> left && !root -> right)	{cerr << root ->value;	return;}
		cerr << root -> value << '(';
		if (root -> left) printTree(root -> left);
		else cerr << "N";
		cerr << ' ';
		if (root -> right) printTree(root -> right);
		else cerr << "N";
		cerr << ')';
	}
	void printTreeByAddress(sptr<BSTNode> root) {
		if (!root)	return;
		if (!root -> left && !root -> right)	{cerr << root;	return;}
		cerr << root << '(';
		if (root -> left) printTreeByAddress(root -> left);
		else cerr << "N";
		cerr << ' ';
		if (root -> right) printTreeByAddress(root -> right);
		else cerr << "N";
		cerr << ')';
	}
	vi getPostOrder() {return PostOrder(root);}
	vi getPreOrder() {return PreOrder(root);}
	void printInOrder() {return void(InOrder(root));}
	ll getNumsOfBST(ll mod) {
		vi nums = getPreOrder();
		int n = sz(nums);
		vector<vector<ll>> C(n + 1, vector<ll>(n + 1, 0));
		for (int i = 1; i <= n; i++) {
			C[i][0] = 1;	C[i][i] = 1;
			for (int j = 1; j < i; j++)
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
		return NumsOfBST(C, nums, mod) - ((SIZE == 1) ? 0 : 0);
	}
};

class MinHeap {
	struct HeapItem {
		queue<Customer> CustomerQueue;
		int key;
		int value;
		int last_change;
		HeapItem() = default;
		HeapItem(int _key, int _value, int _last_change) : key(_key), value(_value), last_change(_last_change) {};
		HeapItem(queue<Customer> _CustomerQueue, int _key, int _value, int _last_change) : CustomerQueue(_CustomerQueue), key(_key), value(_value), last_change(_last_change) {};
	};
	bool cmp(HeapItem a, HeapItem b) {	// return a < b
		if (a.value == b.value)	return a.last_change < b.last_change;
		return a.value < b.value;
	}
private:
	int capacity;
	sptr<HeapItem[]> arr;
	int totalItems;
	int last_change_counter;
	void shiftUp(int index) {
		if (index < 1)	return;
		int parent = (index - 1) / 2;
		if (cmp(arr[index], arr[parent])) {
			swap(arr[index], arr[parent]);
			shiftUp(parent);
		}
		return;
	}
	void shiftDown(int index) {
		int minIndex = -1;
		int lChildIndex = index * 2 + 1;
		int rChildIndex = (index * 2) + 2;
		if (lChildIndex < totalItems)	{
			if (!cmp(arr[index], arr[lChildIndex])) { // par > l child
				minIndex = lChildIndex;
			}
		}
		if (rChildIndex < totalItems)	{
			if (!cmp(arr[minIndex == -1 ? index : minIndex], arr[rChildIndex])) {	// r-child is potential to swap (lchild > rchild)
				if (minIndex == -1)	minIndex = rChildIndex;
				else minIndex = (cmp(arr[lChildIndex], arr[rChildIndex]) ? lChildIndex : rChildIndex);
			}
		}
		if (minIndex == -1)	return;
		swap(arr[index], arr[minIndex]);
		shiftDown(minIndex);
	}
public:
	MinHeap() = default;
	MinHeap(int _capacity) : capacity(_capacity), arr(new HeapItem[_capacity]), totalItems(0), last_change_counter(0) {};
	void insert(int key, int value, Customer customer) {
		if (totalItems == capacity)	return;
		arr[totalItems] = HeapItem(key, value, last_change_counter);
		arr[totalItems].CustomerQueue.push(customer);
		//cerr << "Area " << key << ":";	db(value);	debug(arr[totalItems].last_change);
		shiftUp(totalItems);
		totalItems++;
		last_change_counter++;
	}
	int getIndex(int key) {	// get index given a key
		for (int i = 0; i < totalItems; i++)	if (arr[i].key == key)	return i;
		return -1;
	}
	void update(int key, int val, Customer customer) {	// heap[key] += val; If val < 0. Assume that |val| < heap[key]
		if (val == 0)	return;
		int index = getIndex(key);
		arr[index].last_change = last_change_counter;
		last_change_counter++;
		arr[index].value += val;
		arr[index].value = max (arr[index].value, 0);
		if (val < 0) {
			auto &q = arr[index].CustomerQueue;
			for (int i = 0; i < min(abs(val), sz(q)); i++) {
				auto cus = q.front();
				cout << cus.getResult() << "-" << cus.getID(capacity - 1) << '\n';
				q. pop();
			}
		}
		if (arr[index].value == 0) {
			DeleteAt(index);
			return;
		}
		if (val < 0) {
			shiftUp(index);
		}
		else {
			for (int i = 0 ; i < val; i++) {
				arr[index].CustomerQueue.push(customer);
			}
			//debugHeap();
			shiftDown(index);
		}
	}
	void PrintCleave(int num, int i) {
		if (i >= totalItems)	return;
		//db(arr[i].key);
		HeapItem tmp = arr[i];
		auto q = tmp.CustomerQueue;
		for (int cnt = 0; cnt < min(num, sz(q)); cnt++) {
			q.front().printCustomerInfo(capacity - 1);
			q.pop();
		}
		int lhs = i * 2 + 1;
		PrintCleave(num, lhs);
		int rhs = i * 2 + 2;
		PrintCleave(num, rhs);
	}
	void debugHeap() {
		cerr << "Heap size: " << totalItems << "[\n";
		for (int i = 0; i < totalItems; i++) {
			int last_change = arr[i].last_change;
			cerr << "  Area " << arr[i].key << ": ";	db(arr[i].value);	debug(last_change);
		}
		cerr << "]\n";
	}
	void printHeap(int cnt) {
		cnt = min (cnt, totalItems);
		for (int i = 0; i < cnt; i++)	cout << arr[i].key << '-' << arr[i].value << '\n';
	}
	void deleteMin() {
		assert(totalItems != 0);
		swap(arr[0], arr[this->totalItems - 1]);
		totalItems--;
		//shift down
		shiftDown(0);
	}
	void DeleteAt(int index) {
		assert(totalItems != 0);
		swap(arr[index], arr[this->totalItems - 1]);
		totalItems--;
		int par = (index - 1) / 2;
		if (cmp(arr[index], arr[par]))	shiftUp(index);
		else shiftDown(index);
	}
	int getSize() {return totalItems;}
	vii nSmallestKey(int cnt) {
		cnt = min (cnt, totalItems);
		vt <HeapItem> process;
		for (int i = 0; i < totalItems; i++)	process.pb({arr[i].key, arr[i].value, arr[i].last_change});
		sort(all(process), [&] (HeapItem a, HeapItem b) {
			if (a.value == b.value)	return a.last_change < b .last_change;
			return a.value < b.value;
		});
		vii ans;	for (int i = 0; i < cnt; i++)	ans.pb({process[i].key, process[i].value});
		return ans;
	}
};

class GRestaurant {
private:
	int MAXN;
	struct Area {
	public:
		BST tree;
		queue<sptr<BSTNode>> q;
		Area() = default;
		void add(sptr<BSTNode> node) {
			q.push(node);
			tree.add(node);
		}
	};
	vt <Area> area;
public:
	GRestaurant() = default;
	GRestaurant(int _MAXSIZE) : MAXN(_MAXSIZE) {
		area.resize(MAXN + 1);
	}
	void add(Customer customer) {
		int ID = customer.getID(MAXN);
		area[ID].add(make_shared<BSTNode>(customer.getResult()));
	}
	void Kokusen() {
		for (int ID = 1; ID <= MAXN; ID++) {
			//db(ID);
			vi AreaTree = area[ID].tree.getPreOrder();
			//DEBUG(AreaTree);
			int CNT_DELETE = area[ID].tree.getNumsOfBST(MAXN);
			/*db(CNT_DELETE);*/	CNT_DELETE = min(CNT_DELETE, area[ID].tree.getSize());	/*debug(CNT_DELETE);*/
			for (; CNT_DELETE; CNT_DELETE--) {
				auto &q = area[ID].q;
				sptr<BSTNode> NODE = q.front();	q.pop();
				area[ID].tree.deleteNode(NODE);
			}
			//cerr << '\n';
		}
	}
	void Limitless(int NUM) {
		if (NUM > MAXN || NUM < 1) 	return;
		area[NUM].tree.printInOrder();
	}
};

class SRestaurant {
private:
	int MAXN;
	MinHeap Heap;
	vi cur_exist;	// area currently exists
public:
	SRestaurant() = default;
	SRestaurant(int _MAXSIZE) : MAXN(_MAXSIZE), Heap(_MAXSIZE + 1), cur_exist(vi(_MAXSIZE + 1, 0)) {};
	void add(Customer customer) {
		int areaID = customer.getID(MAXN);
		if (!cur_exist[areaID]) { Heap.insert(areaID, 1, customer);	cur_exist[areaID] = 1; }
		else Heap.update(areaID, +1, customer);
		//Heap.debugHeap();
	}
	void Keiteiken(int NUM) {
		vii DeleteList = Heap.nSmallestKey(NUM);
		//debug(DeleteList);
		for (auto ii : DeleteList) {
			int key = ii.first;
			int SizeBefore = Heap.getSize();
			Heap.update(key, -NUM, Customer());
			if (SizeBefore > Heap.getSize())	cur_exist[key] = 0;
			//Heap.debugHeap();
		}
	}
	void Cleave(int num) {
		return void(Heap.PrintCleave(num, 0));
	}
};

class Solution {
private:
	vector<Customer> customer_list;
	GRestaurant gres;
	SRestaurant sres;
	int MAXSIZE;
public:
	Solution(int _MAXSIZE) : MAXSIZE(_MAXSIZE) {
		gres = GRestaurant(MAXSIZE);
		sres = SRestaurant(MAXSIZE);
	}
	void Lapse(string s) {
		//cout << "lapse\n";
		//cerr << s << '\n';
		Name _name(s);
		Customer p(_name);
		if (p.getType() != -1) customer_list.pb(p);
		if (p.getType() == 1) {
			//cerr << "Customer " << p.getResult() << " comes to GRestaurant and sits in " << p.getID(MAXSIZE) << "th area \n";
			gres.add(p);
		}
		else if (p.getType() == 0) {
			//cerr << "Customer " << p.getResult() << " comes to SRestaurant and sits in " << p.getID(MAXSIZE) << "th area \n";
			sres.add(p);
		}
	}
	void Kokusen() {
		//cerr << "kokusen" << '\n';
		//cout << "kokusen\n";
		gres.Kokusen();
	}
	void Keiteiken(int num) {
		//cerr << "keiteiken <" <<  num << ">\n";
		//cout << "keiteiken - " << num << '\n';
		sres.Keiteiken(num);
	}
	void Hand() {
		//cerr << "hand\n";
		if (sz(customer_list)) customer_list.back().Hand();
	}
	void Limitless(int num) {
		//cerr << "limitless <" << num << ">\n";
		gres.Limitless(num);
	}
	void Cleave(int num) {
		//cerr << "cleave <" << num << ">\n";
		sres.Cleave(num);
	}
};

static void simulate(string filename)
{
	freopen(filename.c_str(), "r", stdin);
	//freopen(filename.c_str(), "w", stdout);
	string typ;	cin >> typ;
	cin >> MAXSIZE;
	sptr<Solution> solve(new Solution(MAXSIZE));
	while (cin >> typ) {
		if (typ == "LAPSE") {
			string name;	cin >> name;
			solve -> Lapse(name);
			//cerr << '\n';
		}
		if (typ == "KOKUSEN") {
			solve -> Kokusen();
			//cerr << '\n';
		}
		if (typ == "KEITEIKEN") {
			int num;	cin >> num;
			solve -> Keiteiken(num);
			//cerr << '\n';
			//cout << '\n';
		}
		if (typ == "HAND") {
			solve -> Hand();
			//cerr << '\n';
			//cout << '\n';
		}
		if (typ == "LIMITLESS") {
			int num;	cin >> num;
			solve -> Limitless(num);
			//cout << '\n';
			//cerr << '\n';
		}
		if (typ == "CLEAVE") {
			int num;	cin >> num;
			solve -> Cleave(num);
			//cerr << '\n';
			//cout << '\n';
		}
	}
	//cout << solve.use_count();
	return;
}
