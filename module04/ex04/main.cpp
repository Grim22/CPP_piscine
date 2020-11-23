#include "Asteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "Comet.hpp"
#include "StripMiner.hpp"
#include "MiningBarge.hpp"

int main()
{
    /*
    Asteroid as;
    Comet cm;
    DeepCoreMiner dc;
    StripMiner sm;
    dc.mine(&as);
    dc.mine(&cm);
    sm.mine(&as);
    sm.mine(&cm);
    */

    DeepCoreMiner dcm0;
    DeepCoreMiner dcm1;
    StripMiner sm0;

    Asteroid as;
    Comet cm;

    MiningBarge barge;

    barge.equip(&dcm0);
    barge.equip(&dcm1);
    barge.equip(&sm0);

    barge.mine(&as);
    barge.mine(&cm);
}