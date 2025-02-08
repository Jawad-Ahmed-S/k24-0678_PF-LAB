#include<iostream>
using namespace std;
 struct Date{
            int date;
            int month;
            int year;
        };
    struct Event {
        string EventName;
        struct Date D;
        string Venue;
        string Organizer;
    };
int InputEvent(struct Event* E,int nEvents){
   
     
     for(int i=0;i<nEvents;i++){
        cout << "Enter event name: ";
    cin >> E[i].EventName;

    cout << "Enter event date (dd mm yyyy): ";
    cin >> E[i].D.date >> E[i].D.month >> E[i].D.year;

    cout << "Enter event venue: ";
    cin >> E[i].Venue;

    cout << "Enter event organizer: ";
    cin >> E[i].Organizer;
     }
     return nEvents;

}
void DisplayEvent(struct Event E){
    cout << "\nEvent Details:" << endl;
    cout << "Event Name: " << E.EventName << endl;
    cout << "Event Date: " << E.D.date << "/" << E.D.month << "/" << E.D.year << endl;
    cout << "Venue: " << E.Venue << endl;
    cout << "Organizer: " << E.Organizer << endl;

}
void SearchEvent(struct Event* E,int nEvents,struct Date DS){
    for(int i=0;i<nEvents;i++){
            if(E[i].D.date == DS.date){
                DisplayEvent(E[i]);
                break;
            }
    }
}
struct Event* addEvent(struct Event* E,int nEvents){
    Event* E1 = new Event[nEvents+1];
    for (int i=0;i<nEvents;i++){
        E1[i].EventName=E[i].EventName;
        E1[i].Venue=E[i].Venue;
        E1[i].Organizer=E[i].Organizer;
        E1[i].D.date=E[i].D.date;
        E1[i].D.month=E[i].D.month;
        E1[i].D.year=E[i].D.year;
    }
    
}
int main(){

   cout<<"First Input the Events Data";
    int nEvents;
    cout<<"Number of Events";
    cin>>nEvents;
    Event* E = new Event[nEvents];

    int NumberOfEvents= InputEvent(E,nEvents);

    int Functionality;
    struct Date DS;
    cout<<"1. Search by Date";
    cout<<"2. End";
    cin>>Functionality;
    switch(Functionality){

        case 1:
        cout<<"enter the date";
        cin>>DS.date;
        cin>>DS.month;
        cin>>DS.year;
        SearchEvent(E,nEvents,DS);
        case 2:
        return 0;
        default:
        cout<<"enter the date";
        cin>>DS.date;
        cin>>DS.month;
        cin>>DS.year;
        SearchEvent(E,nEvents,DS);
    }

}