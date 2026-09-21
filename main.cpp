#include <iostream>
#include <string>
using namespace std; 

struct Patient{
    string name;
    string gender; 
    string disease; 
    string contact_no; 
    string condition;
    int priority; 
    int age; 
    Patient *next; 
    Patient *prev; 

};

// declaring the functions 
void AddPatient(){
    string n, g, d, no; 
    int pri, a; 
    Patient *t, *s,*c; 
    s=NULL, t=NULL; 
    c = new Patient();     // creating node 

    cout<<"Enter the name of the patient:- "; 
    getline(cin, n); 
    
    cout<<"Enter gender of the patient:- "; 
    getline(cin, g); 

    cout<<"Enter the patient's disease:- "; 
    getline(cin, d); 
    
    cout<<"Enter contact number:- "; 
    getline(cin, no);
    
    cout<<"Enter the age of the patient:- "; 
    cin>>a; 

    cout<<"Enter the condition of patient\n"; 
    cout<<"1. Critical/Energency\n";
    cout<<"2. Serious\n";
    cout<<"3. Moderate\n";
    cout<<"4. Normal/stable\n"; 
    cin>>pri; 
    cout<<endl; 

    c->name = n;
    c->gender = g; 
    c->disease = d; 
    c->age = a; 
    c->contact_no = no; 
    c->priority= pri;  
    c->next = NULL;
    c->prev = NULL; 
    if(pri==1){
        c->condition = "Critical/Energency Case";  
    }
    else if(pri==2){
        c->condition = "Serious";
    }
    else if(pri==3){
        c->condition = "Moderate"; 
    }
    else{
        c->condition = "Normal"; 
    }

    if(s==NULL){
        s=c; 
        t=c; 
    }
    else {
        t->next = c; 
        c->prev = t;
        t=c; 
    }

    



} 

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
            AddPatient(); 
            break; 

            case 2:
            DisplayPatients(); 
            break; 

            case 3:
            SendPatientToDoctor();
            break; 

            case 4:
            SearchPatient(); 
            break; 

            case 5:
            CancelAppointment(); 
            break;
            
            case 6:
            cout<<"Exit selected !\n"; 
            break; 

            default:
            cout<<"Invalid choice !\n"; 
        }
    }
    return 0; 
}