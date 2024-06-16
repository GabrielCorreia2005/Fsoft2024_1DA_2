#ifndef WALLET_MANAGEMENT_ACQUIRE_H
#define WALLET_MANAGEMENT_ACQUIRE_H

#include "Insurance.h"
#include "Client.h"

class Acquire {
private:
    Insurance *insurance;
    Client *client;

public:
    Acquire(Insurance *insurance, Client *client);
    Acquire(const Acquire &obj);
    ~Acquire();

    Insurance* getInsurance() const;
    void setInsurance(Insurance *insurance);

    Client* getClient() const;
    void setClient(Client *client);

    bool operator==(const Acquire& rhs) const;
};

#endif //WALLET_MANAGEMENT_ACQUIRE_H