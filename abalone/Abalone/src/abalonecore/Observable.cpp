#include "Observable.h"
#include "Observer.h"

void Observable::addObserver(Observer * obs) {
    observers_.insert(obs);
}

void Observable::removeObserver(Observer * obs) {
    observers_.erase(obs);
}

void Observable::notifyObservers() {
    for(auto * o : observers_) {
        o->update();
    }
}
