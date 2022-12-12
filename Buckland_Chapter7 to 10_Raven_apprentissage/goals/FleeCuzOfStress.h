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
        int         item,
        int         p_nbFramesBetweenChange) : Goal_GetItem(pBot, item)
    {
        m_bClockwise = RandBool();
    FleeCuzOfStress:nbFramesBetweenChange = p_nbFramesBetweenChange;
    };

    void Activate() override;
    int Process() override;
    void Terminate() override;

};


#endif //FLEECUZOFSTRESS_H
