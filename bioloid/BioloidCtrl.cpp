/* 
 * File:   BioloidCtrl.cpp
 * Author: allen
 * 
 * Created on 2012年7月9日, 上午10:40
 */

#include "BioloidCtrl.h"
namespace BioCtrl {

    BioloidCtrl::BioloidCtrl() {
        mTimeOfCycle = 0.02f;
    }

    void BioloidCtrl::setTimeOfCycle(float mTimeOfCycle) {
        this->mTimeOfCycle = mTimeOfCycle;
    }

    float BioloidCtrl::getTimeOfCycle() const {
        return mTimeOfCycle;
    }

    BioEfect::BioloidJointsEffector& BioloidCtrl::getBioEffect()
    {
        return mBioEffector;
    }


    //BioloidCtrl::BioloidCtrl(const BioloidCtrl& orig) {
    //}

    BioloidCtrl::~BioloidCtrl() {
    }

    void BioloidCtrl::BioBlindMode(BLIND_MODE p_Mode) {
        switch (p_Mode) {
            case GETUP_LIE:
                this->mFixedCtrl.getUpFromLieBlindDeg();
                break;
            case GETUP_DIVE:
                this->mFixedCtrl.getUpFromDiveBlindDeg();
                break;
            case WALK_STRAIGHT:
                this->mFixedCtrl.walkBlindDeg();
                break;
            default:
                break;
        }
        return;

    }
}

