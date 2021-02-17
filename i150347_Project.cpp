// i150347_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ABC_Array;
class Verticle_List;

class Horizontal_List
{
	struct Horizontal_List_Node
	{
		Verticle_List *ptr_to_vertical = NULL;
		Horizontal_List_Node  *next = NULL;
		int sentence_no = 0; ///bhsvbahbshbsabsaqb
		int count_word_in_single_sentence; //ghsdbshbdshbdhbsdhbsh
	};
	Horizontal_List_Node *Head;
public:
	Horizontal_List()
	{
		Head = NULL;
	}
	bool is_empty()
	{
		if (Head == NULL);
		{
			return true;
		}
	}
	void add_horizontal_Node()
	{
		if (is_empty())
		{
			Horizontal_List_Node *Current_node = new Horizontal_List_Node;
			Head = Current_node;
			Current_node->next = NULL;
			Current_node->ptr_to_vertical; //sduggasydashdhsadhbasdsadhysayhdhsy
			Current_node->sentence_no;  //hcbdshfwfusadhbdasbdabs
		}
		else if (!is_empty())
		{
			Horizontal_List_Node *temp_node = Head;
			while (temp_node != NULL)
			{
				temp_node = temp_node->next;
			}
			temp_node = new Horizontal_List_Node;
			temp_node->next = NULL;
			temp_node->ptr_to_vertical; //sduggasydashdhsadhbasdsadhysayhdhsy
		}
	}
	void Display_Horizontal_list()
	{
		Horizontal_List_Node *current_node = Head;
		while (current_node != NULL)
		{
			cout << current_node->ptr_to_vertical; //bdhbasdbasbdhasbdbsajdh2
			current_node = current_node->next;
		}
	}
	void delete_all_nodes()
	{
		Horizontal_List_Node *current_node = Head;
		if (Head != NULL)
		{
			if (current_node->next = NULL)
			{
				delete current_node;
			}
			else
			{
				del_node(current_node);
			}
		}
	}
	
	void del_node(Horizontal_List_Node  *ptr)
	{
		if (ptr->next == NULL)
		{
			return;
		}
		del_node(ptr->next);
		delete ptr; //may be error...............
	}
		void set_senence_no(int n)
		{
		
		}
		//find node and vertex            bahusbhagbxhuahxbahbxhsabxhabhxahsxhaiuhsuhahsh
	
		~Horizontal_List()
		{
			delete_all_nodes();
		}
};


class Verticle_List
{
	struct vertical_list_node
	{
		string  name = "";
		int count_word_in_whole_data = 0;
		Horizontal_List H_list;
		vertical_list_node *next = NULL;
	};
	vertical_list_node *Head;
public:
	Verticle_List()
	{
		Head = NULL;
	}
	void add_verticle_node(string s)
	{
		if (is_empty())
		{
			vertical_list_node *Current_node = new vertical_list_node;
			Head = Current_node;
			Current_node->next = NULL;
			Current_node->count_word_in_whole_data = 1;
			Current_node->name = s;
		}
		else if (!is_empty())
		{
			vertical_list_node *temp_node = Head;
			if (!is_found(s))
			{
				while (temp_node != NULL)
				{
					temp_node = temp_node->next;
				}
				temp_node = new vertical_list_node;
				temp_node->next = NULL;
				temp_node->count_word_in_whole_data = 1;
				temp_node->name = s;
			}
			else if (is_found(s))
			{
				while (temp_node != NULL)
				{
					if (temp_node->name == s)
					{
						(temp_node->count_word_in_whole_data)++;
					}
					temp_node = temp_node->next;
				}
			}
		}

	}
	bool is_empty()
	{
		if (Head == NULL);
		{
			return true;
		}
	}
	bool  is_found(string sr)
	{
		vertical_list_node *current_node = Head;
		while (current_node!=NULL)
		{
			if (current_node->name == sr)
			{
				return true;
			}
			current_node = current_node->next;
		}
		return false;
	}

	void Display_vertical_list()
	{
		vertical_list_node *current_node = Head;
		while (current_node != NULL)
		{
			cout << current_node<< "   " << endl; //bdhbasdbasbdhasbdbsajdh2
			current_node = current_node->next;
		}
	}
	void delete_all_nodes()
	{
		vertical_list_node *current_node = Head;
		if (Head != NULL)
		{
			if (current_node->next = NULL)
			{
				delete current_node;
			}
			else
			{
				del_node(current_node);
			}
		}
	}

	void del_node(vertical_list_node  *ptr)
	{
		if (ptr->next == NULL)
		{
			return;
		}
		del_node(ptr->next);
		delete ptr; //may be error...............
	}

	~Verticle_List()
	{
		delete_all_nodes();
	}

};

class ABC_Array
{
	struct abc {
		char characters='\0';
		int  ascii_values = 0;
		Verticle_List V;
	};
	abc *abc_line;
			

public:
	ABC_Array()
	{
		abc_line = new abc[53];
		for (int i = 0; i < 52; i++)
		{
			if (i <= 25)
			{
				abc_line[i].ascii_values = i + 65;
				abc_line[i].characters = i + 65;
			}
			else if (i >= 26)
			{
				abc_line[i].ascii_values = i + 71;
				abc_line[i].characters = i + 71;
			}
		}
	}
	//........binary search is needed 
	void insert_word(string s)
	{
		int t = s[0];
		int index_abc = binarySearch(t);
		if (index_abc== -1)
		{

		}
		else if (index_abc != -1)
		{
			abc_line[index_abc].V.add_verticle_node(s);
		}

	}

	int binarySearch(int value)
	{
		int first = 0, last = 52 - 1, middle, position = -1;
		bool found = false;
		while (!found && first <= last)
		{
			middle = (first + last) / 2;  // Calculate mid point
			if (abc_line[middle].ascii_values == value)   // If value is found at mid
			{
				found = true;
				position = middle;
			}
			else if (abc_line[middle].ascii_values > value) // If value is in lower half
				last = middle - 1;
			else
				first = middle + 1;	    // If value is in upper half
		}
		return position;
	}


	~ABC_Array()
	{
		delete abc_line;
	}
};


class Language_Model
{
	ABC_Array abc;
public:
	void read_from_file()
	{
		string str, word="";
		ifstream file;
		file.open("test.en-de.en");
		if(!file.is_open())
		{
			cout << "File does not readed successfully!" << endl;
		}
		else if (file.is_open())
		{
			cout << "File readed succesfully!" << endl;
			while (!file.eof())
			{
				getline(file, str);
				for (int i = 0; i < str.length(); i++)
				{
					if (word[i] != ' ')
					{
						word = word + str[i];
						//abc.insert(word);
					}
					else if (word[i] == '.')
					{
						word = ".";
						//abc.insert(word);
					}
					word = word + str[i];
					word = "";
				}
			
			}

		}
	}
};


int main()
{
	cout << "Ghassan" << endl;
	char c = 41;
	string s = "abc";
	int t = s[0];
	cout << t << endl;
	cout << s << endl;
	cout << s.length() << endl;
	cout << c << endl;
	system("Pause");
    return 0;
}

