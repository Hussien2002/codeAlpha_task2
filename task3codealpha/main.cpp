#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void Regester();
void Login();
void resetpassword();
int main() {
    int c;
    cout<<"1-Regester\n2-Login\n";
    cin>>c;
    if(c==1)
    {
        Regester();
    }
   else
    {
        Login();
    }
    return 0;
}
void Regester()
{
    string usernam ,password;
    cout<<"Enter User name :";
    cin>>usernam;
    cout<<"Enter Password :";
    cin>>password;
    ofstream file;
    file.open("dataofuser.txt",ios::app);
    if(file.is_open())
    {
        file<<usernam<<"\t"<<password<<endl;
        file.close();
        cout<<"Registration successfully\n ";
    }

}
void Login()
{
    string username , password, storeduser ,storedpass;
    cout << "Enter user name: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
     ifstream file;  // Declare an input file stream
    file.open("dataofuser.txt");  // Open a file for reading
bool flag=false;
    while(file>>storeduser >>storedpass)
    {
        if(username==storeduser&&password==storedpass)
        {
            flag=true;
            break;
        }
    }
        if(flag)
        {
            cout<<"successful login\n";
        }
     else {
         string word;
            cout<<"is you want reset password enter reset password : ";
            cin>>word;
     if(word!="NO")
        {resetpassword();}
        else
        {
            cout << "You are not logged in\n";
        }
    }

}
void resetpassword()
{
    string username,password;
    cout << "Enter user name: ";
    cin >> username;
    vector<string> lines;  // To store the lines from the file
    string line;
     ifstream file;  // Declare an input file stream
    file.open("dataofuser.txt");  // Open a file for reading
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
bool flag =true;
       for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].find(username) != string::npos) {
            cout << "Enter the new password: ";
            cin >> password;

            // Update the line with the new password
            lines[i] = username + " " + password;
            flag=false;
            break;
        }
       }
        if(flag)
        {
           cout << "Username not found!\n";
        return;
        }
             // Step 3: Write the modified content back to the file
    ofstream outputFile("dataofuser.txt");
    for (const auto& modifiedLine : lines) {
        outputFile << modifiedLine << endl;
    }
    outputFile.close();

    cout << "Data has been updated!" << endl;

        }
