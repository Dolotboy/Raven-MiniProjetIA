#ifndef FLEECUZOFSTRESS_H
#define FLEECUZOFSTRESS_H
#include "Goal_GetItem.h"


class FleeCuzOfStress : public Goal_Composite<Raven_Bot> {

private:
    bool        isFleeing;
    void        FleeCuzOfStress::initFlee();

public:
    FleeCuzOfStress(Raven_Bot* pOwner) :Goal_Composite<Raven_Bot>(pOwner, goal_attack_target)
    {}

    void Activate() override;
    int Process() override;
    void Terminate() override;

};


#endif //FLEECUZOFSTRESS_H
