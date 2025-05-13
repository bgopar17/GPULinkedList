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
        void enqueue(string gpuName, string model, string issue){
            
        }
}