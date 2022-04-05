#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//void run(vector<string>strWord,char userInput);


char askFORinput(char input)
{
    cout<<"Enter the userinput"<<endl;
    cin>>input;
    return input;
}

 void CompareArrayWithUserInput(vector<string> vec,char usInput){
           vector<char>indexOFmatched;
        vector<string>Strword;
        char userInput=usInput;
        bool matched=false;
            
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
                                matched=true;
                            }
                    }
            
            }
            for(auto it:Strword)
                {cout<<it<<endl;
                }
 }
                
    /*    if(matched)
        {
            run(Strword,userInput);
        }
     
}
 

void run(vector<string>strWord,char userInput)
{
    strWord
}*/

void chartOutput() {
    char word = 'b';
    word = toupper(word);
    char arr[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int num = 0;
    for (auto it : arr) {
        if (it == word) {
            num += 1;
            cout << it << "        " << num << endl;

        } else {
            cout << it << "        "
                 << "0" << endl;
        }
    }
}

int main()
{  // getting input from user here and storing it in userInput variable*/

   bool matched=false;// int a;
    char userInput;//using this variable to store the user input
    vector<string>arr;
 
 /**************************Reading File ANd storing it in arr vector array**************************/
 
 
 ifstream myFile;
    myFile.open("dictionary.txt");
    if(myFile.is_open())
    {
        while(!myFile.eof())//this loop run untill the last line
        {
             myFile.getline(word,100);
       arr.insert(arr.end(),word);
        }
    }else{
        cout<<"Error";
   }
  /*********************************Aking And Storing USer Input()*****************************************************/
  userInput=askFORinput(userInput);
  
  /*********************************************this will compare stored words with user input and store it in another vector array*******************************************************/     
    
   CompareArrayWithUserInput(arr,userInput);



  /****************read file and store in array************************/
  

 

 chartOutput();
 
 /**************************************/ 

    
 
 
 }
     
    
