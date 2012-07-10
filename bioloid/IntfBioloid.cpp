/* 
 * File:   IntfBioloid.cpp
 * Author: allen
 * 
 * Created on 2012年7月9日, 上午10:09
 */

#include "IntfBioloid.h"
#include "BioloidCtrl.h"

namespace BioInterface {
    using namespace std;
    IntfBioloid::IntfBioloid() {
    }

    //IntfBioloid::IntfBioloid(const IntfBioloid& orig) {
    //}

    IntfBioloid::~IntfBioloid() {
    }

    void IntfBioloid::setPerceptionMode(const PerceptionInfo& p_Pcept) {

    }

    void IntfBioloid::setBlindMode(BioInterface::BLIND_MODE p_Mode) {
        switch (p_Mode) {
            case GETUP_LIE:
                BIO_ROBOT.BioBlindMode(BioCtrl::BioloidCtrl::GETUP_LIE);
                break;
            case GETUP_DIVE:
                BIO_ROBOT.BioBlindMode(BioCtrl::BioloidCtrl::GETUP_DIVE);
                break;
            case WALK_STRAIGHT:
                BIO_ROBOT.BioBlindMode(BioCtrl::BioloidCtrl::WALK_STRAIGHT);
                break;
        }
    }

    void IntfBioloid::getTargetJoints(EffectorInfo& p_Efct) {
        if (BIO_ROBOT.getBioEffect().getJointsFlag() == BioEfect::BioloidJointsEffector::DEG) {

            getTargetJointsDeg(p_Efct);
        } else if (BIO_ROBOT.getBioEffect().getJointsFlag() == BioEfect::BioloidJointsEffector::SPEED) {
            getTargetJointsSpeed(p_Efct);
        }
    }

    void IntfBioloid::getTargetJointsDeg(EffectorInfo & p_Efct) {
        p_Efct.flag = BioInterface::DEG;
        p_Efct.mJointsDegs[BioInterface::NECK] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::NECK].getDeg();


        p_Efct.mJointsDegs[BioInterface::RSHOULDER] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RSHOULDER].getDeg();
        p_Efct.mJointsDegs[BioInterface::RUPPERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RUPPERARM].getDeg();
        p_Efct.mJointsDegs[BioInterface::RLOWERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RLOWERARM].getDeg();


        p_Efct.mJointsDegs[BioInterface::LSHOULDER] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LSHOULDER].getDeg();
        p_Efct.mJointsDegs[BioInterface::LUPPERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LUPPERARM].getDeg();
        p_Efct.mJointsDegs[BioInterface::LLOWERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LLOWERARM].getDeg();


        p_Efct.mJointsDegs[BioInterface::RHIP1] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RHIP1].getDeg();
        p_Efct.mJointsDegs[BioInterface::RHIP2] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RHIP2].getDeg();
        p_Efct.mJointsDegs[BioInterface::RTHIGH] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RTHIGH].getDeg();
        p_Efct.mJointsDegs[BioInterface::RSHANK] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RSHANK].getDeg();
        p_Efct.mJointsDegs[BioInterface::RANKLE] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RANKLE].getDeg();
        p_Efct.mJointsDegs[BioInterface::RFOOT] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RFOOT].getDeg();



        p_Efct.mJointsDegs[BioInterface::LHIP1] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LHIP1].getDeg();
        p_Efct.mJointsDegs[BioInterface::LHIP2] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LHIP2].getDeg();
        p_Efct.mJointsDegs[BioInterface::LTHIGH] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LTHIGH].getDeg();
        p_Efct.mJointsDegs[BioInterface::LSHANK] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LSHANK].getDeg();
        p_Efct.mJointsDegs[BioInterface::LANKLE] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LANKLE].getDeg();
        p_Efct.mJointsDegs[BioInterface::LFOOT] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LFOOT].getDeg();
    }

    void IntfBioloid::getTargetJointsSpeed(EffectorInfo & p_Efct) {
        p_Efct.flag = BioInterface::SPEED;
        p_Efct.mJointsSpeeds[BioInterface::NECK] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::NECK].getSpeed();


        p_Efct.mJointsSpeeds[BioInterface::RSHOULDER] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RSHOULDER].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::RUPPERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RUPPERARM].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::RLOWERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RLOWERARM].getSpeed();


        p_Efct.mJointsSpeeds[BioInterface::LSHOULDER] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LSHOULDER].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::LUPPERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LUPPERARM].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::LLOWERARM] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LLOWERARM].getSpeed();


        p_Efct.mJointsSpeeds[BioInterface::RHIP1] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RHIP1].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::RHIP2] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RHIP2].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::RTHIGH] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RTHIGH].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::RSHANK] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RSHANK].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::RANKLE] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RANKLE].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::RFOOT] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::RFOOT].getSpeed();



        p_Efct.mJointsSpeeds[BioInterface::LHIP1] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LHIP1].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::LHIP2] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LHIP2].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::LTHIGH] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LTHIGH].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::LSHANK] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LSHANK].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::LANKLE] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LANKLE].getSpeed();
        p_Efct.mJointsSpeeds[BioInterface::LFOOT] =
                BIO_ROBOT.getBioEffect().getBioJoints()[BioEfect::BioloidJointsEffector::LFOOT].getSpeed();
    }



}/*namespace BioInterface*/
