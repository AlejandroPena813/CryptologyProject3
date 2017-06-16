// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream
#include <vector> //vector class
#include <sstream>
#include <stdlib.h>     /* atoi */

using namespace std; //LOOK AT OFSTREAM EXAMPLE IN EXC 2 FOR CLEARING FILE

int ASCItranslate(char y){ //function translates value for me
  return int(y);
}


void task1(string fileName){ //should have stream as paramter, and return object

  int freq[256] = {0}; //will hold the freq of each value
   int x;//will contain the stream's value
   //stringstream ss; //stream to convert hex

   char str[256];
   //string line;


   std::cout << "Enter the name of the text file to be converted in program 3_1: "; //change this appearance, match example by Nemo
   //cin.ignore();
   std::cin.get (str,256);    // get c-string

   std::ifstream ts(str);     // open file
   char m;
 //is.get(c)
   //while ( getline (is,line, ' ') ) //working but not reading next digit


   while(ts.get(m))
   {
       x= ASCItranslate(m);

       freq[x] +=1;


   }

   //-n,-c,-L<n>

 //cout << "Please enter flags: n,c, or L<n>: ";

   for(int i = 0; i<256; i++){

     cout<< i <<" " <<freq[i]<< ";"<<endl;//edit this to look like required print

   }
ts.close();

}

void nybbleSub(string fileName){ //parameters and return

  vector<int> inputVec; //holds char of input
  //vector<int> inputIntVec; //holds int of input

  char str[256];


  std::cout << "Enter the name of the text file to be converted: "; //change this appearance, match example by Nemo
  //cin.ignore();
  std::cin.get (str,256);    // get c-string

  std::ifstream is(str);     // open file


  char c; //bin xout
  while (is.get(c)) {         // loop getting single characters from file
    //std::cout<< std::hex <<(int)c << " ";
    if(c != ' '){

      if(c == '0')
        inputVec.push_back(0);
      else if(c == '1')
        inputVec.push_back(1);
      else if(c == '2')
        inputVec.push_back(2);
      else if(c == '3')
        inputVec.push_back(3);
      else if(c == '4')
        inputVec.push_back(4);
      else if(c == '5')
        inputVec.push_back(5);
      else if(c == '6')
        inputVec.push_back(6);
      else if(c == '7')
        inputVec.push_back(7);
      else if(c == '8')
        inputVec.push_back(8);
      else if(c == '9')
        inputVec.push_back(9);
      else if(c == 'A' || c == 'a')
        inputVec.push_back(10);
      else if(c == 'B' || c == 'b' )
        inputVec.push_back(11);
      else if(c == 'C' ||  c == 'c')
        inputVec.push_back(12);
      else if(c == 'D' || c == 'd' )
          inputVec.push_back(13);
      else if(c == 'E' || c == 'e')
          inputVec.push_back(14);
      else if(c == 'F' || c == 'f')
          inputVec.push_back(15);

    }
  }

  //inputVec.pop_back(); //pop newline char

  for(int i = 0; i<inputVec.size(); i++){ //simple print statement, not needed

    cout<< inputVec[i]<<endl;
  }

  is.close(); // end of file input//////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////
  char keyFile[256];//file name
  char key[16];//stores 16 keys, create way of getting input
  vector<char> vecOutput;//contains encrypted version of input


  std::cout << "Enter the name of the key file: "; //change this appearance, match example by Nemo
  cin.ignore();
  std::cin.get (keyFile,256);    // get c-string

  std::ifstream ks(keyFile);     // open file

  char k; //bin xout
  int i = 0;
  while (ks.get(k)) {         // loop getting single characters from file
    //std::cout<< std::hex <<(int)c << " ";
    if(k != ' '){
      key[i] = k; //key array named above
      i++;

    }

  }

  //simple key output
  cout<< "key values: "<<endl; //may erase these testing prints
  for(int i = 0; i<16 ; i++){

    cout<< key[i] << " ";

  }

  //encrypt input into vector vecOutput
  for(int i = 0; i < inputVec.size(); i++){

    int temp = inputVec[i];
    char tmp = key[temp];
    vecOutput.push_back(tmp);

  }

  cout<< " ENCRYPTED VALUES: " <<endl;
  for(int i = 0; i < vecOutput.size(); i++){

    cout<< vecOutput[i] << " ";

  }

  ofstream outputFileNyb("nybbleOutput.txt");//name of output for transposition function
  //...
  //outputFile << "writing to file";
  for(int i=0; i<vecOutput.size(); i++)//does size change dynamically??
   outputFileNyb<< vecOutput[i] << " ";


is.close();
ks.close();
}



int transpositionFunc(string fileName){



    char str[256];
    string inputPad;
    int inputLength;

    std::cout << "Enter the name of an existing text file: ";
    std::cin.get (str,256);    // get c-string

    std::fstream trs(str, fstream::in | fstream::out);     // open file

    cout<< "Enter the block length value n (which also equals to key length): "; //make the default n = 8
    cin>>inputLength;// THIS WAS FOR REPEATING MULTIPLES OF INPUTBYTES to be encrypted in groups of n multiples size, or 2_1 program
    //cout<< "blockLength: "<< inputLength<<endl;

    std::ostringstream oss; //PURPOSE???? forgot lol, not needed purpose is written in exc 2
    string s;//not needed
    char c;//not needed





    char strOther[256]; //specify name of keyfile
    int inputLengthP2;
    vector<int> keyVec;//  for file vecVVVVVVVIMPORTANT IMPORTANT letter were prob not seperated by space so make a vec type char to read in strings without spaces///////////////////////////////////////
    vector<string> fileVec;//store file elements to shift around
  //std::vector<std::vector<int>> matrix;


    std::cout << "Enter the name of the key text file: "<<endl; //need for e or decrypt
    cin.ignore();//once again fixes silly get issue
    cin.get (strOther,256);    // get c-string
    cout<< "name of this file to be exec: "<< strOther <<endl;

    std::fstream fs(strOther, fstream::in | fstream::out);  //for actual key file


    string line; //SAME NAME AS BEFOREEEEEEEEE< SCOPE PROBS
    string lineFile;//retrieves file lines

    while ( getline (fs,line, ' ') )
    {   //convert 2 digit strings to int
        keyVec.push_back( atoi(line.c_str()) );

    }

    cout<<" KEY VEC ELEMENTS: " <<endl;
    for(int i=0; i<keyVec.size(); i++)//does size change dynamically??
      cout<< keyVec[i];

      cout<<endl;
  //i was testing letters seprated by spaces, likely not seperated by spaces, TEST TEST TEST TEST TEST this
      while ( getline (trs,lineFile, ' ') )//retrieve file elements
      {   //convert 2 digit strings to int
          fileVec.push_back( lineFile );//look at other example if broken
  //letters must be seperated by space?
      }

      if( (fileVec.size() % inputLength) != 0 ){
        cout<< "Sorry, keyfile must be a multiple of n bytes"<<endl;
        return 0;
      }
    //remove this? trying to delete new line char  for(int i = 0; i<fileVec.size(); i++)//remove "\n" from fileVec
      //{
        //if(fileVec[i] == "\n")//  myvector.erase (myvector.begin()+5);
          //fileVec.erase(fileVec.begin()+i);

      //}

      cout<<" FILE FILE VEC ELEMENTS: " <<endl;
      for(int i=0; i<fileVec.size(); i++)//does size change dynamically??
        cout<< " "<<fileVec[i];

      //vector<string> encryVec(fileVec.size()); //will have en order, NEEDS AN WHILE(IS.OPEN) TO READ NEW LINES
      vector<string> encryVec;
  //  while(encryVec.size() != fileVec.size())
  //{
  int j = 0;
  int ogFileVecSize = fileVec.size();
      for(int i = 0; i<= ogFileVecSize; i++){//fix i<= part!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        int position = keyVec[j];
        //encryVec.insert(encryVec.begin()+position-1, fileVec[i]);
        //encryVec[i] = fileVec[position]; // PROBLEM stores extra NW LINE and LEtter A
        encryVec.push_back(fileVec[position]);

        j++;
        if(j>inputLength){
          j=0;
          fileVec.erase(fileVec.begin(), fileVec.begin()+inputLength);

      }
  }

      cout<<" FILE FILE AFTER REORDER VEC ELEMENTS: " <<endl;
      for(int i=0; i<encryVec.size(); i++)//does size change dynamically??
       cout<< encryVec[i] << " ";

       cout<<endl;


                     ofstream outputFile("transpositionOutput.txt");//name of output for transposition function
                     //...
                     //outputFile << "writing to file";
                     for(int i=0; i<encryVec.size(); i++)//does size change dynamically??
                      outputFile<< encryVec[i] << " ";

  trs.close();
  fs.close();

return 0;
}


int main () { 

string taskString;
task1(taskString);//works without any conditions, stream ts

//cout<< "transposition"<<endl;
//string transpositionInput;//get an actual value,   input file must be multiple of n bytes, any type char value
//transpositionFunc(transpositionInput); //test: A B C D E F G H I J K L, key.txt----->out: transpositionOutput.txt , stream trs and fs

//cout<< "nybble sub"<<endl;
//string nybInput; //is this needed?,  inputFile must be hex values
//nybbleSub(nybInput);//test: 0 1 A B C D E F, KeyFile3_2P1.txt------->out: nybbleOutput.txt    ,stream is and ks



return 0;
}
