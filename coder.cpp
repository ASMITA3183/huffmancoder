#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include "huffman.cpp"
//#include "comp.h"

using namespace std ;

class comp
{
	public:
	bool operator() (Node* a ,Node* b)
	{
		return (a->count) > (b->count) ;
	}
};

class HuffmanCoder
{
	public:
		
	string text ;
	vector<int>v ;
	priority_queue<Node* , vector<Node*> , comp>pq;
	HuffmanTree* obj ;
	unordered_map<string ,char>decodes;
	unordered_map<char ,string>codes;
	string header ;
	
	HuffmanCoder(string data)
	{
		this->text = data;
		for(int i =0 ; i < 256 ; i++)
		{
			v.push_back(0);
		}
		obj = new HuffmanTree();
	}
	
	void countfreequecy() //1
	{
		for(char c : text)
		{
			v[c]++;
		}
	}
	
	void makenode() //2
	{
		for(int i = 0; i < 256 ; i++)
		{
			if(v[i] != 0)
			{
				Node* node ;
				node = new Node(v[i] ,i);
				pq.push(node);
			}
		}
	}
	
	void mergenodes() //3
	{
		
		while(pq.size() >= 2)
		{
			Node* a ;
			Node* b ;
			a = pq.top() ; pq.pop();
			b = pq.top() ; pq.pop();
			
			Node* c = obj->addnode(a ,b);
			pq.push(c);
		}
		
		obj->root = pq.top();
	}
	
	void makecodes() //4
	{
		string s = "";
		obj->traverse(obj->root , s ,codes ,decodes);
	}
	
	void makeheader() //5
	{
		for(auto it : codes)
		{
			header.push_back(it.first);
			header += it.second ;
		}
	}
	
	string code()
	{
		string data = "";
		data += header ;
		data += "#";
		
		for(char c : text)
		{
			//cout<<c<<" "<<codes[c]<<endl;
			data += codes[c];
		}
		
		//cout<<data<<endl;
		return data;
	}
	
	int converttoint(string s)
	{
		int n = 0;
		for(int i = 0 ; i < s.size() ;i++)
		{
			if(s[i] == '1'){
				n += pow(2 ,i);
			}
		}
		
		return n;
	}

	string perform()
	{
		countfreequecy() ;
		makenode() ;
		mergenodes() ;
		makecodes() ;
		makeheader() ;
		string s = code() ;
		//cout<<"code: "<<s<<endl;
		return s;
	}
	
	string makesmall()
	{
		string text = perform();
		
		//cout<<"Text: "<<text<<endl;
		
		int index = 0 ;
		
		for(int i = 0; i < text.size() ;i++)
		{
			if(text[i] == '#'){
				index = i+1;
				break;
			}
		}
		
		string header = text.substr(0 , index-1);
		
		//cout<<"Header: "<<header<<endl;
		string s = "";
		string codeddata = "";
		
		for(int i = index  ; i < text.size() ; i++)
		{
			s.push_back(text[i]);
			if(s.size() == 7){
				int n = converttoint(s);
				char ch = n;
				codeddata.push_back(ch);
				s = "";
			}
		}
		
//		if(s.size()){
//			int n = converttoint(s);
//			char ch = n;
//			codeddata.push_back(ch);
//		}

		codeddata += s ;
		
		//cout<<"header: "<<header<<endl;
		string codeddata2 = header + "#" + codeddata;
		
		//cout<<codeddata2<<endl;
		return codeddata2 ;
		
	}
	
	string solve()
	{
		string s = makesmall();
		return s ;
	}
		
};
