#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
    Node* newNode = new Node;
    newNode->s = new Student(s.getName(), s.getPerm());
    newNode->next = NULL;
    if(!head || !tail) {
      head = tail = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }
}

std::string StudentRoll::toString() const {
    std::ostringstream oss;
    oss << "["; 
    Node* temp = head;
    while(temp){
        oss << temp->s->toString();
        if(temp != tail){
            oss << ",";
        }
        temp = temp->next;
    }
    oss << "]";
    return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  if(!orig.head){
    return;
  }
  head = NULL;
  Node* temp = orig.head;
  while(temp) {
    insertAtTail(*temp -> s);
    temp = temp -> next;
  }
}

StudentRoll::~StudentRoll() {
  while(head){
      Node *temp = head;
      Student *temp2 = temp->s;
      head = head->next;
      delete temp2;
      delete temp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  if(this->head){
    this->~StudentRoll();
  }

  Node* counter = right.head;
  while(counter){
    insertAtTail(*counter-> s);
    counter = counter -> next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
}




