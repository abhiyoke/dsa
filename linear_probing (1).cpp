#include <bits/stdc++.h>
using namespace std;

struct Rec
{
        int prn;
        int marks;
        int link;
};


int main()
{
        int size = 23;
        int roll;
        int mrk;
        int insert_count = 0;
        int search_count = 0;
        Rec arr[size];
        for (int i = 0; i <size; i++)
        {
                arr[i].prn = -1;
                arr[i].marks = -1;
                arr[i].link = -1;
        }
        int choice;
        
        do
        {
               cout<<"enter your choice : "<<endl;
               cout<<"1. insert "<<endl;
               cout<<"2. delete "<<endl;
               cout<<"3. search "<<endl; 
               cout<<"4. display "<<endl;
               cout<<"5.quit   " <<endl;
               cin>>choice;
               
               switch(choice)
               {
                        case 1 :
                                 //insert();
                                 insert_count = 0;
                                  cout<<"enter prn and marks : ";
                                  cin>>roll>>mrk;
                                  if (arr[roll%size].prn == -1 || arr[roll%size].prn == -2 )
                                  {
                                        arr[roll%size].prn = roll;
                                        arr[roll%size].marks = mrk;
                                        insert_count++;
                                  }
                                  else 
                                  {
                                        int y = roll%size;
                                        while(arr[y].prn!=-1 && arr[y].prn!= -2)          
                                        {
                                                y++;
                                                y = y%size;
                                                insert_count++;
                                        }
                                        arr[y].prn = roll;
                                        arr[y].marks = mrk;
                                        insert_count++;
                                     }

                                     cout<<"no of comparison required for insertion : "<<insert_count<<endl;
                                 break;

                        case 2 :
                                 //delete();
                                 
                                 cout<<"enter prn to be deleted ";
                                 cin>>roll;                                
                                 
                                 if (arr[roll%size].prn == roll)
                                 {
                                        arr[roll%size].prn = -2;
                                        arr[roll%size].marks  = -1;
                                 } 
                                 else
                                 {
                                        int y = roll%size;
                                        y++;
                                        while(y%size!= roll%size)
                                        {
                                                if (arr[y%size].prn == roll)
                                                  {
                                                        arr[y%size].prn = -2;
                                                        arr[y%size].marks = -1;
                                                  }
                                                  else          y++;
                                        }                                       
                                 }                                                              
                                 break;

                        case 3 :
                                //search();
                                search_count = 0;
                                cout<<"enter prn to search "<<endl;
                                cin>>roll;
                                
                                if (arr[roll%size].prn == roll)     
                                {
                                        cout<<"prn found with no of comparisons : 1"<<endl;                                      
                                }
                                else
                                {
                                        search_count = 1;
                                        int y = roll%size;
                                        y++;
                                        bool flag = 0;
                                        while(y%size!= roll%size)
                                        {
                                                if (arr[y].prn == roll)
                                                {
                                                        search_count++;
                                                        cout<<"prn found at index :"<<y%size<<endl;
                                                        cout<<"no of comparisons for searching : "<<search_count<<endl;
                                                        flag = 1;
                                                        
                                                        break;
                                                }
                                                else      
                                                {
                                                        search_count++;
                                                        y++;
                                                        y = y%size;
                                                        
                                                }
                                        }
                                        if (flag == 0)                         cout<<"prn not found"<<endl;                                   
                                 }                               
                                break;

                        case 4 :
                                //display();
                                
                                cout<<"prn"<<"\t"<<"marks"<<"\t"<<"link"<<endl;
                                for (int i = 0; i <size; i++)
                                {
                                        cout<<arr[i].prn<<"\t"<<arr[i].marks<<"\t"<<arr[i].link<<endl;
                                }                             
                                break;

                        default :
                                exit(0);                  
               }              
        }    while (0<choice<4);
               
        return 0;
}


