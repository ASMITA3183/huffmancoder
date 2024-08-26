#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include "node.cpp"
using namespace std ;

class HuffmanTree
{
	public:
	Node* root;
	
	HuffmanTree()
	{
		root = NULL ;
	}
	
	Node* addnode(Node* a ,Node* b)
	{
		Node* c;
		c = new Node(a->count + b->count , a ,b);
		return c ;
	}
	
	void traverse(Node* node , string s ,unordered_map<char ,string>&codes , unordered_map<string ,char>&decodes)
	{
		if(node == NULL){
			return ;
		}
		if(node->left == NULL)
		{
			codes[node->ch] = s;
			decodes[s] = node->ch;
			return ;
		}
		traverse(node->left , s + "0" , codes ,decodes);
		traverse(node->right , s + "1" ,codes ,decodes);
	}
};
