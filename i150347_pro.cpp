// i150347_pro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;







*/
class BTreeNode;
class BTree;

class Simple_list
{
	struct Node
	{
		int n;
		Node *next = NULL;
	};
	Node   *head;
public:
	Simple_list()
	{
		head = NULL;
	}
	void insert_no(int N)
	{
		if (head == NULL)
		{
			head = new Node;
			head->next = NULL;
			head->n = N;
		}
		else if (head != NULL)
		{
			Node *temp = head;
			while (temp != NULL)
			{
				temp = temp->next;
			}
			temp = new Node;
			temp->n = N;
			temp->next = NULL;
		}
		
	}

	void display_list()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->n << " ";
		}
		cout << endl;
	}
	void delete_nodes()
	{
		Node *current_node = head;
		if (head != NULL)
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

	void del_node(Node  *ptr)
	{
		if (ptr->next == NULL)
		{
			return;
		}
		del_node(ptr->next);
		delete ptr; //may be error...............
	}
	int count_no_of_nodes()
	{
		int count = 0;
		Node *temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
		}
	}
	int return_last_node()
	{
		int s = 0;
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		s = temp->n;
		delete temp;
		temp = NULL;
		return s;
	}
	~Simple_list()
	{
		delete_nodes();
	}

};




int Total_No_of_Words_in_Vocabulary;
class List
{
	struct Node
	{
		string words = "";
		int no_of_times_word_occured = 0;
		int ID = 0;
		Node *next = NULL;
	};
	Node   *head;
	static int count_total_words;
public:
	List()
	{
		head = NULL;
	}
	void insert_word(string s,int id)
	{
		if (head == NULL)
		{
			head = new Node;
			head->next = NULL;
			head->words = s;
			head->ID = id;
			count_total_words++;
			(head->no_of_times_word_occured)++;
		}
		if (head != NULL)
		{
			bool ss = 0;
			Node *temp = head;
			while(temp!=NULL)
			{
				if (temp->words == s)
				{
					(temp->no_of_times_word_occured)++;
					ss = 1;
				}
				temp = temp->next;	
			}
			if (ss == 0)
			{
				temp = new Node;
				temp ->next = NULL;
				temp->ID = id;
				temp->words = s;
				(temp->no_of_times_word_occured)++;
				count_total_words++;
			}
		}
	}

	void display_list()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->words << " ";
		}
		cout << endl;
	}
	void delete_nodes()
	{
		Node *current_node = head;
		if (head != NULL)
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

	void del_node(Node  *ptr)
	{
		if (ptr->next == NULL)
		{
			return;
		}
		del_node(ptr->next);
		delete ptr; //may be error...............
	}
	//insert in B-tree;
	
	static int get_total_no_of_words_in_vocab() 
	{
		return count_total_words;
	}

	~List()
	{
		delete_nodes();
	}

};
int List::count_total_words = 0;



class ABC_ASCII
{
	
	struct abc
	{
		int ascii_value;
		List L;
	};
	abc  *abc_ascii_nodes;

public:
	Simple_list simp_list;
	ABC_ASCII()
	{
		abc_ascii_nodes = new abc[53];
		for (int i = 0; i < 52; i++)
		{
			if (i <= 25)
			{
				abc_ascii_nodes[i].ascii_value = i + 65;
			}
			else if (i >= 26)
			{
				abc_ascii_nodes[i].ascii_value = i + 71;
			}
		}
		read_from_file();
	}
	//Binary Search......................................................................................
	int binarySearch(int value)
	{
		int first = 0, last = 51, middle, position = -1;
		bool found = false;
		while (!found && first <= last)
		{
			middle = (first + last) / 2;  // Calculate mid point
			if (abc_ascii_nodes[middle].ascii_value == value)   // If value is found at mid
			{
				found = true;
				position = middle;
			}
			else if (abc_ascii_nodes[middle].ascii_value > value) // If value is in lower half
				last = middle - 1;
			else
				first = middle + 1;	    // If value is in upper half
		}
		return position;
	}

	void read_from_file()
	{
		int simpi = 4;
		string str, word = "";
		int a;
		static int idd = 1; 
		ifstream file;
		file.open("test.en-de.en");
		if (!file.is_open())
		{
			cout << "File does not readed successfully!" << endl;
		}
		else if (file.is_open())
		{
			cout << "File readed succesfully!" << endl;
			abc_ascii_nodes[0].L.insert_word("AAA",0 ); //1st 2 wordsssssss
			abc_ascii_nodes[0].L.insert_word("AAAAAA", 1);

			while (!file.eof())
			{
				getline(file, str);
				for (int i = 0; i < str.length(); i++)
				{
					if (str[i] != ' ')
					{
						word = word + str[i];
						a = int(word[0]);
						idd++;
						abc_ascii_nodes[binarySearch(a)].L.insert_word(word,idd);
						simpi++;
						
					}
					else if (str[i] == '.' || str[i] == '?')
					{
						word = str[i];
						idd++;
						abc_ascii_nodes[52].L.insert_word(word,idd);
						if (str[i] == '.' || str[i] == '?')
						{
							simpi++;
							simp_list.insert_no(simpi);
							simpi = 4;
						}
						
					}
				}

			}
			abc_ascii_nodes[51].L.insert_word("zzz", abc_ascii_nodes[51].L.get_total_no_of_words_in_vocab());
			abc_ascii_nodes[51].L.insert_word("zzzzzz", abc_ascii_nodes[51].L.get_total_no_of_words_in_vocab());
			Total_No_of_Words_in_Vocabulary= abc_ascii_nodes[51].L.get_total_no_of_words_in_vocab();
			
		}
	}
	
	
	~ABC_ASCII()
		{
			delete[]abc_ascii_nodes;
		}

};
// This values will be stored in B-Treee to make search easier;
//													B-Tree
//                                                  
//                                                  B-Tree

class BTreeNode
{
	int *keys;  
	int t;      
	BTreeNode **C; 
	int n;     
	bool leaf; 
public:
	BTreeNode(int _t, bool _leaf);   
	void insertNonFull(int k);
	void splitChild(int i, BTreeNode *y);
	void traverse();
	BTreeNode *search(int k);   
	friend class BTree;
};


class BTree
{
	BTreeNode *root; 
	int t;  
public:
	
	BTree(int _t)
	{
		root = NULL;  t = _t;
	}


	void traverse()
	{
		if (root != NULL) root->traverse();
	}

	
	BTreeNode* search(int k)
	{
		return (root == NULL) ? NULL : root->search(k);
	}

	void insert(int k);
};


BTreeNode::BTreeNode(int t1, bool leaf1)
{

	t = t1;
	leaf = leaf1;

	keys = new int[2 * t - 1];
	C = new BTreeNode *[2 * t];


	n = 0;
}


void BTreeNode::traverse()
{
	
	int i;
	for (i = 0; i < n; i++)
	{
		
		if (leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}

	if (leaf == false)
		C[i]->traverse();
}


BTreeNode *BTreeNode::search(int k)
{
	
	int i = 0;
	while (i < n && k > keys[i])
		i++;


	if (keys[i] == k)
		return this;

	
	if (leaf == true)
		return NULL;

	return C[i]->search(k);
}


void BTree::insert(int k)
{
	
	if (root == NULL)
	{
		
		root = new BTreeNode(t, true);
		root->keys[0] = k;  
		root->n = 1;  
	}
	else 
	{
		
		if (root->n == 2 * t - 1)
		{
			
			BTreeNode *s = new BTreeNode(t, false);

			s->C[0] = root;

			s->splitChild(0, root);

			\
			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->C[i]->insertNonFull(k);
			root = s;
		}
		else  
			root->insertNonFull(k);
	}
}


void BTreeNode::insertNonFull(int k)
{
	int i = n - 1;

	
	if (leaf == true)
	{
	
		while (i >= 0 && keys[i] > k)
		{
			keys[i + 1] = keys[i];
			i--;
		}

		keys[i + 1] = k;
		n = n + 1;
	}
	else 
	{
		while (i >= 0 && keys[i] > k)
			i--;
		if (C[i + 1]->n == 2 * t - 1)
		{
			splitChild(i + 1, C[i + 1]);
			if (keys[i + 1] < k)
				i++;
		}
		C[i + 1]->insertNonFull(k);
	}
}
void BTreeNode::splitChild(int i, BTreeNode *y)
{
	BTreeNode *z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;
	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + t];
	if (y->leaf == false)
	{
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}
	y->n = t - 1;
	for (int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];
	C[i + 1] = z;
	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];

	keys[i] = y->keys[t - 1];
	n = n + 1;
}
struct Matrix
{
	int total_Row;
	int total_Column;
	double **matrix;
public:
	Matrix(int r = 0, int c = 0)
	{

		total_Column = c;
		total_Row = r;
		matrix = new double*[r];
		for (int i = 0; i < r; ++i)
		{
		
		matrix[i] = new double[c];
		}
		for (int i = 0; i < r;i++)
		{
			for (int j = 0; j < c; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix &temp)
	{
		for (int i = 0; i < total_Column; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		//delete last matrix;
		total_Column = temp.total_Column;
		total_Row = temp.total_Row;
		matrix = new double*[total_Row];
		for (int i = 0; i < total_Row; ++i)
		{

			matrix[i] = new double[total_Column];
		}
		for (int i = 0; i < temp.total_Row; i++)
		{
			for (int j = 0; j < temp.total_Column; j++)
			{
				matrix[i][j] = temp.matrix[i][j];
			}
		}

	}

	void display_matrix()
	{
		for (int i = 0; i < total_Row; i++)
		{
			for (int j = 0; j < total_Column; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	Matrix operator=(Matrix &obj) const
	{
		Matrix temp;
		temp.total_Column = obj.total_Column;
		temp.total_Row = obj.total_Row;
		for(int i = 0; i < temp.total_Row; i++)
		{
			for (int j = 0; j < temp.total_Column; j++)
			{
				temp.matrix[i][j] = obj.matrix[i][j];
			}
		}
		return temp;
	}
	~Matrix()
	{
		for (int i = 0; i < total_Column; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};

class Log_Linear_Language_Model
{
	int total_words_in_vocabulary;
	int total_no_of_trigrams;
	Matrix W;
	Matrix b;
	Matrix probabbility;
	Matrix loss_mat;
	//Inialize W B X
	//find prob
	//then score
    //the perplexity
public:
	Log_Linear_Language_Model() :W(Total_No_of_Words_in_Vocabulary,Total_No_of_Words_in_Vocabulary),b(Total_No_of_Words_in_Vocabulary,1),probabbility(Total_No_of_Words_in_Vocabulary,Total_No_of_Words_in_Vocabulary-2),loss_mat(0,0)
	{
		total_words_in_vocabulary = Total_No_of_Words_in_Vocabulary;
		total_no_of_trigrams = total_words_in_vocabulary - 2;
		for (int i = 0; i < W.total_Row; i++)
		{
			for (int j = 0; j < W.total_Column; j++)
			{
				W.matrix[i][j] = rand() % 5 + 1;
			}
		}
		for (int i = 0; i < b.total_Row; i++)			//iniatlize W and b
		{
			for (int j = 0; j < b.total_Column; j++)
			{
				b.matrix[i][j] = rand() % 5 + 1;
			}
		}
	}
	//.......................................................................................................................


	void Calculate_probabilities()
	{
		for (int i = 0; i < total_no_of_trigrams; i++) //for n-trgrams
		{
			int norm_b, norm_w;
			updation:
			for (int j = 0; j < probabbility.total_Row; j++) 
			{
				probabbility.matrix[j][i] = (W.matrix[j][i]) + (W.matrix[j][i+1]) + (b.matrix[j][0]);	//this will be S																				//downword
			}
			exponents_of_S(i); //theis will the expotential form of S
			double s=calculate_sum_of_expo(i);
			calculate_original_Prob(i, s); //original prob;
			loss_mat = probabbility;           //copy constructor for finding loss
			caluculate_loss_vectors(i);        //will calculate loss vector 
			norm_b= calculate_norm_of_loss_vector(i); //norm of loss vector for updation of b
			if (norm_b != 0)
			{
				update_b(i);
			}
			calculate_loss_vector_for_W(i); 
			norm_w = calculate_norm_of_loss_vector(i);
			if (norm_w != 0)
			{
				update_w(i);
			}
			if (norm_w != 0 || norm_b != 0)
			{
				goto updation;
			}
	    }
	}


	string Generate_new_Sentence()
	{
		string sent = "";
		Calculate_probabilities();
		for (int i = 0; i < total_no_of_trigrams; i++)
		{
			if (when_to_stop_sentence(i) == true)
			{
				return sent;
			}
			sent = sent + Generate_word(i);
			sent = sent + " ";
		}

	}
	//...............................................................................................

	void exponents_of_S(int a) //a=i
	{
		for (int b = 0; b < probabbility.total_Row; b++)
		{
			probabbility.matrix[b][a] = exp(probabbility.matrix[b][a]);
		}
	}
	double calculate_sum_of_expo(int a) //a=i
	{
		double sum = 0;
		for (int b = 0; b < probabbility.total_Row; b++)
		{
			sum = sum + probabbility.matrix[b][a];
		}
		return sum;
	}
	void calculate_original_Prob(int a,double ss)
	{
		for (int b = 0; b < probabbility.total_Row; b++)
		{
			(probabbility.matrix[b][a]) = (probabbility.matrix[b][a]) / ss;
		}
	}
	void caluculate_loss_vectors(int ii)
	{
		loss_mat.matrix[ii][ii] = loss_mat.matrix[ii][ii] - 1;
		loss_mat.matrix[ii+1][ii] = loss_mat.matrix[ii+1][ii] - 1;
	}
	int calculate_norm_of_loss_vector(int ii)
	{
		double sum = 0;
		for (int j = 0; j < loss_mat.total_Row; j++)
		{
			sum = sum + loss_mat.matrix[j][ii];
		}
		return abs(sum);
	}

	void update_b(int ii)
	{
		for (int j = 0; j < loss_mat.total_Row; j++)
		{
			b.matrix[j][0] = (b.matrix[j][0]) - (0.3*(loss_mat.matrix[j][ii]));  //0.3 is the value of Alpha
		}
	}
	void calculate_loss_vector_for_W(int ii)
	{
		for (int j = 0; j < loss_mat.total_Row; j++)
		{
			if (ii != j || (ii + 1) != j)
			{
				loss_mat.matrix[j][ii] = 0;
			}
		}
	}

	void update_w(int ii)
	{
		for (int j = 0; j < loss_mat.total_Row; j++)
		{
			W.matrix[j][ii] = (W.matrix[j][ii]) - (loss_mat.matrix[j][ii]);
			W.matrix[j][ii + 1] = (W.matrix[j][ii + 1]) - (loss_mat.matrix[j][ii]);
		}
	}

	int search_maximum_prob_index(int ii)
	{
		double temp = -1000000000;
		int index;
		for (int j = 0; j < probabbility.total_Row; j++)
		{
			if (probabbility.matrix[j][ii] > temp)
			{
				temp = probabbility.matrix[j][ii];
				index = j;
			}
		}
		return index;
	}

	bool when_to_stop_sentence(int ii)
	{
		int word_index = search_maximum_prob_index(ii);
		if (word_index == ((probabbility.total_Row) - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string Generate_word(int ii)
	{
		int word_index = search_maximum_prob_index(ii);
		if (word_index != ((probabbility.total_Row) - 1))
		{
			//search from the  binary tree return string;
		}
	}

	Matrix Multiply_all_context_probability()  //linear row
	{
		Matrix temp(0, probabbility.total_Column);
		for (int i = 0; i < temp.total_Column; i++)
		{
			for (int j = 0; j < temp.total_Row; j++)
			{
				temp.matrix[0][i] = (temp.matrix[0][i])*(temp.matrix[j][i]);
			}
		}
		return temp;
	}

	double log_likelihood(const Matrix &t)
	{
		double sum = 0;
		for (int i = 0; i < t.total_Column; i++)
		{
			sum += (log(t.matrix[i][0]));
		}
		return sum;
	}

	double average_log_likelihood()
	{
		return (log_likelihood(Multiply_all_context_probability())/ total_words_in_vocabulary);
	}
	
	//Actually,My project file has been losted by me...so i recovered it roughly in last hour
	double Get_perplexity()
	{
		return exp(-average_log_likelihood());
	}
	Matrix get_W()const
	{
		return W;
	}
	Matrix get_probablities()const
	{
		return probabbility;
	}
	Matrix get_B()const
	{
		return b;
	}
};

void Project()
{
	int p, ttt, c;
	ABC_ASCII abc;
	//B-tree
	Log_Linear_Language_Model Linear;
	cout << "Total No of Words in vocab =" << Total_No_of_Words_in_Vocabulary << endl;
	cout << endl << "The New Generated sentence is as follows:" << endl << endl;
	cout << Linear.Generate_new_Sentence() << endl;
	cout << "W is as follows::    " << endl << endl;
	Linear.get_W().display_matrix();
	cout << endl<<"W is as follows::    " << endl << endl;
	Linear.get_B().display_matrix();
	p = Linear.Get_perplexity();
	cout << "Perplexity of trained data=  " << Linear.Get_perplexity() << endl << endl;

	//The following code is for calculating perplexity difference
	c = abc.simp_list.count_no_of_nodes();
	for (int i = 0; i < c; i++)
	{
		Total_No_of_Words_in_Vocabulary = abc.simp_list.return_last_node();
		Log_Linear_Language_Model test;
		test.Calculate_probabilities();
		ttt = ttt + test.Get_perplexity();
	}
	ttt = (ttt / c);
	cout << "Perplexity of test data=  " << ttt << endl << endl;
	cout << "Perplexity Difference=     " << abs(ttt - p) << endl;
}


int main()
{
	cout << "log linear method:" << endl;
	Project();

	
	system("Pause");
    return 0;
}

