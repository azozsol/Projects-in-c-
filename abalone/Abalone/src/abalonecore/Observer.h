#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief The observer interface that allows to observe an observable.
 */
class Observer{

public:
    virtual ~Observer() = default;
    /**
     * @brief Updates the changed informations.
     */
    virtual void update() = 0;
};

#endif // OBSERVER_H
