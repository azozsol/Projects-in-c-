#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>

class Observer;

/**
 * @brief The Observable interface excpected to be observed by an Observer.
 */
class Observable {

private:
    std::set<Observer *> observers_;

public:
    /**
     * @brief Adds an observer to the list of observers.
     * @param obs a given Observer
     */
    void addObserver(Observer * obs);

    /**
     * @brief Removes an Observer from the list of Observers.
     * @param obs the Observer rto remove.
     */
    void removeObserver(Observer * obs);

    /**
     * @brief Notifies all observers when something changed.
     */
    void notifyObservers();
};

#endif // OBSERVABLE_H
