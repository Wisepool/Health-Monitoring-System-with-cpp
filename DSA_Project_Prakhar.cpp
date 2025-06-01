#include<iostream>

using namespace std;

    class CircularQueue {

    private:

        struct Symptom{

            string type;

            int severity;

        };

        Symptom queue[5];

        int front,rear,count;

    public:

        CircularQueue(){

            front=-1;

            rear=-1;

            count=0;

        }

        bool isFull(){

            return count==5;

        }

        bool isEmpty(){

            return count==0;

        }

        void addSymptom(string type,int severity){

            if(isFull()){

                cout<<"Queue is full. Deleting the oldest symptom to add a new one.\n";

                deleteOldestSymptom();

            }

            if(isEmpty()){

                front=0;

                rear=0;

            }else{

                rear=(rear+1)%5;

            }

            queue[rear]={type,severity};

            count++;

            cout<<"Symptom added successfully!\n";

        }

        void viewCurrentSymptoms(){

            if(isEmpty()){

                cout<<"No symptoms recorded.\n";

                return;

            }

            int i=front;

            cout<<"Current Symptoms:\n";

            do{

                cout<<"Symptom Type: "<<queue[i].type<<", Severity: "<<queue[i].severity<<endl;

                i=(i+1)%5;

            }while(i!=(rear+1)%5);

        }

        void deleteOldestSymptom(){

            if(isEmpty()){

                cout<<"No symptoms to delete.\n";

                return;

            }

            cout<<"Deleting oldest symptom: "<<queue[front].type<<endl;

            front=(front+1)%5;

            count--;

        }

        void updateSymptom(int index){

            if(isEmpty()||index<0||index>=count){

                cout<<"Invalid symptom index.\n";

                return;

            }

            int i=(front+index)%5;

            cout<<"Updating Symptom:\n";

            cout<<"Current Symptom Type: "<<queue[i].type<<endl;

            cout<<"Enter new type: ";

            cin>>queue[i].type;

            cout<<"Enter new severity (1-10): ";

            cin>>queue[i].severity;

            cout<<"Symptom updated successfully!\n";

        }

        void analyzeSymptomChanges(){

            if(isEmpty()){

                cout<<"No symptoms to analyze.\n";

                return;

            }

            int totalSeverity=0;

            int i=front;

            do{

                totalSeverity+=queue[i].severity;

                i=(i+1)%5;

            }while(i!=(rear+1)%5);

            int avgSeverity=totalSeverity/count;

            if(avgSeverity>7.0){

                cout<<"Alert: high average severity level , consult Therapist (Avg: "<<avgSeverity<<").\n";

            }else{

                cout<<"Symptoms are within manageable levels (Avg: "<<avgSeverity<<").\n";

            }

        }

        void generateReport(){

            if(isEmpty()){

                cout<<"No data to generate report.\n";

                return;

            }

            cout<<"Generating Symptom Report:\n";

            int i=front;

            do{

                cout<<"Symptom Type: "<<queue[i].type<<", Severity: "<<queue[i].severity<<endl;

                i=(i+1)%5;

            }while(i!=(rear+1)%5);

        }

        int getCount(){

            return count;

        }

    };

    void displayMenu(){

        cout<<"\n--- Mental Health Monitoring System ---\n";

        cout<<"1. Add New Symptom Entry\n";

        cout<<"2. View Current Symptoms\n";

        cout<<"3. Delete Oldest Symptom\n";

        cout<<"4. Update Symptom Entry\n";

        cout<<"5. Check for Significant Changes\n";

        cout<<"6. Generate Symptom Report\n";

        cout<<"7. Exit\n";

        cout<<"Select an option: ";

    }

    int main(){

        CircularQueue cq;

        int choice,severity,index;

        string type;

        do{

            displayMenu();

            cin>>choice;

            switch(choice){

            case 1:

                cout<<"Enter Symptom Type : ";

                cin>>type;

                cout<<"Enter Severity (1-10): ";

                cin>>severity;

                cq.addSymptom(type,severity);

                break;

            case 2:

                cq.viewCurrentSymptoms();

                break;

            case 3:

                cq.deleteOldestSymptom();

                break;

            case 4:

                cout<<"Enter the symptom index (0 to "<<cq.getCount()-1<<") to update: ";

                cin>>index;

                cq.updateSymptom(index);

                break;

            case 5:

                cq.analyzeSymptomChanges();

                break;

            case 6:

                cq.generateReport();

                break;

            case 7:

                cout<<"Exiting program...\n";

                return 0;

            default:

                cout<<"Invalid option. Please try again.\n";

            }

        }while(choice<7);

        return 0;

    }

