#ifndef FLEECUZOFSTRESS_H
#define FLEECUZOFSTRESS_H
#include "Goal_GetItem.h"


class FleeCuzOfStress : public Goal_GetItem {

private:
    bool        isFleeing;
    void        FleeCuzOfStress::initFlee();

public:
    FleeCuzOfStress(
        Raven_Bot* pBot,
        int         item) : Goal_GetItem(pBot, item)
    {
    };

    void Activate() override;
    int Process() override;
    void Terminate() override;

};


#endif //FLEECUZOFSTRESS_H
