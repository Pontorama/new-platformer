#ifndef ServiceLocator_h
#define ServiceLocator_h

#include "GameManager.h"

class ServiceLocator{
    private:

    public:
        ServiceLocator();
        // Provides
        void provide(GameManager* gm);
};

#endif