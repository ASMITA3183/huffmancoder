#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std ;

class Decoder
{
	public:
	string data ;
	unordered_map<string ,char>mp ;
	string header ;
	string text ;
	
	Decoder(string data)
	{
		this->data = data;
		header = "";
		text = "";
	}
	
	void saperateHeaderandText()
	{
		int index = 0;
		for(int i = 0 ; i < data.size() ;i++)
		{
			if(data[i] == '#'){
				index = i;
				break;
			}
		}
		
		header = data.substr(0 , index);
		//cout<<header<<endl;
		text = data.substr(index+1 , data.size()-index);
		//cout<<text<<endl;
	}
	
	void mapthcodefromheader()
	{
		string s = "" ;
		char ch = '0' ;
		for(char c : header)
		{
			if(c == '1' || c == '0'){
				s.push_back(c);
			}
			else
			{
				if(ch == '0'){
					ch = c;
				}
				else
				{
					mp[s] = ch ;
					ch = c ;
					s = "";
				}
			}
		}
		mp[s] = ch;
		
//		cout<<header<<endl;
//		for(auto it : mp)
//		{
//			cout<<it.first<<" "<<it.second<<endl;
//		}
	}
	
	string converttostring(int n)
	{
		string s = "";
		
		while(n)
		{
			if(n&1){
				s.push_back('1');
			}
			else{
				s.push_back('0');
			}
			n = n/2 ;
		}
		
		if(s.size() < 7)
		{
			int a = 7 - s.size();
			while(a--)
			{
				s.push_back('0');
			}
		}
		
		return s;
	}
	
	string convertTexttoBinary()
	{
		string binarydata = "";
		
		int index = text.size()-1;
		string s = "";
		while(text[index] == '1' || text[index] == '0')
		{
			s.push_back(text[index]);
			index--;	
		}
		
		reverse(s.begin() ,s.end());
		string temp = s;
		
//		cout<<"text: "<<text<<endl;
//		cout<<"Temp "<<temp<<endl;
		for(int i = 0 ; i <= index ; i++)
		{
			string s = converttostring(text[i]);
			//cout<<text[i]<<" "<<s<<endl;
			if(s.size() < 7)
			{
				int a = 7 - s.size();
				string p = "";
				while(a--)
				{
					p.push_back('0');
				}
				s = s + p;
			}
			
			binarydata += s ;
		}
		
		binarydata += temp ;
		
		//cout<<"binarydata : "<<binarydata<<endl;
		
		return binarydata;
	}
	
	string mapthecode()
	{ 
		string textobinary = convertTexttoBinary();
		//cout<<"binarydata : "<<textobinary<<endl;
		
//		cout<<"Codes : "<<endl;
//		for(auto it : mp)
//		{
//			cout<<it.second<<" "<<it.first<<endl;
//		}
	
		string s = "";
		string decodeddata = "";
		
		for(char c : textobinary){
			s.push_back(c);
			//cout<<s<<endl;
			if(mp.find(s) != mp.end()){
				decodeddata.push_back(mp[s]);
				s = "";
			}
		}
		
		decodeddata.push_back(mp[s]);
		
		//cout<<"Decoded data : "<<endl;
		//cout<<decodeddata<<endl;
		
		return decodeddata ;
		
	}
	
	string perform()
	{
		saperateHeaderandText();
		mapthcodefromheader();
		string s = mapthecode();
		return s;	
	}
};
