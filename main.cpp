#include <iostream>
#include<string>
#include <ctime>

using namespace std;

struct TicketNode{ 
    string gpuName;
    string model;
    string issue;
    time_t timestamp;
    TicketNode* next;

    TickeNode(string g, sting m, string i){
        gpuName = g; // Initialize gpuName
        model = m; // Initialize model
        issue = i; // Initialize issue
        timestamp = time(0); //current time
        next = nullptr; // Initialize next to nullptr
    }
}

class TicketQueue {
    private:
        TickeNode * head;
        TicketNode * tail;

    public:
        TicketQueue(){
            head = nullptr; // Initialize head to nullptr
            tail = nullptr; // Initialize tail to nullptr
        }

        ~TicketQueue() {
            while (head != nullptr){
                dequeue();
            }
        }
        void enqueue(string gpuName, string model, string issue){// Add a new ticket to the queue
            TicketNode * newTicket = new TickeNode(gpuName, model, issue); // Create a new ticket node
            if (tail == nullptr){ // If the queue is empty
                head = tail = newTicket;
            } else {// If the queue is not empty
                tail -> next = newTicket;
                tail = newTicket;
            }
            cout << " Ticket created: " << gpuName << " " << model << " " << issue << endl;
        }

        void dequeue() {
            if (head==nullptr){
                cout << "No tickets in the queue." << endl;
                return;
            }
            TicketNode * temp = head; // Store the current head
            head = head -> next; // Move the head to the next ticket
            if (head == nullptr) tail = nullptr;
            cout << "Ticket resolved: " << temp->gpuName<< " (" <<temp->model << ")\n";
            delete temp; // Delete the resolved ticket"
        }
}