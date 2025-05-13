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
            TicketNode * newTicket = new TicketNode(gpuName, model, issue); // Create a new ticket node
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

        void display(){
            if (head == nullptr) {
                cout << "Ticket queue is empty.\n";
                return;
            }
            TicketNode * current = head;
            cout << "\n GPU Support Tickets:\n";
            while(current != nullptr){
            cout << "---------------------------------\n";
            cout << "GPU name: " << current->gpuName << "\n";
            cout << "Model: " << current->model << "\n";
            cout << "Issue " << current->issue << "\n";
            cout << "Timestamp:" << current->timestamp << "\n";
            cout << "---------------------------------\n";
            }
        }
}

int main () {
    TicketQueue queue;
    queue.enqueue("NVIDIA RTX 4080", "RTX4080", "Artifacting under load");
    queue.enqueue("AMD RX 7900 XTX", "RX7900XTX", "Driver crash on boot");
    queue.enqueue("Intel Arc A770", "ARC770", "Incompatible with VR");

    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
    // The program will create a ticket queue, add some tickets, display the queue, resolve a ticket, and display the queue again.

}