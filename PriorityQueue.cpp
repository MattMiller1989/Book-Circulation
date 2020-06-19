//include requiored package
#include "PriorityQueue.h"
PriorityQueue::PriorityQueue() {}
//implement method addEmployee
void PriorityQueue::addEmployee(Employee* temp)
{
    //insert element into the queue
    WorkQueue.push_back(temp);
}
//implement method pop to remove element from queue
// pulls highest priority from queue : O(n)
Employee* PriorityQueue::pop_max()
{
    // assume max is first element
    Employee* max = *WorkQueue.begin();
    vector<Employee*>::iterator it, toErase;
    it = toErase = WorkQueue.begin();
    it++;
    for (it; it != WorkQueue.end(); it++) {
        if ((max->getWait() - max->getRetain())
            < ((*it)->getWait() - (*it)->getRetain()))
        {
            max = *it;
            toErase = it;
        }
    }
    WorkQueue.erase(toErase);
    return max;
}
Employee* PriorityQueue::top() {
    Employee* max = *WorkQueue.begin();
    vector<Employee*>::iterator it = WorkQueue.begin();
    it++;
    for (it; it != WorkQueue.end(); it++) {
        if ((max->getWait() - max->getRetain())
            < ((*it)->getWait() - (*it)->getRetain()))
        {
            max = *it;
        }
    }
    return max;
}
bool PriorityQueue::empty() {
    return WorkQueue.size() < 1;
}