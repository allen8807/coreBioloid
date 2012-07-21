/* 
 * File:   BioloidCtrl.cpp
 * Author: allen
 * 
 * Created on 2012年7月9日, 上午10:40
 */

#include "BioloidCtrl.h"
namespace BioCtrl {

    BioloidCtrl::BioloidCtrl() {
        //       mTimeOfCycle = 0.2f;
    }

    void BioloidCtrl::setTimeOfCycle(float p_timeOfCycle) {
        mPecpetion.setTimeOfCycle(p_timeOfCycle);

    }

    float BioloidCtrl::getTimeOfCycle() const {
        return mPecpetion.getTimeOfCycle();
    }

    BioEfect::BioloidJointsEffector& BioloidCtrl::getBioEffect() {
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

     void BioloidCtrl::BioNormalLoop(){
//更新传感器的信息
         mPecpetion.update();

         BioPcept::BioloidPerception::BalanceState nowState = mPecpetion.getNowBalanceState();
         if(nowState == BioPcept::BioloidPerception::LIED_STATE){
       //       std::cout<<"Loop before Lie"<<std::endl;
             this->mFixedCtrl.getUpFromLie();
         }else if(nowState == BioPcept::BioloidPerception::DIVED_STATE){
      //         std::cout<<"Loop before Dive"<<std::endl;
             this->mFixedCtrl.getUpFromDive();
         }else if(nowState == BioPcept::BioloidPerception::BALANCE_STATE){
         //    std::cout<<"Loop before walk"<<std::endl;
              this->mFixedCtrl.walkStraight();
         }
     }

}

