#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}
    virtual void register_observer(Observer *o) = 0;
    virtual void remove_observer(Observer *o) = 0;
    virtual void notify_observer() = 0;
};


#endif /* SUBJECT_H */