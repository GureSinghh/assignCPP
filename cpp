#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void Frequency(vector<char>indexOFmatched);



/*-----------------------------------funtion which ask for user first input return it------------------------------------------------------------------*/
char askFORinput(char input)
{
    cout<<"Please enter an alphabetic character?  : ";
    cin>>input;
    return input;
}



/*_________________________________________________________________________________________________________________________________________________*/


/*-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 void CompareArrayWithUserInput(vector<string> vec,char usInput){
          
        vector<char>indexOFmatched;
        vector<string>Strword;
        char userInput=usInput;
       
            
            for(auto it:vec)
            {
                
                string word=it;
                int l=it.length();
                    for(int i=0;i<=l;i++)
                    {
                        if(userInput==word[i]&&word[i]==word[i+1])//if find duplicate of userInput turn matched true
                            {
                               indexOFmatched.insert(indexOFmatched.end(),word[0]);
                               Strword.insert(Strword.end(),word);
                              
                            }
                    }
            
            }
/*--------------------------------------------------------------------*/            
            int totalwords=0;

            for(auto it:indexOFmatched)
                {
                    totalwords+=1;
                }
            cout<<"The words that include "<<userInput<<userInput<<" are "<<totalwords<<endl;
/*--------------------------------------------------------------------*/    
         
            for(auto it:Strword)
                {
                    cout<<it<<endl;
                }

/*--------------------------------------------------------------------*/                 
        Frequency(indexOFmatched);
          
 }
                
    /*    if(matched)
        {
            run(Strword,userInput);
        }
     

 


  **************read file and store in array************************/


void Frequency(vector<char>indexOFmatched)
{
     char arr[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    int a;
    
      int totalwords[26];    
    
    

int i=0;int storVal=0;bool start=true;


/*******************************/




while(start)
{
    
  for(auto it:indexOFmatched)
  {
      if(toupper(it)==arr[i])
      {
          storVal+=1;
          
      }
    
  }
  totalwords[i]=storVal;
  storVal=0;
   if(i==26)
   {
       start=false;
   }
    i++;
}

cout<<"How would you like to display the result? "<<endl;
     cout<<"1- Tabular form "<<endl;
     cout<<"2- Bar chart "<<endl;
     cout<<"Please enter either 1 or 2. You can end the program if you enter any other number :";
     cin>>a;
     cout<<endl;
     cout<<"Rating"<<"           "<<"Frequency"<<endl;
     cout<<"______"<<"           "<<"_________"<<endl;






int val=65;
if(a==1)
{
    for(int i=0;i<=25;i++)
{ 
 cout<<char(val)<<"                 "<<totalwords[i]<<endl ;
 val++;
}
}
}




/*-------------------------------------------------------------MAIN BODY--------------------------------------------------------------------------------------------*/

int main()
{  
      int chk=0;
    while(chk!=1)
    {
        
            char userInput;//using this variable to store the user first input
            vector<string>arr;
 
 /**************************Reading File ANd storing it in arr vector array**************************/
 
             char word[100];
             ifstream myFile;
            
            myFile.open("dictionary.txt");
               
                if(myFile.is_open())
                    {
                        while(!myFile.eof())//this loop run untill the last line
                        {
                             myFile.getline(word,100);
                       arr.insert(arr.end(),word);
                        }
                    }
                else
                    {
                    cout<<"Error";
                    }
  /*********************************Aking And Storing USer Input()*****************************************************/
            
            userInput=tolower(askFORinput(userInput));
  
  
  /*********************************************this will compare stored words with user input and store it in another vector array*******************************************************/     
    
            CompareArrayWithUserInput(arr,userInput);
/*----------------------------------------------------------------------------------------------------------------------------------------*/
           
            cout<<"Want to Enter Word Again (Y/N) :";
            char yesORno;
            cin>>yesORno;
            if(toupper(yesORno)=='Y')
                {
                chk=0;
                }
            else if(toupper(yesORno)=='N')
                {
                chk++;
                }
            else
                {
                cout<<endl<<"Invalid Input"<<endl;
                }
            
    }


    
 
 
 }
     
     
    
