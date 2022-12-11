#ifndef NADE_H
#define NADE_H
#pragma warning (disable:4786)

#include "Raven_Projectile.h"

class Raven_Bot;

class Nade : public Raven_Projectile
{
private:

    //the radius of damage, once the nade has impacted
    double    m_dBlastRadius;

    //this is used to render the splash when the nade impacts
    double    m_dCurrentBlastRadius;

    //If the nade has impacted we test all bots to see if they are within the 
    //blast radius and reduce their health accordingly
    void InflictDamageOnBotsWithinBlastRadius();

    //tests the trajectory of the shell for an impact
    void TestForImpact();

public:

    Nade(Raven_Bot* shooter, Vector2D target);

    void Render();

    void Update();

};


#endif