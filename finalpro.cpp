#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<cstdlib>
#define shopdetails sd
using namespace std;
//CUSTOMER PART
class Customer
{

public:
	char name[20],address[20],contact[20],typeofshop[20];
	int floorno;
	
	 public:
	 	int shop_no;
	
clogin()
    {
    	system("cls");
    string path = "d:\\mypro\\mall manager\\";
    string searchPattern = "*.dat";
    string fullSearchPath = path + searchPattern;
 
    WIN32_FIND_DATA FindData;
    HANDLE hFind;
 
    hFind = FindFirstFile( fullSearchPath.c_str(), &FindData );
 
    if( hFind == INVALID_HANDLE_VALUE )
    {
        cout << "Error searching directory\n";
        return -1;
    }
 
    do
    {
        string filePath = path + FindData.cFileName;
        ifstream in( filePath.c_str() );
        cout<<"\n\n TODAYS OFFER PAGE-WELCOME TO E3 MALL \n\n";
        if( in )
        {
        	char c[100];
        		
            do
            {
            	in>>c;
            	cout<<c<<" ";
			}while(in.eof()==0);
		
			
			cout<<"\n\n\n";
			cout<<"**************************************************************************** \n";
        }
        else
        {
            cout << "Problem opening file " << FindData.cFileName << "\n";
        }
    }
    while( FindNextFile(hFind, &FindData) > 0 );
 
    if( GetLastError() != ERROR_NO_MORE_FILES )
    {
        cout << "Something went wrong during searching\n";
    }
 
    system("pause");
    return 0;
}



	
	
//to view the shops
	

	
}cs;


void viewShop()
	{
		system("cls");
	    cout<<"\t\t\t   HELLO WELCOME \n";
		cout<<"\t\t\t   -----  ------   ";  
	FILE *sd1;
	

	if ((sd1=fopen("D:/mypro/shopdetails/sdt.txt","r"))==NULL)
	{
		cout<<"File is empty";
	}
	else
	{
		
while (fread(&cs, sizeof(cs), 1, sd1))
{

			      
        std::cout<<"\n\n\t\t\t Shop number  : \t"<<cs.shop_no;
		cout<<"\n\n Shop name        :\t"<<cs.name;
		cout<<"\n Type of the shop :\t "<<cs.typeofshop;
		cout<<"\n Owner's address  :\t "<<cs.address;
		cout<<"\n Owner's contactno:\t "<<cs.contact;
		cout<<"\n Floor no         :\t "<<cs.floorno;

	
	
	
		}

	fclose(sd1);
	
	}
}

customer()
{
	
	int ans;
	char opt;
	do
	{
	system("cls");
	cout<<"\n\t\t  ........E3 MALL WELCOMES YOU..........  \n";
	cout<<"\n \t\t ........Customer Page............ \n";
	cout<<"\n\n \t 1.View Shops Available in the Mall";
    cout<<"\n   \t 2.View Today's Offer:";
    
    cout<<"\n   \t 3.Exit: ";
    cout<<"\n Enter your option:";
    cin>>ans;
    
    switch(ans)
    {
    	case 1:viewShop();
    	       break;
        case 2:cs.clogin();
               break;
        
        case 3:exit(0);
               break;
        default:cout<<"Enter the values between [1-3]";
               break;
	}
	cout<<"\n Do you wish to continue at CUSTOMERS PAGE";
	cin>>opt;
}while(opt=='y'||opt=='Y');

}

//SHOP OWNER PART
 
class Shopowner
{
public:
     	string shopname;
		string spassword;
		string inputshopname;
		string inputPassword;
char sfname[10];
char fname[10];

void shopRegisterDo()
    {
    char c;
    
    ofstream out;
    out.open(fname);
	if (!out.is_open())
	{
	out.open(fname);
	}
    out << shopname << " " << spassword << endl;
    out.close();
	}



void shopRegister()
  {
  cout << "Welcome!\n-------------------------\n\nPlease register.\nEnter a new Username:\n";
  cin >> shopname;
  cout << "\nPlease enter a new password:\n";
  cin >> spassword;
  shopRegisterDo();
  }

void slogin()
{
	
    cout << "Please enter your username:\n";
	cin >> inputshopname;
	cout << "\nPlease enter your password:\n";
    cin >> inputPassword;
	string suserAndPass = inputshopname + " " + inputPassword; // Search pattern
	int offset;
	string line;
	ifstream usersFile;
	usersFile.open (sfname);
	if(usersFile.is_open())
        {
        bool found = false;
        if(usersFile.is_open()) 
	    {
        while(getline(usersFile,line) && !found) 
		{
		if (line.compare(suserAndPass) == 0) 
		{ //match strings exactly!
		found = true; // found is true => break loop
		}
		}
        usersFile.close(); //close the file before recursivly opening it again later
        }
	    if(found)
		{
	        cout << "Welcome "<< inputshopname << '\n';
	    }
	    else 
		{
	        cout << "\nUsername and/or password incorrect!\n\n\n\n";
        slogin(); //ok we didn't find them, lets redue this!
	}
    }		
	}
	}so;


void addoffer()
{
 char c,fname[10];
              system("cls");
              ofstream out;
              cout<<"Create A File To Store Your Offerr [as .dat] format:";
              cin>>fname;
              out.open(fname);
              cout<<"Enter contents to store in file (Enter # at end):\n";
              while((c=getchar())!='#')
              {
                out<<c;
              }
              out.close();
	
 }


void viewoffer()
{
	system("cls");
	ifstream ifile;
	char s[100], fname[20];
	cout<<"Enter the offer file name(like file.dat) : ";
	cin>>fname;
	ifile.open(fname);
	if(!ifile)
	{
		cout<<"Error in opening file..!!";
		getch();
		exit(0);
	}
	while(ifile.eof()==0)
    {
        ifile>>s;
        cout<<s<<" ";
    }
	cout<<"\n";
	ifile.close();
	getch();
}



void deleteoffer()
{
	system("cls");
	int status;
	char fname[20];
	cout<<"\n Enter the offer file name (like file.dat) you want to delete : ";
	cin>>fname;
	status=remove(fname);
	if(status==0)
	{
		cout<<"file "<<fname<<" deleted successfully..!!\n";
	}
	else
	{
		cout<<"Unable to delete file "<<fname<<"\n";
		perror("Error Message ");
	}

}

void shopowner()
{
char ans;
    do
    {
    system("cls");	
	
	int opt;
	cout<<"\n\t\n   WELCOME TO E3 WORLD   ";
	cout<<"\n\n\n \t\t CATEGORIES";
	cout<<"\n\t\t 1.Add a offer";
	cout<<"\n\t\t 2.view the offer";
	cout<<"\n\t\t 3.Delete the offer";
    cout<<"\n Select the option:";
    cin>>opt;
    
    switch(opt)
	{
		    case 1: addoffer();
		       break;
			case 2: viewoffer();
		       break;
	        case 3: deleteoffer();
			   break;
	    	   default:
			   	cout<<"enter option between [1-3]";
		}
		cout<<"\n Do you wish to continue at OFFERS PAGE:";
		cin>>ans;
	
}while(ans=='y'||ans=='Y');

}

void shoplogin()
{
system("cls");	
	ifstream ifile;
	cout<<"Enter your shop name in .txt format: ";
	cout<<"\n";
	cin>>so.sfname;
	ifile.open(so.sfname);
	if(!ifile)
	{
		cout<<"\n";
		cout<<"Sorry no such shop is available in our E3 Mall:";
		getch();
		exit(0);
	}
	else
	
	so.slogin();
	shopowner();
}

//MALL MANAGER PART


class Shop
{ 

   public:
	char name[20],address[20],contact[20],typeofshop[20];
	int floorno;
	
	 public:
	 	int shop_no;
	
	  static int count()
	  {
	  	static unsigned int shopno=0;
	  	shopno++;
	  	//std::cout<<shopno;
	  	return shopno;
	  }
}s;

int avail(int sno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("D:/mypro/shopdetails/sdt.txt","r");
 while (!feof(fp))
 {
  fread(&s, sizeof(s), 1, fp);

  if (sno == s.shop_no)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
	




	    
//For adding the shops

//int Shop::shopno=0; 
	void addShop()
	{
    
		FILE *sd;
     if ((sd=fopen("D:/mypro/shopdetails/sdt.txt","a+"))==NULL)
	{
		cout<<"file is empty";
	}
	else
{
 s.shop_no=s.count();
 std::cout<<"\n The shop no is :"<<s.shop_no;
 cout<<"\n\n kindly fill this details first before you login ";
  cout<<"\n Enter your shop name as .txt format:";
    cin>>so.fname;
 so.shopRegister();
 cout<<"Enter the shop name      :";
 cin>>s.name;
 fflush(stdin);
 cout<<"Enter the type of shop   :";
 cin>>s.typeofshop;
 fflush(stdin);
 cout<<"Enter the owner's address   :";
 cin>>s.address;
 fflush(stdin); 
  cout<<"Enter the owner's phoneno   :";
 cin>>s.contact;
 fflush(stdin);
 cout<<"Enter the floor no :";
 cin>>s.floorno;
 fflush(stdin);
 fwrite(&s,sizeof(s),1,sd); 
 fclose(sd);
}	
}

//For Viewing the shops	
	void viewShop1()
	{
		system("cls");
	    cout<<"\t\t\t   HELLO WELCOME \n";
		cout<<"\t\t\t   -----  ------   ";  
	FILE *sd1;
	

	if ((sd1=fopen("D:/mypro/shopdetails/sdt.txt","r"))==NULL)
	{
		cout<<"File is empty";
			}
	else
	{
		
while (fread(&s, sizeof(s), 1, sd1))
{

			      
        std::cout<<"\n\n\t\t\t Shop number  : \t"<<s.shop_no;
		cout<<"\n\n Shop name        :\t"<<s.name;
		cout<<"\n Type of the shop :\t "<<s.typeofshop;
		cout<<"\n Owner's address  :\t "<<s.address;
		cout<<"\n Owner's contactno:\t "<<s.contact;
		cout<<"\n Floor no         :\t "<<s.floorno;

	
	
	
		}

	fclose(sd1);
	
	}
}
//For Searching A Particular shop
void searchShop()
{
	int avl;
 FILE *sd2;
 int shopno,temp;
 cout<<"\n Enter the Shop no you want to search;";
 cin>>shopno;
 avl=avail(shopno);
 if (avl== 0)
  cout<<"Shop no"<<shopno<<"is not available in mall";
 else
 {
 	 sd2=fopen("D:/mypro/shopdetails/sdt.txt","r");


  while (fread(&s, sizeof(s), 1, sd2))
  {
   temp= s.shop_no;
   if (shopno == temp)
   {
   	 cout<<"\n\n\t\t\t Shop number  : \t"<<s.shop_no;
		cout<<"\n\n Shop name        :\t"<<s.name;
		cout<<"\n Type of the shop :\t "<<s.typeofshop;
		cout<<"\n Owner's address  :\t "<<s.address;
		cout<<"\n Owner's contactno:\t "<<s.contact;
		cout<<"\n Floor no         :\t "<<s.floorno;

    
   }
  }
  fclose(sd2);
 }
}
//delete the record.

void deleteShop()

{
	
 FILE *sd3;
 FILE *sd4;
 int avl;
 int shopno, s1;
 
 cout<<"Enter the Shop no you want to delete :";
 cin>>shopno;
 avl=avail(shopno);
 if (avl == 0)
  cout<<"shop is not available in the file ";
 else
 {
  sd3 = fopen("D:/mypro/shopdetails/sdt.txt","r");
  sd4 = fopen("D:/mypro/shopdetails/tempfile.txt", "w");
  while (fread(&s, sizeof(s), 1,sd3))
  {
   s1 = s.shop_no;
   if (s1 != shopno)
    fwrite(&s, sizeof(s), 1, sd4);
  }
  fclose(sd3);
  fclose(sd4);
  sd3 = fopen("D:/mypro/shopdetails/sdt.txt", "w");
  sd4 = fopen("D:/mypro/shopdetails/tempfile.txt", "r");
  while (fread(&s, sizeof(s), 1,sd4))
   fwrite(&s, sizeof(s), 1,sd3);
  printf("\nRECORD DELETED\n");
  fclose(sd3);
  fclose(sd4);
 }

}




//to update a file

void updateShop()
{
 int avl;
 FILE *sdo;
 FILE *sdt;
 int s2,shopno, ch;
 cout<<"\nEnter shop number to update:";
 cin>>shopno;
 avl=avail(shopno);
 if (avl == 0)
 {
  cout<<"\nShop is not Available in the file";
 }
 else
 {
  sdo = fopen("d:/mypro/shopdetails/sdt.txt", "r");
  sdt = fopen("d:/mypro/shopdetails/tempfile.txt", "w");
  while (fread(&s, sizeof(s), 1, sdo))
  {
   s2 = s.shop_no;
   if (s2 != shopno)
    fwrite(&s, sizeof(s), 1, sdt);
   else
   {
    cout<<"\n\t1. Update Name of Shop Name"; 
    cout<<"\n\t2. Update The Type Of The Shop";
    cout<<"\n\t3. Update The address of the shop";
    cout<<"\n\t4. Update The contact of the shop";
	cout<<"\n\t5. Update The floorno of the shop";	
    cout<<"\n\t6. Update The whole shop details";
    cout<<"\nEnter your choice:";
    cin>>ch;
    switch (ch)
    {
    case 1:
     cout<<"Enter Shop Name:";
     cin>>s.name;
     break;
    case 2:
     printf("Enter type of shop : ");
     cin>>s.typeofshop;
     break;
    case 3:
     cout<<"Enter Address of the shop owner:";
     cin>>s.address;
     break;
    case 4:
     cout<<"Enter contact number:";
     cin>>s.contact;
     break;
    case 5:
     cout<<"Enter Floor number:";
     cin>>s.floorno;
     break;
    
	
	
	
	
	case 6:
    
     cout<<"Enter Shop Name:";
     cin>>s.name;
    
     cout<<"Enter type of shop : ";
     cin>>s.typeofshop;
    
     cout<<"Enter Address of the shop owner:";
     cin>>s.address;
     cout<<"Enter contact number:";
     cin>>s.contact;
   
     cout<<"Enter Floor number:";
     cin>>s.floorno;
     break;
    
	
	default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&s, sizeof(s), 1,sdt);
   }
  }
  fclose(sdo);
  fclose(sdt);
  sdo = fopen("D:/mypro/shopdetails/sdt.txt", "w");
  sdt = fopen("D:/mypro/shopdetails/tempfile.txt", "r");
  while (fread(&s, sizeof(s), 1, sdt))
  {
   fwrite(&s, sizeof(s), 1,sdo);
  }
  fclose(sdo);
  fclose(sdt);
  printf("\n RECORD UPDATED");
 }
}




void mandisplay()
{
	int opt;
	char ans;
	do
	{
	system("cls");

	cout<<"\n\t\n   WELCOME TO E3 WORLD   ";
	cout<<"\n\n\n \t\t CATEGORIES";
	cout<<"\n\t\t 1.View the shops";
	cout<<"\n\t\t 2.Add a new shop";
    cout<<"\n\t\t 3.Search a shop";
    cout<<"\n\t\t 4.Delete a shop";
    cout<<"\n\t\t 5.Update the shop detail:";
	cout<<"\n\t\t 6.Exit";
	cout<<"\n\n Pless select your option..";
	cin>>opt;
	switch(opt)
	{
		    case 1: viewShop1();
		            break;
			case 2: addShop();
		            break;
	        case 3: searchShop();
			
		            break;
      		case 4:deleteShop();
			        break;
			case 5:updateShop();
			        break;
		
			case 6:exit(0);
			        break;
			
			default:
			cout<<"\n Press any value between [1-6]";
	}

cout<<"\n\n Do you wish continue at MALL MANAGER :(y/n)";
cin>>ans;
}while(ans=='y'||ans=='y');

}
	
	
	





class User 
{
 
        public:

	    string username;

	    string password;

	    string inputUsername;

	    string inputPassword;
        
        string oldUser;
        string oldPass;
        string olduserAndPass;
	     
	    
	    

	    // User registration
void userRegisterDo()

{

	ofstream usersFile ("D:/mypro/shopdetails/userData.txt");
	
	        if (!usersFile.is_open())

	        {

	            usersFile.open("D:/mypro/shopdetails/userData.txt");

	        }

	 

	            usersFile << username << " " << password << endl;

	 

	            usersFile.close();

	    }

	 

	    // Initialize user registration
void userRegister()

   {
         FILE *sd1;
         
         	if ((sd1=fopen("D:/mypro/shopdetails/userData.txt","r"))!=NULL)
	{
		cout<<"Enter your old user name:";
		cin>>oldUser;
		cout<<"Enter the old password:";
		cin>>oldPass;
		string olduserAndPass = oldUser + " " + oldPass; // Search pattern

		int offset;

	        string line;
	        ifstream usersFile;

            usersFile.open ("D:/mypro/shopdetails/userData.txt");

	        if(usersFile.is_open())

	        {

            bool found = false;

        	if(usersFile.is_open()) 
	        {

	        while(getline(usersFile,line) && !found) 
		    {

	        if (line.compare(olduserAndPass) == 0) 
			{ //match strings exactly!

	            found = true; // found is true => break loop

	        }

        }

	    usersFile.close(); //close the file before recursivly opening it again later
       } 
	    if(found)
		 {

	        cout <<"Change your new password and username:"<<"\n" ;	        
	        cout << "Welcome!\n-------------------------\n\nPlease register.\nEnter a new username:\n";

	     cin >> username;

	     cout << "\n Please enter a new password:\n";

	     cin >> password;

	     userRegisterDo();
	    cout<<"\nRegistered successfully";
    }
    
}
else
{

	cout<<"\n incorrect";
	getch();
}
}
    else 
	{
	      
         
         
	     cout << "Welcome!\n-------------------------\n\nPlease register.\nEnter a new username:\n";

	     cin >> username;

	     cout << "\nPlease enter a new password:\n";

	     cin >> password;

	     userRegisterDo();

    }
}
		
		void login()

	    {

	        cout << "Please enter your username:\n";

	        cin >> inputUsername;

	        cout << "\nPlease enter your password:\n";

	        cin >> inputPassword;
	        
			string userAndPass = inputUsername + " " + inputPassword; // Search pattern

	        int offset;

	        string line;
	        
			ifstream usersFile;

            usersFile.open ("D:/mypro/shopdetails/userData.txt");

	        if(usersFile.is_open())

	        {

            bool found = false;

        	if(usersFile.is_open()) 
	        {

	        while(getline(usersFile,line) && !found) 
		    {

	        if (line.compare(userAndPass) == 0) 
			
			{ //match strings exactly!

	            found = true; // found is true => break loop

	        }

        }

	    usersFile.close(); //close the file before recursivly opening it again later
        }
	    if(found)
		 {

	        cout << "Welcome "<< inputUsername << '\n';
	        
	           mandisplay();
    }
    else 
	{
	        cout << "\nUsername and/or password incorrect!\n\n\n\n";

	        login(); //ok we didn't find them, lets redue this!
	  }
}
  }
}user1;



void mallManager()
{
    char ans;
	int opt;
	do
	{
	system("cls");
	cout<<"\n\t\t  ........E3 MALL WELCOMES YOU..........  \n";
	cout<<"\n\n\t\t 1.New Manager \t\t";
	cout<<"\n\n\t\t 2.Existing user \t\t";
    cout<<"\n\n\t\t 3.Exit \t\t";
	cin>>opt;
	switch(opt)
	{
		    case 1:
			       user1.userRegister();
		           break;
			
			case 2:
			       user1.login();
		           break;
	        
			case 3: exit(0);
			       
			       break;
			       
			
			default:
			       cout<<"\n\n  Press any value between [1-3]";
	}

cout<<"\n \n Do you wish to continue at MALL MANAGER LOGIN";
cin>>ans;
}while(ans=='y'||ans=='y');
}






//introduction in main
void intro()
{
cout<<"\n\t\t  ........SPENCER MALL WELCOMES YOU..........  \n";
cout<<"\n\n \t Spencer Plaza is a shopping mall located on Anna Salai in Chennai, Tamil Nadu, India, ";
cout<<"\n is one of the modern landmarks of the city. Originally built during the period of the British Raj and";
cout<<"\n reconstructed in 1985 on the site of the original Spencer's departmental store, it is the oldest shopping mall in India";
cout<<"\n one of the biggest shopping malls in South Asia when it was built.It is one of the earliest Grade A commercial projects of the city,";
cout<<"\n which were developed in the second half of the 1990s As of March 2010, it is the 11th largest mall in the country with a gross lettable area of 530,000 sq ft. \n";
cout<<"\n \n \t\t\t AMENTITES \n";
cout<<"\t\t\t --------- \n";
cout<<"\n \t 1.Accesisble Parking \n\t 2.ATM \n\t 3.Baby changing station \n\t 4.Enhanced Cellular Connectivity \n\t 5.Lost And Found \n\t 6.Mobile Device Charging stations \n\t 7.Parking \n\t 8.Train Ride \n\t 9.Wheel chairs \n\t 10.Wireless (Wi-Fi) Internet";
cout<<"\n\t\t\t press any key to continue..";
getch();
}


//MAIN FUNCTION
int main()
{
	int ch;
	char ans;
    intro();
    

   do
   {
   system("cls");
   cout<<"\n\t\t  ........E3 MALL WELCOMES YOU..........  \n";

   cout<<"\n \t\t\t 1.Customer";
   cout<<"\n \t\t\t 2.Shopowner";
   cout<<"\n \t\t\t 3.Mall Manager";
   cout<<"\n \t\t\t 4.Exit";
   
   cout<<"\n\n please select the type of the user :";
   cin>>ch;

switch(ch)
{
		    case 1: customer();
		    break;
			case 2: shoplogin();
		    break;
	        case 3: mallManager();
		    break;
			case 4:exit(0);
			break;

		default:
	cout<<"\n\n  Press any value between [1-4]";
}
cout<<"Do you wish to continue at HOME PAGE:";
cin>>ans;
}while(ans=='y'||ans=='Y');

return 0;
getch();		

}
