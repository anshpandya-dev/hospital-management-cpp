#include <iostream>
#include <string>
using namespace std; 

struct Patient{
    string name;
    string gender; 
    string disease; 
    string contact_no; 
    string condition;
    string ID; 
    int priority; 
    int age; 
    Patient *next; 
    Patient *prev; 

};

// declaring the functions 
void AddPatient(Patient *&s,Patient *&t){
    string n, g, d, no,id; 
    int pri, a; 
    Patient *c; 
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

    cout<<"Enter patient's ID:-  ";
    getline(cin,id); 
    
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
    c->ID = id; 
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

    Patient *temp; 
    temp = c->prev;
    // swapping logic  
    while (temp != NULL && c->priority>t->priority){
        Patient *temp_add_prev = temp->prev; 
        Patient *c_address_next = c->next;
        
        if(temp_add_prev != NULL){
            temp_add_prev->next = c; 
        }
        else{
            s=c;     // making the c the first node 
        }

        if(c_address_next !=NULL){
            c_address_next->prev = temp; 
        }
        else {
            t= temp;             // now temp is the new tail
        }

        c->prev = temp_add_prev; 
        c->next = temp; 
        temp->prev = c; 
        temp->next = c_address_next; 

        // updating the value of the pointer temp 
        t = c->prev;   
    }
    cout<<"Patient added successfully\n"; 


} 

void DisplayPatients(Patient *s){
    Patient *temp = s; 
    if(temp==NULL){
        cout<<"Nothing to display\n"; 
    }
    else{
        cout<<"============ Waiting List ============\n";
        while (temp != NULL){
            cout<<"Name of Patient:   "<<temp->name<<endl;
            cout<<"Patient ID     :   "<<temp->ID<<endl;  
            cout<<"Disease        :   "<<temp->disease<<endl; 
            cout<<"Condition      :   "<<temp->condition<<endl; 
            cout<<"Gender         :   "<<temp->gender<<endl; 
            cout<<"Age            :   "<<temp->age<<endl; 
            cout<<"Contact Number :   "<<temp->contact_no<<endl; 
            cout<<"--------------------------------------------"<<endl; 
            
            temp = temp->next; 
        }
    }
} 

void SendPatientToDoctor(Patient *&s){
    
    // edge case in which there is no patient 
    if(s==NULL){
        cout<<"No Patients are currently waiting !"<<endl; 
    }
    else {
        cout<<"Next Patient's Details are: "<<endl; 
        cout<<"Name           :   "<<s->name<<endl; 
        cout<<"Patient ID     :   "<<s->ID<<endl;  
        cout<<"Disease        :   "<<s->disease<<endl; 
        cout<<"Condition      :   "<<s->condition<<endl; 
        cout<<"Contact number :   "<<s->contact_no<<endl; 
        cout<<"Gender         :   "<<s->gender<<endl; 
        cout<<endl; 
        cout<<"--------------------------------------------"<<endl; 
        cout<<"Sending next patient to the Doctor !"<<endl; 
        s = s->next; 
        if(s!=NULL){
            s->prev = NULL;}  
    }
}

Patient* SearchPatient(Patient *s){
    if(s==NULL){
        cout<<"No patient record available\n";
        return NULL;
    }
    else 
    {
        Patient *temp = s; 
        int no_patient = 1; 
        int search_choice; 
        cout<<"How would you like to search a patient\n"; 
        cout<<"1. By name\n";
        cout<<"2. By ID\n"; 
        cin>>search_choice; 
        string name; 
        string id; 

        switch (search_choice){

            case 1: 
            cin.ignore(); 
            cout<<"Enter the name of the patient:- ";
            getline(cin, name);
            while(temp!=NULL && temp->name != name){
                temp = temp->next; 
                no_patient +=1; 
            }
            if(temp !=NULL){
                cout<<"Patient Foudnd at number "<<no_patient<<endl; 
                cout<<"Patient details are given\n "; 
                cout<<"Name of Patient  :   "<<temp->name<<endl;
                cout<<"Patient ID       :   "<<temp->ID<<endl;  
                cout<<"Disease          :   "<<temp->disease<<endl; 
                cout<<"Condition        :   "<<temp->condition<<endl; 
                cout<<"Gender           :   "<<temp->gender<<endl; 
                cout<<"Age              :   "<<temp->age<<endl; 
                cout<<"Contact Number   :   "<<temp->contact_no<<endl; 

                return temp;
            }
            else{
                cout<<"The patient you are searching for does not exist in the Data"<<endl; 
                return NULL;
            }
            
            case 2:
            cin.ignore(); 
            cout<<"Enter the id of the patient:- ";
            getline(cin, id);
            while(temp!=NULL && temp->ID != id){
                temp = temp->next; 
                no_patient +=1; 
            }
            if(temp !=NULL){
                cout<<"Patient Foudnd at number \n"<<no_patient; 
                cout<<"Patient details are given\n "; 
                cout<<"Name of Patient :   "<<temp->name<<endl;
                cout<<"Patient ID      :   "<<temp->ID;  
                cout<<"Disease         :   "<<temp->disease<<endl; 
                cout<<"Condition       :   "<<temp->condition<<endl; 
                cout<<"Gender          :   "<<temp->gender<<endl; 
                cout<<"Age             :   "<<temp->age<<endl; 
                cout<<"Contact Number  :   "<<temp->contact_no<<endl; 

                return temp;
            }
            else{
                cout<<"The patient you are searching for does not exist in the Data"<<endl; 
                return NULL;
            }

            default:
            cout<<"Invalid choice\n";
            return NULL;      
        }
    }
}

void CancelAppointment(Patient *&s){
    Patient *temp = SearchPatient(s);  
    // if the first node is being deleted 
    if(temp == NULL){
        cout<<endl; 
    }
    else{
        if(temp->prev==NULL){         // if the first patient's appointment is being cancelled 
            s=s->next;
            if(s != NULL){
                s->prev = NULL;
            }
 
            cout<<"\nAppointment cancelled successfully\n"; 
        }  
        else if(temp->next==NULL){     // if the last is being deleted 
            Patient *temp1 = temp->prev; 
            temp->prev = NULL; 
            temp1->next =  NULL; 
            cout<<"\nAppointment cancelled successfully\n"; 
        }
        else{
            Patient *temp1 = temp->prev;     
            Patient *temp2 = temp->next; 
            temp1->next = temp2; 
            temp2->prev = temp1;  
            cout<<"\nAppointment cancelled successfully\n"; 
        }
    }
}

int main(){
    Patient *s,*t; 
    s=NULL,t=NULL; 
    string User_name = "Admin", Password = "AD1234"; 
    string t_usname, t_pass; 
    cout<<"Enter your user name : "; 
    getline(cin, t_usname);
    cout<<"Enter  password: ";
    getline(cin, t_pass); 


    if(t_usname==User_name && t_pass==Password) {
        cout<<"Access Granted\n"; 

        while(true){
            int choice;
            cout<<"Enter your choice \n"; 
            cout<<endl; 
            cout<<"\nEnter 1 to Add new patient\n";
            cout<<"Enter 2 to Display the patients\n"; 
            cout<<"Enter 3 to send next patient to Doctor\n"; 
            cout<<"Enter 4 to search for specific patient\n"; 
            cout<<"Enter 5 to cancel the appointment of any patient\n"; 
            cout<<"Enter 6 to Exit\n"; 
            cin>>choice;  

            switch(choice){
                case 1:
                cin.ignore();     // this will ignore the extra \n in the buffer 
                AddPatient(s,t); 
                break; 

                case 2:
                DisplayPatients(s); 
                break; 

                case 3:
                SendPatientToDoctor(s);
                break; 

                case 4:
                SearchPatient(s); 
                break; 

                case 5:
                CancelAppointment(s); 
                break;
                
                case 6:
                cout<<"Exit selected !\n"; 
                return 0; 
                break; 

                default:
                cout<<"Invalid choice !\n"; 
            }
        }
    }
    else{
        cout<<"Access Denied \n"; 
    }
    return 0; 
}