#include<iostream> 
#include<iomanip> 
#include<cstring> 
#include<algorithm> 
#include<cstdlib>
#include<cctype>
#include<string>
using namespace std; 
#include<conio.h> 
#include<windows.h>
#include<fstream>
#include<cmath>
#include<sstream>
#include<stdio.h>

// For Resizing Terminal Window
HWND WINAPI GetConsoleWindowNT(void){
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
    ,TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}
// ---------------------------

// functions
void carCompare();
void payment(int num, int pickUp, int dropOff, int xdays);
void receipt(int paymentMethod, int i, int pUp, int dOff, int xtotal);


// variables
int pickUpChoice, dropOffChoice;

int	const arrSize = 6;
int dynSize = 10;

int selectedCar; // car selection
int days; // car selection

// struct for specs

struct specs{
	string carName[arrSize] = {"Hyundai Santa Fe 2021","Hyundai Tucson 2021","Hyundai Bayon","Nissan Juke F16","Toyota Corolla E210 Hatchback","Toyota Yaris 2017"};
	double price[arrSize] = {1700, 2150, 1900, 2500, 2600, 2455};
	string engine[arrSize] = {"DOHC 16-valve inline-4, aluminum block and head, direct fuel injection", "DOHC 16-valve inline-4, aluminum block and head, direct fuel injection", "1.0 T-GDi (100 Hp)", "Inline 3", "Inline 4", "1.5L L4 DOHC 16-valve"};
	string suspension[arrSize] = {"Struts/Multilink", "Electronic Controlled Suspension", "Independent type McPherson/Torsion", "Independent type McPherson/Semi Independent", "Independent type McPherson/Multilink", "Independent suspension/Rear torsion beam suspension"};
	string powertrain[arrSize] = {"turbocharged and intercooled DOHC 16-valve 1.6-liter inline-4", "Internal Combustion engine", "Internal Combustion engine", "JUKE hybrid powertrain", "Power-split (hybrid)", "Power-split (hybrid)"};
	string transmission[arrSize] = {"8-speed automatic", "6-speed automatic with manual shifting mode", "6-speed manual", "6-speed manual", "1-speed Auto CVT", "5-speed manual"};
};

// struct for user registration

struct {
	string name;
	int age;
	string address;
	
} userInfo;

// universal variables
string *pName = &userInfo.name;
int *pAge = &userInfo.age;
string *pAddress = &userInfo.address;
//

string pickUp[] = {"1191 Pablo Ocampo Sr. Ext, Makati City", "1229 Legaspi Street, Legaspi Village, Makati City", "Padre Burgos Avenue, Manila City"};
string dropOff[] = {"Two Serendra, 11th Avenue, Fort Bonifacio, Global City, Taguig City", "7th St. Bonifacio Global, Taguig City", "Ayala Ave, Makati City"};


int main(){
	// resizing terminal window
	HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,0,0,1500,600,TRUE);
	// ---------------------- //
	
	char ans;
	bool verif=true;
	char retry;
	do{
	cout << "Welcome to The Cartel!" << endl;
	cout << "Press enter to begin transaction . . ." << endl;
	cin.ignore(); 
	system("cls");

	
	//pick-up and drop-off
	cout << "                                   ***** PICK-UP AND DROP-OFF *****" << endl << endl;
	
	cout << left << setw(60) << "                     Pick-up" << "                      Drop-off" << endl << endl
		<< "[1]" << setw(60) << pickUp[0] << "[1]" << setw(60) << dropOff[0] << endl
		<< "[2]" << setw(60) << pickUp[1] << "[2]" << setw(60) << dropOff[1] << endl
		<< "[3]" << setw(60) << pickUp[2] << "[3]" << setw(60) << dropOff[2] << endl << endl;
	
	while(verif)
	{
	cout << "Choose a pick-up point (number only): ";
	cin >> pickUpChoice;
		try{
			if(pickUpChoice<1||pickUpChoice>3)
				throw pickUpChoice;
			verif=false;
		}
		catch(int xchoice){
			cout<<"Please enter a valid input..."<<endl;
			continue;
		}
	}
	verif=true;
	while(verif)
	{
	cout << "Choose a drop-off point (number only): ";
	cin >> dropOffChoice;
		try{
			if(dropOffChoice<1||dropOffChoice>3)
				throw dropOffChoice;
			verif=false;
		}
		catch(int xchoice){
			cout<<"Please enter a valid input..."<<endl;
			continue;
		}
	}
	
	
	system("cls");
	
	// displaying specs
	
	specs specss[arrSize];
	
	bool boolAns = true;
	
	while(boolAns == true){
//		int switcher = 1;
		char userIn;
		int i;
		
		for(i = 0; i < 6; i++){
		
		system("cls");
			//display first car
		cout <<specss[i].carName[i] << endl << endl
			<< "Price: Php" << specss[i].price[i] << " /day" << endl
			<< "Engine: " << specss[i].engine[i] << endl
			<< "Suspension: " << specss[i].suspension[i] << endl
			<< "Powertrain: " << specss[i].powertrain[i] << endl
			<< "Transmission: " << specss[i].transmission[i] << endl << endl;
		
		// options
		verif=true;
		while(verif)
		{
			cout << "Input 'c' to compare cars..." << endl
				<< "Show next car?[y/n] ";
			cin >> userIn;
			try{
				if(tolower(userIn)!='y'&&tolower(userIn)!='n'&&tolower(userIn)!='c')
					throw userIn;
				verif=false;
			}
			catch(char xchoice){
				cout<<"Please enter a valid input..."<<endl;
				continue;
			}
		}
		
		if(userIn == 'y'){
			continue;
		}
			
		else if(userIn == 'n')
			break;
			
		else if(userIn == 'c'){
//			create compare function
			cout << endl;
			carCompare();
		}
			
		else{
			cout << "Please enter a valid character." << endl;
			system("pause");
			continue;
			}
		
	} // for-loop
	
	if(userIn == 'n')
		break;
		
	}
	
	// car selection
	
	system("cls");
	cout << "SELECT A CAR" << endl << endl
		<< left << setw(30) << "[1]Hyundai Santa Fe 2021" << "[4]Nissan Juke F16" << endl
		<< setw(30) << "[2]Hyundai Tucson 2021" << "[5]Toyota Corolla E210 Hatchback" << endl
		<< setw(30) << "[3]Hyundai Bayon" << "[6]Toyota Yaris 2017" << endl << endl;
	

	
	
	verif=true;
	while(verif)
		{
			cout << "Chosen Car (number only): ";
			cin >> selectedCar;
			try{
				if(selectedCar<1||selectedCar>6)
					throw selectedCar;
				verif=false;
			}
			catch(int xchoice){
				cout<<"Please enter a valid input..."<<endl;
				continue;
			}
		}
	selectedCar = selectedCar - 1;
	

	verif=true;
	while(verif)
		{
			cout << endl << "How many days would you like to rent? (1-31): ";
			cin >> days;
			try{
				if(days<1||days>31)
					throw days;
				verif=false;
			}
			catch(int xchoice){
				cout<<"Please enter a valid input..."<<endl;
				continue;
			}
		}

	// registration
	
	system("cls");
    cout << "REGISTRATION" << endl << endl;
    
    cout << "Enter your" << endl
    	 << "Full Name: ";
	cin.ignore();
	getline(cin, *pName);
	
	cout << "Age: ";
	cin >> *pAge;
	cin.ignore();
	
	cout << "Address: ";
	getline(cin, *pAddress);
    
    // payment
    payment(selectedCar, pickUpChoice, dropOffChoice, days);
	system("pause");
	system("cls");
	do{
	cout<<"Do you want perform another transaction?[y/n]"<<endl;
	cin>>retry;
	cin.ignore();
	system("cls");
	}while(tolower(retry)!='y'&&tolower(retry)!='n');
	}while(tolower(retry)=='y');
}

void carCompare(){
	int car1, car2;
	
	specs specss[arrSize];
	
	system("cls");
	cout << "CHOOSE TWO CARS TO COMPARE" << endl << endl
		<< left << setw(30) << "[1]Hyundai Santa Fe 2021" << "[4]Nissan Juke F16" << endl
		<< setw(30) << "[2]Hyundai Tucson 2021" << "[5]Toyota Corolla E210 Hatchback" << endl
		<< setw(30) << "[3]Hyundai Bayon" << "[6]Toyota Yaris 2017" << endl << endl;
	
	bool verif = true;
	int e, f;
	while(verif){
	try{
	
	cout << "Car 1: ";
	cin >> car1;
	
	if(car1 < 1 || car1 > 6){
		throw e;
		}
	
	car1 = car1 - 1;
	break;
	}
	
	catch(int e){
		cout << "Please enter a valid number within range 1-6." << endl;
		continue;
	}
	
}

	while(verif){
	try{
	cout << "Car 2: ";
	cin >> car2;
	
	if(car2 < 1 || car2 > 6 || car2 == car1+1){
		throw f;
	}
	
	car2 = car2 - 1;
	break;
	}
	
	catch(int f){
		cout << "Please enter a valid number within range 1-6, and not equal to the first car in comparison." << endl;
		continue;
	}
}
	
	// display
	system("cls");
	cout << setw(80) << specss[car1].carName[car1] << setw(50) << " " << specss[car2].carName[car2] << endl << endl <<
		"Php"<< specss[car1].price[car1] << setw(73) << "/day" << setw(50) << "PRICE" << "Php" << specss[car2].price[car2] << "/day" << endl << endl <<
		setw(80) << specss[car1].engine[car1] << setw(50) << "ENGINE" << specss[car2].engine[car2] << endl << endl <<
		setw(80) << specss[car1].suspension[car1] << setw(50) << "SUSPENSION" << specss[car2].suspension[car2] << endl << endl <<
		setw(80) << specss[car1].powertrain[car1] << setw(50) << "POWERTRAIN" << specss[car2].powertrain[car2] << endl << endl <<
		setw(80) << specss[car1].transmission[car1] << setw(50) << "TRANSMISSION" << specss[car2].transmission[car2] << endl << endl;
	
	system("pause");
}


void payment(int num, int pickUp, int dropOff, int xdays) {
	specs myArr[arrSize];
	
	int payMethod, cardPin;
	char cardNum[100];
	bool verif=true;
	int total=myArr[num].price[num]*xdays;
	int i;
	bool alphaDet=false;
	
	system("cls");
	cout<<"========== PAYMENT =========="<<endl<<endl;
	
	cout<<"car: "<<myArr[num].carName[num]<<endl
		<<"rate: Php"<<myArr[num].price[num]<<endl
		<<"days to rent: "<<xdays<<endl
		<<"total: Php"<<total<<endl
		<<endl;
	
	while(verif){
		try{
			cout<<"[1] card"<<endl
				<<"[2] cash"<<endl
				<<"enter desired payment method: ";
			cin>>payMethod;
			cout<<endl;
			cin.ignore();
			if (payMethod>2||payMethod<1) 
				throw(payMethod);
			
			verif=false;
		}
		catch(int error){
			cout<<error<<" is an invalid input."<<endl
				<<"please choose 1 or 2 only..."<<endl;
			continue;
		}
		verif=true;
		if(payMethod==1)
		{
		while(verif){
			try{
				alphaDet=false;
				cout<<"enter card number (no spaces): ";
				cin.ignore();
				cin.getline(cardNum, 100);
				for(i=0;i<strlen(cardNum);i++)
					if(isalpha(cardNum[i]))
						alphaDet=true;
				
				if (strlen(cardNum)!=15||alphaDet==true) 
					throw(cardNum);
				verif=false;
				cout<<endl;
				}
			catch(char* error){
				cout<<"input invalid; card number must be 16 numbers and have no letters"<<endl
					<<"try again..."<<endl;
				continue;
				}
			cout<<"transaction success!";
			}			
		}
		verif=false;
	}
	
	receipt(payMethod, num, pickUp, dropOff, total);
}

void receipt(int paymentMethod, int i, int pUp, int dOff, int xtotal){
	specs myArr[arrSize];
	ifstream fin;
	ofstream fout;
	int id;
	int *pID = &id;
	string strId;
	int *dynID = new int[dynSize];
	
	fin.open("idcount.txt");
	fin>>*pID;
	id++;
	fin.close();
	
	fout.open("idcount.txt");
	fout<<*pID;
	fout.close();
	
	dynID={pID};
	
	system("cls");
	
	cout<<"============================== RECEIPT =============================="<<endl;
	
	
	cout<<"reference number: "<<*(dynID+0)<<endl
		<< "name: " << *pName << endl
		<< "age: " << *pAge << endl
		<< "address: " << *pAddress << endl
		<<endl
		<<"car: "<<myArr[i].carName[i]<<endl
		<<"pick-up point: "<<pickUp[pUp-1]<<endl
		<<"drop-off point: "<<dropOff[dOff-1]<<endl;
		
	
	if(paymentMethod==1){
		cout<<"Payment Method: CARD"<<endl
			<<endl
			<<"amount paid: Php "<<xtotal<<endl
			<<"balance: 0"<<endl
			<<"thank you!"<<endl;
	}
	
	if(paymentMethod==2){
		cout<<"Payment Method: CASH"<<endl
			<<endl
			<<"please prepare Php"<<xtotal<<" to be paid in person to our driver. thank you!" << endl
			<<"balance: Php"<<xtotal<<endl;
	}
	
	cout<<endl<<"====================================================================="<<endl;
	
	strId=to_string(id);
	strId+=".txt";
	fout.open(strId.c_str());
	
	fout<<"============================== RECEIPT =============================="<<endl;
	
	
	fout<<"reference number: "<<*(dynID+0)<<endl
		<<endl
		<<"car: "<<myArr[i].carName[i]<<endl
		<<"pick-up point: "<<pickUp[pUp-1]<<endl
		<<"drop-off point: "<<dropOff[dOff-1]<<endl;
	
	if(paymentMethod==1){
		fout<<"Payment Method: CARD"<<endl
			<<endl
			<<"amount paid: Php "<<xtotal<<endl
			<<"balance: 0"<<endl
			<<"thank you!"<<endl;
	}
	
	if(paymentMethod==2){
		fout<<"Payment Method: CASH"<<endl
			<<endl
			<<"please prepare Php"<<xtotal<<" to be paid in person to our driver. thank you!" << endl
			<<"balance: Php"<<xtotal<<endl;
	}
	
	fout<<endl<<"====================================================================="<<endl;
	
	fout.close();

}

