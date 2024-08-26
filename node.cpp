
class Node
{
	public:
	int count ;
	char ch ;
	Node* left ;
	Node* right ;
		
	Node()
	{
		count = 0 ;
		ch = '0';
		left = right = nullptr ;
	}
	
	Node(int count , char ch)
	{
		this->count = count;
		this->ch = ch ;
		left = right = nullptr ;
	}
	
	Node(int count , Node* a , Node* b)
	{
		this->count = count;
		this->ch = ch ;
		this->left = a ;
		this->right = b ;
	}
};
