#include <bits/stdc++.h>
using namespace std;

class Hash
{
	public:
		int prn;
		int marks;
		int link;
		Hash()
		{
			prn = -1;
			marks = -1;
			link = -1;
		}
};

void insert(Hash table[],int size)
{
		int prn,marks,link;
		cout<<"Enter the prn, marks: ";
		cin>>prn>>marks;
		int index = prn%size;
		if(table[index].prn == -1|| table[index].prn == -2 ){
			table[index].prn = prn;
			table[index].marks = marks;
			table[index].link = -1;
		} 
		else{
			int last=index;
            if(table[index].prn%size == prn%size){
                while(table[index%size].prn!=-1 || table[index].prn == -2){
				    if(table[index].prn%size != prn%size || table[index].link == -1){
					    index++;
                                            index%=size;
					    if(table[index%size].prn%size == prn%size)last = index;
				    }
				    else{
					    index=table[index].link;
					    if(table[index].prn%size==prn%size)last = index;
				    }
                }
                table[index%size].prn = prn;
                table[index%size].marks = marks;
                if(table[last].prn%size == prn%size)table[last].link = index%size;
			    
            }
            else{
                while(table[index].prn!=-1 || table[index].prn==-2){
                    index++;index%=size;
                }
                table[index].prn = table[last].prn;
			    table[index].marks = table[last].marks;
                table[prn%size].prn = prn;
                table[prn%size].marks = marks;
                table[prn%size].link = -1;
                index = table[index].prn%size;
                last = index;
                index++;
                int cur = last;
                while(index!=cur){
                    if(table[index].prn%size !=cur){
                        index++;
                        index%=size;
                    }
                    else{
                        table[last].link = index;
                        last = index;
                        index++;
                    }
                }
            }				
		}
}

void update(Hash table[], int index, int size)
{
	int last = index;
	int mod = index;
	while(table[index].prn!=-1){
		if(table[index].link==-1 || table[index].prn%size !=mod){
			index++;
			index%=size;
			if(table[index].prn%size==mod){
				table[last].link = index;
				last = index;
			}
		}
		else if(table[index].prn%size==mod){
			int k = table[index].link;
			table[last].link = index;
			last = index;
			index = k;
		}
		else	{break;} 
	}
	table[last].link = -1;
}

void display(Hash table[], int size)
{
	cout<<"Index   "<<"PRN   "<<"MARKS    "<<"LINK "<<endl;
	for(int i = 0; i < size; i++){
		cout<<i<<"\t"<<table[i].prn<<"     "<<table[i].marks<<"      "<<table[i].link<<endl;
	}
}

int search(Hash table[], int prn, int size)
{
	int index = prn%size;
	while(table[index%size].prn!=prn){
		if(table[index].prn%size != prn%size || table[index].link == -1){
			index++;
			index%=size;
		}
		else if(table[index].link!=-1){
			index=table[index].link;
			index%=size;
		}
		if(table[index].prn==-1){
			return -1;
		}
		if(table[index].prn==prn){
			return index;
		}
	}
	if(table[index].prn==prn){
		return index;
	}
}

void Delete(Hash table[], int prn, int size)
{
	int loc = search(table,prn,size);
	int mod = table[loc].prn%size;
	table[loc].prn=-2;
	table[loc].marks=-1;
	table[loc].link= -1;
	update(table,mod,size);
}

int main()
{
	int size = 23;
	Hash table[size];
	int choice;
	
	do
	{
		cout<<"1. Add entries to the hash table"<<endl;
		cout<<"2. Search for a particular PRN no"<<endl;
		cout<<"3. Delete an entry"<<endl;
		cout<<"4. View the hash table"<<endl;
		cout<<"5. EXIT"<<endl;
		cout<<"Enter the choice: ";
		cin>>choice;
		switch(choice){
			case 1: 
					insert(table, size);
					display(table, size);
					cout<<endl;
					break;
			case 2: int find;
					cout<<"Enter the prn that is to be searched : ";
					cin>>find;
					if(search(table,find, size)==-1){
						cout<<"NOT Found!!!"<<endl;
					}
					else{
						cout<<"The element is present at index no "<<search(table,find, size)<<endl;
					}
					cout<<endl;
					break;
			case 3:
					int del;
					cout<<"Enter the prn that is to be deleted : ";
					cin>>del; 
					Delete(table,del, size);
					cout<<endl;
					break;
			case 4: 
					display(table, size);
					cout<<endl;
					break;
		}
	} while (choice != 5);
}