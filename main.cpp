#include <iostream>
#include <string>
using namespace std; 

struct Node(){
    string name;
    string gender; 
    string disease; 
    string contact_no; 
    string condition;
    int priority; 
    int age; 

};

// declaring the functions 
void AddPatient(){} 

void DisplayPatients(){} 

void SendPatientToDoctor(){}

void SearchPatient(){}

void CancelAppointment(){}

int main(){

    while(true){
        int choice;
        cout<<"Enter your choices \n"; 
        cout<<"-------------------------||||||||-------------------------\n";
        cout<<"\nEnter 1 to Add new patient\n";
        cout<<"Enter 2 to Display the patients\n"; 
        cout<<"Enter 3 to send next patient to Doctor\n"; 
        cout<<"Enter 4 to search for specific patient\n"; 
        cout<<"Enter 5 to cancel the appointment of any patient\n"; 
        cout<<"Enter 6 to Exit\n"; 
        cin>>choice;  

        switch(choice){
            case 1:
            break; 

            case 2:
            break; 

            case 3:
            break; 

            case 4:
            break; 

            case 5:
            break;
            
            case 6:
            cout<<"Exit selected !\n"; 
            break; 
        }
    }
    return 0; 
}