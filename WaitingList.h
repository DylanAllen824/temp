#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include <queue>
#include <map>
#include <string>

// One pending request from a student for a specific resource.
struct WaitRequest {
    int studentID = 0;
    std::string studentName;
    std::string resourceID;
    std::string date;
};

// Keeps a separate FIFO queue of waiting students for each resource ID,
// so a student waiting on one resource is never handed a different one.
class WaitingList {
public:
    void enqueue(const std::string& resourceID, const WaitRequest& req);

    // Removes and returns the next student waiting for a resource.
    // Returns false (handled, not crashed) if nobody is waiting.
    bool dequeue(const std::string& resourceID, WaitRequest& out);

    bool isEmpty(const std::string& resourceID) const;
    size_t size(const std::string& resourceID) const;

    // Prints how many students are waiting for each resource that has
    // at least one person in line.
    void displayAll() const;

private:
    std::map<std::string, std::queue<WaitRequest>> queues_;
};

#endif // WAITING_LIST_H
