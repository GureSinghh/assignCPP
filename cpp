#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void Frequency(vector<char>indexOFmatched);//frequency chaker and outputer



/*-----------------------------------funtion which ask for user first input return it------------------------------------------------------------------*/
char askFORinput(char input)
{
    cout<<"Please enter an alphabetic character?  : ";
    cin>>input;
    return input;
}



/*_________________________________________________________________________________________________________________________________________________*/


/*--------------------------------function that compare userInput with  list of array and which qualified requirments it stores that word in diffrent array---------------------------------------------------------------------------------------------*/
 void CompareArrayWithUserInput(vector<string> vec,char usInput)//taking vector array and userInput as argument
 {
          
        vector<char>indexOFmatched;//this stores a total index values of qualified words
        vector<string>Strword;//this vactor array is used for storing total qualified words
        char userInput=usInput;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/       
            
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
/*-------------------------- here we counts that how many total words are exist which are qualified acc. to user input------------------------------------------*/            
            int totalwords=0;

            for(auto it:indexOFmatched)
                {   
                    totalwords+=1;
                }
              
            cout<<"The words that include "<<userInput<<userInput<<" are "<<totalwords<<endl;//printing out total words
/*-----------------------------------here we are printing all qualified words as list ---------------------------------*/    
         
            for(auto it:Strword)
                {
                    cout<<it<<endl;
                }

/*--------------------------------------------------------------------*/                 
        Frequency(indexOFmatched);//passing vector which holds index value of words,as argument to the frequency function
          
 }
                
    

 


  /**************read file and store in array************************/


void Frequency(vector<char>indexOFmatched)//function user to calculate frequency with taks vector array which has all unique words index values that are matched with user input
{
     char arr[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',//arr is used to stor the A to Z alphabets
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    int a;
    
      int totalwords[26];//when storVal stors a value we store it in this array here    
    
    

int i=0;
int storVal=0;//store value of that how many total words are exist in list which start from perticular charcters
bool start=true;//used to turn of the while loop when its task get completed


/*******************************/




while(start)//it will keep runing until start is equal to true
{
    
  for(auto it:indexOFmatched)
  {
      if(toupper(it)==arr[i])
      {
          storVal+=1;
          
      }
    
  }
  totalwords[i]=storVal;//it adds a storVal into array 
  storVal=0;
   if(i==26)
   {
       start=false;//its end the while loop when i == 26
   }
    i++;
}

    cout<<"How would you like to display the result? "<<endl;//Giving user two choices to print data
     cout<<"1- Tabular form "<<endl;//first as tabular for and second is bar chart as u can see number 2
     cout<<"2- Bar chart "<<endl;
     cout<<"Please enter either 1 or 2. You can end the program if you enter any other number :";//asking user to input number 1 or 2 acc. to what type of output they want.
     cin>>a;//storing that choice number of user here
     cout<<endl;
     cout<<"Rating"<<"           "<<"Frequency"<<endl;//just printing some headings lines 
     cout<<"______"<<"           "<<"_________"<<endl;





int val=65;//storing ascii value of character 'A'
if(a==1)//if user puts 1 as input this output will print
{
    for(int i=0;i<=25;i++)//this loop will not stop until it will complete 0 to 25 cycles
{ 
 cout<<char(val)<<"                 ";//printing A to Z characters
 if(a==1)
 {
     cout<<totalwords[i]<<endl ;//this print total number of words start from that charcters
 }
     
 }
 val++;
}else if(a==2)//if user puts 2 as input this output will get printed
{
    for(int i=0;i<=25;i++)
        { 
         cout<<char(val)<<"                 ";//same printing A to Z
        if(a==2)
            {
            int size=totalwords[i];
            for(int i=0;i<=size-1;i++)
            {
                cout<<"*";//if input from user is 2 it will print '*'instead of numbers
            }
            cout<<endl;
            }
        val++;
    }
}
}




/*-------------------------------------------------------------MAIN BODY--------------------------------------------------------------------------------------------*/

int main()
{  
      int chk=0;//stores a choice of user that they wanna start this program again or not
    while(chk!=1)
    {
        
            char userInput;//using this variable to store the user first input
            vector<string>arr;//storing words of that file in here 
 
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
  
  
  /*********************************************this will compare words with user input and store it in another vector array*******************************************************/     
    
            CompareArrayWithUserInput(arr,userInput);
/*--------------------------------------------------------------- asking user that if they wanna start searching for words or not(if they wanna start program again or not)-------------------------------------------------------------------------*/
           
            cout<<"Would you like to enter a new letter(Y/N)? ";
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
     
