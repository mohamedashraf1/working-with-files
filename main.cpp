#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string data;
char nameOFfile[100];

void loadingFile();
void createFile();
void displayFile();
void countFile();
void searchFile ();
void emptyFile();
void Add ();
void Replacement();
void Upper_case();
void lowercase();
void append();
void cipherORdecipher();

int main()
{
    int choice;
    bool x=true;

    while(x){
    cout<<"welcome \n";
    cout<<"what do you like to do today?\n";
    cout<<"1-for loading an existing file\n";
    cout<<"2-create a new file\n";
    cout<<"3-display file content\n";
    cout<<"4-for count the word and the character in the file \n";
    cout<<"5-search for a word in the file \n";
    cout<<"6-empty file content \n";
    cout<<"7- Add more content to the end of the file \n";
    cout<<"8- Replace a word in the file with another word\n";
    cout<<"9- Turn all the content file to upper case\n";
    cout<<"10- Turn all the content file to lower case\n";
    cout<<"11- Add another file to the end of the current file \n";
    cout<<"12- Encrypt and decrypt the file \n";
    cout<<"13-end\n";
    cin>>choice;
    switch (choice) {
   case 13 :
        x=false;
        break;
       case 1 :
    loadingFile();
    break;

       case 2:
        createFile();
        break;
       case 3 :
        displayFile();
        break;
       case 4 :
        countFile();
        break;
       case 5 :
        searchFile ();
        break;
       case 6 :
        emptyFile();
        break;
       case 7 :
        Add();
        break;
       case 8 :
        Replacement();
        break;
       case 9 :
        Upper_case();
        break;
       case 10 :
        lowercase();
        break;
       case 11 :
        append();
        break;
       case 12 :
        cipherORdecipher();
        break;

    }
       }
return 0;
}

void loadingFile()
{
ifstream infile;
        cout<<"please enter the name of file"<<endl;
        cin>>nameOFfile;
        infile.open(nameOFfile);
        if(!infile.fail()&&!infile.eof()){
           cout<<"the file is loaded Successfully"<<endl;
           cout<<endl;
        }
        else if(infile.fail()){
            cout<<"the file is not opened \n";
            cout<<endl;
        }
        infile.close();




      }

void createFile(){

{
          char inputTheName[100];
          cout<<"enter the name of the file you want to create"<<endl;
          cin>>inputTheName;
          ofstream nameOfNewFile;
          nameOfNewFile.open(inputTheName);
          cout<<"the file is created Successfully"<<endl;
          cout<<endl;
          nameOfNewFile.close();
      }

}
void displayFile() {

ifstream infile;
        infile.open(nameOFfile);
        if(!infile.fail()&&!infile.eof()){
           while( infile>>data){
            cout<<data<<" ";

           }

           cout<<"\n";
                }
        else if(infile.fail()){
            cout<<"the file is not exist \n";
            cout<<endl;
        }
        infile.close();
       }
void countFile()
{
    ifstream infile;
        infile.open(nameOFfile);
        if(!infile.fail()&&!infile.eof()){
           int i=0,sum=0;
           for (i;infile>>data;i++){
                sum+=data.size();

           }

           cout<<"the number of words in this file = "<<i<<endl;
           cout<<"the number of character in this file = "<<sum<<endl;
           cout<<endl;

        }
        else if(infile.fail()){
            cout<<"the file is not opened \n";
            cout<<endl;
        }
        infile.close();

}
void searchFile ()
{
    ifstream infile;
        infile.open(nameOFfile);
        if(!infile.fail()&&!infile.eof()){
          string word;
          int y=0;
          cout<<"enter the word that you want to search about \n";
          cin>>word;
          for (int j=0;j<=word.size();j++)
          {
              if (word[j]<97){
                word[j]+=32;
              }
          }
          while (infile>>data)
          {


            if (data==word){
                cout<<"word is found in the file \n";
                cout<<endl;
                y=1;
              }

                      }
              if (y==0){
                cout<<"word is not found in the file \n";
                cout<<endl;
              }

        }

        else if(infile.fail()){
            cout<<"the file is not opened \n";
        }
        infile.close();
}
void emptyFile()
{


    fstream infile;
        infile.open(nameOFfile, ios::out);
        if(!infile.fail()&&!infile.eof()){
           cout<<"the file is now empty"<<endl;
           cout<<endl;
        }
        else if(infile.fail()){
            cout<<"the file is not opened \n";
            cout<<endl;
        }
        infile.close();


}
void lowercase()
{


     vector<string> word;
    fstream dataFile;
    //char filename[80];
    //cout<<"enter file name"<<endl;
    //cin>>filename;
    dataFile.open(nameOFfile);
    string name;
    while (!dataFile.fail() && !dataFile.eof())
    {
        while (dataFile >> name)
        {
                word.push_back(name);
        }
    }
    for (int i=0 ; i<word.size() ; i++)
    {
        for(int j=0 ; j<word[i].size() ; j++)
        {
            if(word[i][j]<97)
                word[i][j]+=32;
        }
    }
    dataFile.close();
    dataFile.open(nameOFfile , ios::out);
    for(int i=0 ; i<word.size() ; i++)
    {
            dataFile << word[i];
            dataFile << " ";
    }
    dataFile.close();
}
void append()
{
      //char nameOFfile[80];
     //cout<<"enter file name \n";
    //cin>>nameOFfile;
    string name;
    vector<string>word;


    fstream datafile;
    datafile.open(nameOFfile);
    while(datafile.is_open()&&!datafile.eof()){
            while(datafile>>name){
                    word.push_back(name);

            }

    }
    datafile.close();
    fstream file;
    char file_name[80];
    cout<<"enter file name that you want to append the data to it\n";
    cin>>file_name;

    file.open(file_name,ios::out|ios::app);
    file<<" ";

    for(int i=0 ; i<word.size() ; i++)
    {

            file << word[i];


            file << " ";

    }





    file.close();

}
void cipherORdecipher(){
     vector<string> word;
    fstream dataFile;
    //char filename[80];
    //cout<<"enter file name"<<endl;
    //cin>>filename;
    dataFile.open(nameOFfile);
    string name;
    while (!dataFile.fail() && !dataFile.eof())
    {

        while (dataFile >> name)
        {

                word.push_back(name);
        }


    cout<<"1- Cipher a message"<<endl;
    cout<<"2- Decipher a message"<<endl;

    int choice;

   cin>> choice;
   // string name;



    for(int i=0; i<word.size(); i++)
    {
        for(int j=0;j<name.size();j++){
        if (word[i][j]>=97)
        {
            word[i][j]-=32;
        }
    }
    }
    for(int i=0 ; i<word.size() ; i++)
    {
        for(int j=0;j<name.size();j++){
        if (int(word[i][j])>77)
        {
            word[i][j]=char(word[i][j]-13);
        }
        else if (char(word[i][j])<78)
        {
            word[i][j]=char(word[i][j]+13);
        }
        else if (word[i][j]==char(32))
        {
            cout<<" ";
        }
    }
    }

    }


    dataFile.close();
    dataFile.open(nameOFfile , ios::out);
      for(int i=0 ; i<word.size() ; i++)
    {
            dataFile << word[i];
            dataFile << " ";
    }
    dataFile.close();
}
void Add ()
{
    ofstream dataFile;
    string name;
    dataFile.open(nameOFfile,ios::app);
    if (dataFile.fail())
    {
        cout<<" failed to open the file.\n";
    }
    else
    {
        cout<<"enter the file content you want to add : "<<endl;
        cout<<"if you have finished press 1 to exit\n";
        while ( cin >> name)
        {
            if(name=="1")
            {
                break;
            }
            dataFile << " ";
            dataFile << name;
        }
        cout<<" closing the file.\n";
        dataFile.close();
    }

}
void Replacement ()
{
    fstream dataFile;
    string name , word , new_word;
    vector<string> test;
    dataFile.open(nameOFfile);
    if(dataFile.fail())
    {
        cout<<"failed to open the file.\n";
    }
    else
    {
        cout<<"File is opened.\n";
        cout<<"Please enter the existing word : ";
        cin>>word;
        cout<<"Please enter the new word : ";
        cin >> new_word;
        while (!dataFile.fail() && !dataFile.eof())
        {
            dataFile >> name;
            test.push_back(name);
        }
        dataFile.close();
        dataFile.open(nameOFfile,ios::out);
        for(int i=0 ; i<test.size() ; i++)
        {
            if (test[i]==word)
                test[i]=new_word;
        }
        for(int i=0 ; i<test.size()-1 ; i++)
        {
            dataFile << test[i];
            dataFile << " ";
        }
        cout<<" closing the file.\n";
        dataFile.close();
        cout<<"finished.\n";
    }

}
void Upper_case ()
{
    fstream dataFile;
    string name;
    vector<string> test;
    dataFile.open(nameOFfile);
    if(dataFile.fail())
    {
        cout<<"failed to open the file.\n";
    }
    else
    {
        cout<<"File opened.\n"<<"turning all the content file to upper case.\n";
        while (!dataFile.fail() && !dataFile.eof())
        {
            dataFile >> name;
            test.push_back(name);
        }
        dataFile.close();
        dataFile.open(nameOFfile,ios::out);
        for(int i=0 ; i<test.size() ; i++)
        {
            for(int j=0 ; j<test[i].size() ; j++)
            {
                if(test[i][j]>=97)
                    test[i][j]-=32;
            }
        }
        for(int i=0 ; i<test.size()-1 ; i++)
        {
            dataFile << " ";
            dataFile << test[i];
        }
        cout<<" closing the file.\n";
        dataFile.close();
        cout<<"finished.\n";
    }
}
