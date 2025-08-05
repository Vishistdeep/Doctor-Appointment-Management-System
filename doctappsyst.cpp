
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int bookAppointment()
{
    system("cls");
	
    cout<<"\n ----- Book Your Appointment ---- \n";	
    cout<<"\n ----- Availbale slots ---- \n";	 

    //check if record already exist..
    ifstream read;
    read.open("appointment.dat");
    
    int hoursbook = 8;
    
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
     
    if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	       
	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;  
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"\n Appointment Summary by hours:";
	char key = 'A';
	int hours = 9;
	for(int i = 0; i<=12; i++)
	{
	if(i == 0){
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
	}
	
	else
	{								           	
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"->"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
	}
	hours++; key++;
	}
            
	}
		
	read.close();
    }
	if(recordFound == 0){
	cout<<"\n Appointment Available for following hours :";
	char key = 'A';
	for(int i = 9; i<=21; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<" -> "<<i<<" - Available";
		key++;
	}
		
	}
   
   char choice;
   cout<<"\n\n Input your choice : ";
   cin>>choice;
   
   if( !(choice >= 'A' && choice <='Z'))
   {
	cout<<"\n Error : Invalid Selection";
	cout<<"\n Please selction correct value from menu A- Z";
	cout<<"\n Press any key to continue";
	getchar();getchar();
	system("cls");
	bookAppointment();
   }
   
   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0) 
      isBooked = 0;
      
   if(isBooked ==1)
   {
   	cout<<"\n Error : Appointment is already booked for this Hour";
   	cout<<"\n Please select different time !!";
   	cout<<"\n Press any key to continue!!";
   	getchar();getchar();
   	system("cls");
   	bookAppointment();
   }
   
   string name;
   string gender;
   int agge;
   int mobnum;
   cout<<"\n Enter your first name:";
   cin>>name;
   cout<<"\n Enter your age:";
   cin>>agge;
   cout<<"\n Enter your gender:";
   cin>>gender;
   cout<<"\n Enter your mobile number:"; 
   cin>>mobnum;

   ofstream out;
   out.open("appointment.dat", ios::app);
	
   if(out){
	   out<<choice<<":"<<name.c_str()<<"\n";
	   out.close();
	   cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
    }
    else
    {
    	cout<<"\n Error while saving booking";
    }

    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}

int existingAppointment()
{
    system("cls");
    cout<<"\n ----- Appointments Summary ---- \n";	
    //check if record already exist..
    ifstream read;
    read.open("appointment.dat");
    
    int hoursbook = 8;
    
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
     int recordFound =0; 
     
    if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	       
	   while(getline(read, line)) {
	   	   char temp = line[0];
	   	   int index = (temp - 65);
	   	   arr[index]=1;  
		   recordFound = 1;
	  }
        if(recordFound == 1)
        {
        cout<<"\n Appointment Summary by hours:";
        char key = 'A';
        int hours = 9;
        for(int i = 0; i<=12; i++)
        {
        	if(arr[i] == 0) 
        	cout<<"\n "<<key<<"->"<<hours<<" - Available";
        	else
        	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
        	hours++; key++;
        }
            
	}
		
	read.close();
    }
    else
    {
    char key = 'A';
	for(int i = 9; i<=21; i++)
	{
	if(i==9)
	cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
	else
	cout<<"\n "<<key<<" -> "<<i<<" - Available";
	key++;
	}
    }
    
    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;	 
}
int knowAbout()
{
    system("cls");
    cout<<"Doctor name::::: Dr.Z S Meharwal\n";
    cout<<"Cardiac Surgeon, New Delhi, India\n";
    cout<<"Director, 27 years of experience , , ,\n";
    cout<<"FORTIS ESCORTS HEART INSTITUTE, NEW DELHI\n";
    cout<<"****Highlights****\n";
    cout<<"-Dr. Z S Meharawal is one of the leading Cardiac Surgeons in India.\n";
    cout<<"-With an experience of over 27+ years, he is a part of the founding team of doctors at Fortis Escorts Heart Institute.\n";
    cout<<"-He has more than 20,000 cardiac surgeries to his credit.\n";
    cout<<"-He is amongst few cardiac surgeons performing heart transplantation and ventricular assist device implantation. \n";
    cout<<"-Dr. Meharawal has been invited to national and international meetings as faculty.\n";
    cout<<"-He has more than 40 publications in peer-reviewed journals to his credit.\n";
    cout<<"-Dr. Z S Meharawal is an active member of various eminent organizations like the Indian Association of Cardiovascular Thoracic Surgeons, Cardiological Society of India, International Society for Minimally Invasive Cardiac Surgery, and Asian Society of Cardiovascular Thoracic Surgery Society of Thoracic Surgeo\n";
    cout<<" \nPlease any key to continue..";
    getchar(); getchar();
    return 0;
}

;
int main(int argc, char** argv) {
	while(1)
	{
		system("cls");
		cout<<"\tDoctor Appointment System\n";
		cout<<"----------------------------------------\n\n";
		
		cout<<"1. Book Appointment\n";
		cout<<"2. Check Existing Appointment\n";
		cout<<"3. Know about your Doctor\n";
        cout<<"0. Exit\n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: bookAppointment(); break;
			case 2: existingAppointment(); break;
            case 3: knowAbout();break;
			case 0: 
		        while(1)
		        {
				 system("cls");
		        	cout<<"\n Are you sure, you want to exit? y | n \n";
		        	char ex;
		        	cin>>ex;
		        	if(ex == 'y' || ex == 'Y')
		        		exit(0);
		        	else if(ex == 'n' || ex == 'N')
                     		{
                     		 break;
                    		}
                     else{
                     	cout<<"\n Invalid choice !!!";
                     	getchar();
                     }
             	 }	break;
                 	 
            default: cout<<"\n Invalid choice. Enter again ";
                     getchar();
                 	
		}   		        

	}
	return 0;
} 