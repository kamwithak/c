#include <iostream>
#include <random>

using namespace std;

struct ticket {                             // Node class equivalent, more or less
    unsigned int numbers[6];                // unique elements in ticket.numbers[]
    ticket* next;                           // ptr to next ticket object, ie) next node
}; 
 
class SuperDraw {                           // LinkedList class representation

    private:                                        // traditional fields
        ticket* ticketListHead;
        ticket* ticketListTail;
        const int numbersLength = 6;                // len(ticket.numbers[]) == 6
        int size = 0;                               // empty linkedList upon init
        int ithNode = 0;                            // ctr to mark a particular node in LinkedList

    public:
        SuperDraw() {                               // default constructor
            ticketListHead = NULL;                  // init both head and tail pointers to NULL
            ticketListTail = NULL;                  // standard linkedList
        }
        SuperDraw(int numberOfTickets) {            // second constructor
            cout << to_string(numberOfTickets) + " new tickets were successfully generated. (BELOW)" << endl;
            for (int i = 0 ; i < numberOfTickets ; i++) {
                newTicket(1);                       // simplistic use of tools that we've already built
            }
        }
        SuperDraw(SuperDraw &src) {                 // copy constructor
            ticket *aTicket = src.getHeadPtr();     // get head ptr of LinkedList
            while (aTicket != NULL) {               // iterate over LinkedList
                appendNode(aTicket);                // append to end of new LinkedList
                aTicket = aTicket->next;            // next node, repeat
            }
        }
        ~SuperDraw(){                               // default destructor
            ticket* current = ticketListHead;
            ticket* next;                           // init needed variables
            while (current != NULL) {               // delete all nodes in LinkedList
                next = current->next;               // O(size of LinkedList) ~ linear time
                delete current;                     // operand is faster than function:
                current = next;                     // => delete > free()
            }
        }

        bool contains(unsigned int &randomNumber, ticket &aTicket) {    // is randomNumber
            bool cond = false;                                          // contained in aTicket?
            for (unsigned int &number : aTicket.numbers) {
                if (number == randomNumber) {
                    cond = true;
                }
            }
            return cond;                                                // boolean answer
        }

        void initTicket(ticket &aTicket) {          // inserts a zero in ticket.numbers, at each index
            for (unsigned int &number : aTicket.numbers) {
                number = 0;
            }
            aTicket.next = NULL;                    // null for next field, healthy design choice
        }

        void display(ticket *aTicket) {                              // FINISHED
            unsigned int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
            for (int k = 0 ; k < numbersLength ; k++) {              // get respective lotto numbers
                switch (k) {                                         // put these in respective variables:
                    case 0:                                          // linear implementation
                        one = aTicket->numbers[k];
                        break;
                    case 1:
                        two = aTicket->numbers[k];
                        break;
                    case 2:
                        three = aTicket->numbers[k];
                        break;
                    case 3:
                        four = aTicket->numbers[k];
                        break;
                    case 4:
                        five = aTicket->numbers[k];
                        break;
                    case 5:
                        six = aTicket->numbers[k];
                        break;                              // all variables should be populated:
                                                            // linear execution should finish here
                    default:
                        cout << "error ~ execution handling went wrong" << endl;    // line shouldn't run

                }
            }
            // default output below:
            cout << "A new ticket was successfully generated. The numbers are: ";
            cout << to_string(one) + ", " + to_string(two) + ", " + to_string(three) + ", ";
            cout << to_string(four) + ", " + to_string(five) + ", " + to_string(six) << endl;
        }

        void sort(ticket *aTicket) {                                      // FINISHED
            unsigned int temp = 0;
            for (int i = 0 ; i < numbersLength ; i++) {                   // bubbleSort()
                for (int j = 0 ; j < numbersLength - i - 1; j++) {
                    if (aTicket->numbers[j] > aTicket->numbers[j + 1]) {  // quadratic time, worst-case n^2
                        temp = aTicket->numbers[j + 1];
                        aTicket->numbers[j + 1] = aTicket->numbers[j];    // swap code
                        aTicket->numbers[j] = temp;
                    }
                }
            }                                                             // google was good, here! XD
        }

        ticket* createRandomTicket() {         // FINISHED
            ticket* aTicket = new ticket;      // init a new ticket obj
            initTicket(*aTicket);              // set next field to null & populate with tmp values
            unsigned int tmpRand = 0;                           // Random Variable: tmpRand
            for (unsigned int &number : aTicket->numbers) {     // for each number in numbers[6]
                retry:                                          // label
                tmpRand = (unsigned int) (rand() % 49) + 1;     // [1,49] ~ random variable
                if (!contains(tmpRand, *aTicket)) {             // check if unique
                    number = tmpRand;                           // if so, replace with random number
                } else {                                        // else: repeat until we get a unique random #
                    goto retry;                                 // bad design, oh well :/
                }                                               // it should work tho ;)
            }
            //cout << "unique ticket created" << endl;          // unique ticket obj created
            return aTicket;
        }

        void appendNode(ticket* aTicket) {     // addLast():
            if (ticketListHead == NULL) {      // if head is null: then set head and tail to new node
                ticketListHead = aTicket;
                ticketListTail = aTicket;      // empty linkedList ; otherwise, use tail ptr:
            } else {
                ticketListTail->next = aTicket;                     // tail points to new node
                ticketListTail = ticketListTail->next;              // reset the tail of linkedList
            }

        }
                                                                    // FINISHED
        void newTicket(int verbos = 0) {                            // append a node to the linked list
            ticket* aTicket = createRandomTicket();                 // create a ticket
            sort(aTicket);                                          // sort every newly created ticket

            if (verbos == 1) {                                      // if so: display ticket
                display(aTicket);
            }

            appendNode(aTicket);                                    // append aTicket to end of LinkedList
            size += 1;                                              // increment size of LinkedList
        }

        void printAllTicketNumbers() {                          // FINISHED
            cout << "We found " + to_string(getSize()) + " generated tickets:" << endl;
            ticket* p = new ticket;
            p->next = ticketListHead;
            while (p->next != NULL) {
                for (int l = 0; l < numbersLength; l++) {
                    cout << p->next->numbers[l];                // output value at lth index
                    if (l == numbersLength - 1) {               // end of tickets array -> endline and break;
                        cout << endl;
                        break;
                    }
                    cout << ", ";                               // output a comma and some space, repeat
                }
                p = p->next;                                    // iterate to next node
            }
        }

        // @return true if myNumbers already exists in data structure, otherwise false
        bool verifySequence(int myNumbers[]) {                                    // FINISHED
            ticket* p = new ticket;                                               // ticket == node
            p->next = ticketListHead;                                             // ticket points to head
            int k, ctr = 0;                                                       // init variables
            bool alreadyExists = false;                                           // no match by default
            while (p->next != NULL && !alreadyExists) {                           // iterate over linkedList
                k = 0;                                                            // ctr for ith array
                for (int l = 0; l < numbersLength; l++) {                         // over each node
                    if (p->next->numbers[l] == (unsigned int) myNumbers[l]) {     // make comparison
                        k += 1;                                                   // increment
                        if (k == numbersLength) {                                 // given k == 6:
                            alreadyExists = true;                                 // we have found a match
                            break;                                                // exit all loops
                        }
                    }
                }
                ++ctr;                                      // ctr for list of linked nodes
                p = p->next;                                // point to next node
            }
            ithNode = ctr;                                  // node to delete; global variable assignment
        if (!alreadyExists) { cout << "The provided sequence of numbers was never generated before and cannot be found in the LinkedList." << endl; }
            else { cout << "The provided sequence of numbers was generated before and can be found in the LinkedList."  << endl; }
            return alreadyExists;                           // F: New Sequence, T: Sequence already exists in linkedList
        }

        void deleteSequence(int myNumbers[]) {                           // FINISHED
            if (verifySequence(myNumbers)) {                             // if the particular node exits:
                ticket* current = ticketListHead;                        // otherwise, cleverly handled using verifySequence()
                ticket* previous = new ticket;
                if (getTicketToDelete() == 1) {                          // code to delete first node in LinkedList
                    ticketListHead = ticketListHead->next;
                } else if (getTicketToDelete() == getSize()) {           // code to delete last node in LinkedList
                    while(current->next != NULL) {
                        previous = current;
                        current = current->next;
                    }
                    ticketListTail = previous;
                    previous->next = NULL;
                } else {
                    for(int i = 1 ; i < getTicketToDelete() ; i++) {    // code to delete node @ a particular position which is
                        previous = current;                             // not the first or last node in the LinkedList
                        current = current->next;
                    }
                    previous->next = current->next;
                }
                free(current);                                          // free allocated memory
                size -= 1;                                              // decrement size of LinkedList
                cout << "The provided sequence of numbers is now successfully deleted." << endl;
            }
        }

        // Getters:
        int getSize() {
            return size;
        }
        int getTicketToDelete() {
            return ithNode;
        }
        ticket* getHeadPtr() {
            return ticketListHead;
        }
        ticket* getTailPtr() {
            return ticketListTail;
        }

};

int main() {

    SuperDraw sd;
    sd.newTicket(1);
    sd.newTicket(1);
    sd.newTicket(1);
    sd.newTicket(1);

    sd.printAllTicketNumbers();

    int myNumbers[6] = {7,8,13,14,20,22};
    sd.deleteSequence(myNumbers);

    sd.printAllTicketNumbers();

    //SuperDraw sd2(sd);                    // implemented incorrectly
    //cout << sd.getSize() << endl;
    return 0;
}
