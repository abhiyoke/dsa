#include <bits/stdc++.h>
using namespace std;
 
struct node
{
      string word;
      node * next; 
      node(){next = NULL;} 
};
 
 
struct hash_table
{
        node *table[29]={NULL},*c;       
        
        void insert(string);
        void search(string);  
        void display();    
};
 
 
int hashing(string wrd)
{
        int len = wrd.size() - 1;
        int hash_index = 0;
        for (int i = 0; i<= len; i++)
        {
                hash_index += (wrd[i]*(pow(31,i)));
        }
        return hash_index % 29;       
}
 
void hash_table :: insert(string wrd)
{
        int x = hashing(wrd);
        node* temp = new node;
        temp->word = wrd;
        temp->next = NULL;
        if(table[x] == NULL)
        {
                table[x] = temp;
        }
        else
        {
                temp->next = table[x];
                table[x] = temp;
        }
}
 
 
void hash_table :: search(string wrd)
{
         int x = hashing(wrd);
         node * temp = table[x];
         bool flag = false;
         while( temp != NULL )
         {               
                if(temp->word == wrd)            
                {
                        cout<<"spelling is correct"<<endl;
                        flag = true;
                        break;                       
                }
                else                    temp = temp->next;
         }
         if(flag == false)      cout<<"spelling is incorrect "<<endl;             
}
 
 
void hash_table::display()
{
    cout<<"  "<<"Index"<<"   "<<endl;;
    for(int i=0; i<29 ;i++)
    {
        cout<<"  "<<i<<"  ";       
        if(table[i]==NULL)       cout<<"-1"<<endl;
        
        else
        {
            c=table[i];
            while(c!=NULL)
            {
                cout<<c->word<<" -> ";
                c=c->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
 
 
int main()
{
        hash_table table;
        string word;
        
        ifstream in;
        ofstream out;
        in.open("word.txt");
        while ( !in.eof() ) 
        {  
            in>>word;
            table.insert(word);       
        }
        in.close();
        
        int choice;
	do
	{
		cout<<"1. Insert"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Search "<<endl;
		cout<<"4. EXIT"<<endl;
		cout<<"Enter the choice : ";
		cin>>choice;
		
		switch(choice){
			case 1: 
			        cout<<"enter the word :";
			        cin>>word;
			        table.insert(word);	
			        
			        out.open("word.txt", ios :: app);
			        out<<word<<" ";
			        out.close();
				break;
		        case 2:
		                table.display();
		                break;
				
			case 3:
			        cout<<"enter the word to search :";
			        cin>>word;
			        table.search(word);						
				break;	
			default:
			        exit(0);
			        break;		
		}
		cout<<endl; 
		
	} while (0< choice < 4);      
        return 0;
}
