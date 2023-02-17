
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{

	unordered_map<char,TrieNode*> child;

	bool isLast;

	// Default Constructor
	TrieNode()
	{
		// Initialize all the Trie nodes with NULL
		for (char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;

		isLast = false;
	}
};

TrieNode *root = NULL;

// Insert a single Contact into the Trie
void insert(string s)
{
	int len = s.length();

	TrieNode *itr = root;
	for (int i = 0; i < len; i++)
	{

		TrieNode *nextNode = itr->child[s[i]];
		if (nextNode == NULL)
		{

			nextNode = new TrieNode();

			// Insert into the Map
			itr->child[s[i]] = nextNode;
		}

		itr = nextNode;

		if (i == len - 1)
			itr->isLast = true;
	}
}

void displayContactsUtil(TrieNode *curNode, string prefix)
{

	if (curNode->isLast)
		cout << prefix << endl;

	for (char i = 'a'; i <= 'z'; i++)
	{
		TrieNode *nextNode = curNode->child[i];
		if (nextNode != NULL)
			displayContactsUtil(nextNode, prefix + (char)i);
	}
}



void displayContacts(string str)
{
	TrieNode *prevNode = root;

	string prefix = "";
	int len = str.length();


	int i;
	for (i=0; i<len; i++)
	{
		prefix += (char)str[i];

		char lastChar = prefix[i];

		TrieNode *curNode = prevNode->child[lastChar];

		if (curNode == NULL)
		{
			cout << "\nNo Results Found for " << prefix << " \n";
			i++;
			break;
		}

		cout << "\nSuggestions based on " << prefix<< " are \n";
		displayContactsUtil(curNode, prefix);

		prevNode = curNode;
	}

	for (; i<len; i++)
	{
		prefix += (char)str[i];
		cout << "\nNo Results Found for " << prefix<< " \n";
	}
}

void insertIntoTrie(string contacts[],int n)
{

	root = new TrieNode();

	for (int i = 0; i < n; i++)
		insert(contacts[i]);
}

int phonebook()
{

	string contacts[] = {"sanjana" , "bharathi","benny","aayush","prethika","partha","krithika","sanjay","varsha","nilavini","nithish","vamsi","abinaya","aakash","samyugtha"};

	int n = sizeof(contacts)/sizeof(string);

    int startingLetter[26];


	for(int i=0;i<26;i++){
        startingLetter[i] = 0;
	}

	insertIntoTrie(contacts, n);
	int ch;
	string str;

	do{
        cout<<endl<<"\t 1) Display contacts";
        cout<<endl<<"\t 2) Search contact";
        cout<<endl<<"\t 3) Insert contact";
        cout<<endl<<"\t 0) Exit";
        cout<<endl<<" Enter choice : ";
        cin>>ch;

        switch(ch){
            case 1: for (int i=0;i<n;i++){
                        cout<<endl<<contacts[i];
                    }


                    break;
            case 2: cout<<endl<<"Enter String to Query : ";
                    cin>>str;
                    displayContacts(str);

                    break;
            case 3: cout<<endl<<"Enter contact : ";
                    cin>>str;
                    //insert(str);
                    contacts[n] = str;
                    n++;
                    insertIntoTrie(contacts,n);
                    break;
            case 0:
                return 0;


        }

	}while(ch!=0);


	return 0;
}

