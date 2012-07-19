/* 
 * File:   IntfBioloid.cpp
 * Author: allen
 * 
 * Created on 2012年7月9日, 上午10:09
 */

#include "IntfBioloid.h"
#include "BioloidCtrl.h"
#include "BioloidJointsData.h"
namespace BioInterface {
    using namespace BioData;

    IntfBioloid::IntfBioloid() {
    }

    IntfBioloid::~IntfBioloid() {
    }

    void IntfBioloid::setPerceptionMode(const PerceptionInfo& p_Pcept) {

        BioData::BioloidJointsData jointsInfo;
        jointsInfo.getJointData(BioData::BioloidJointsData::NECK).mDeg = p_Pcept.mJointsDegs[BioInterface::NECK];
        jointsInfo.getJointData(BioData::BioloidJointsData::NECK).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::NECK];

        jointsInfo.getJointData(BioData::BioloidJointsData::RSHOULDER).mDeg = p_Pcept.mJointsDegs[BioInterface::RSHOULDER];
        jointsInfo.getJointData(BioData::BioloidJointsData::RSHOULDER).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RSHOULDER];
        jointsInfo.getJointData(BioData::BioloidJointsData::RUPPERARM).mDeg = p_Pcept.mJointsDegs[BioInterface::RUPPERARM];
        jointsInfo.getJointData(BioData::BioloidJointsData::RUPPERARM).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RUPPERARM];
        jointsInfo.getJointData(BioData::BioloidJointsData::RLOWERARM).mDeg = p_Pcept.mJointsDegs[BioInterface::RLOWERARM];
        jointsInfo.getJointData(BioData::BioloidJointsData::RLOWERARM).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RLOWERARM];

        jointsInfo.getJointData(BioData::BioloidJointsData::LSHOULDER).mDeg = p_Pcept.mJointsDegs[BioInterface::LSHOULDER];
        jointsInfo.getJointData(BioData::BioloidJointsData::LSHOULDER).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LSHOULDER];
        jointsInfo.getJointData(BioData::BioloidJointsData::LUPPERARM).mDeg = p_Pcept.mJointsDegs[BioInterface::LUPPERARM];
        jointsInfo.getJointData(BioData::BioloidJointsData::LUPPERARM).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LUPPERARM];
        jointsInfo.getJointData(BioData::BioloidJointsData::LLOWERARM).mDeg = p_Pcept.mJointsDegs[BioInterface::LLOWERARM];
        jointsInfo.getJointData(BioData::BioloidJointsData::LLOWERARM).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LLOWERARM];


        jointsInfo.getJointData(BioData::BioloidJointsData::RHIP1).mDeg = p_Pcept.mJointsDegs[BioInterface::RHIP1];
        jointsInfo.getJointData(BioData::BioloidJointsData::RHIP1).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RHIP1];
        jointsInfo.getJointData(BioData::BioloidJointsData::RHIP2).mDeg = p_Pcept.mJointsDegs[BioInterface::RHIP2];
        jointsInfo.getJointData(BioData::BioloidJointsData::RHIP2).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RHIP2];
        jointsInfo.getJointData(BioData::BioloidJointsData::RTHIGH).mDeg = p_Pcept.mJointsDegs[BioInterface::RTHIGH];
        jointsInfo.getJointData(BioData::BioloidJointsData::RTHIGH).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RTHIGH];
        jointsInfo.getJointData(BioData::BioloidJointsData::RSHANK).mDeg = p_Pcept.mJointsDegs[BioInterface::RSHANK];
        jointsInfo.getJointData(BioData::BioloidJointsData::RSHANK).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RSHANK];
        jointsInfo.getJointData(BioData::BioloidJointsData::RANKLE).mDeg = p_Pcept.mJointsDegs[BioInterface::RANKLE];
        jointsInfo.getJointData(BioData::BioloidJointsData::RANKLE).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RANKLE];
        jointsInfo.getJointData(BioData::BioloidJointsData::RFOOT).mDeg = p_Pcept.mJointsDegs[BioInterface::RFOOT];
        jointsInfo.getJointData(BioData::BioloidJointsData::RFOOT).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::RFOOT];

        jointsInfo.getJointData(BioData::BioloidJointsData::LHIP1).mDeg = p_Pcept.mJointsDegs[BioInterface::LHIP1];
        jointsInfo.getJointData(BioData::BioloidJointsData::LHIP1).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LHIP1];
        jointsInfo.getJointData(BioData::BioloidJointsData::LHIP2).mDeg = p_Pcept.mJointsDegs[BioInterface::LHIP2];
        jointsInfo.getJointData(BioData::BioloidJointsData::LHIP2).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LHIP2];
        jointsInfo.getJointData(BioData::BioloidJointsData::LTHIGH).mDeg = p_Pcept.mJointsDegs[BioInterface::LTHIGH];
        jointsInfo.getJointData(BioData::BioloidJointsData::LTHIGH).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LTHIGH];
        jointsInfo.getJointData(BioData::BioloidJointsData::LSHANK).mDeg = p_Pcept.mJointsDegs[BioInterface::LSHANK];
        jointsInfo.getJointData(BioData::BioloidJointsData::LSHANK).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LSHANK];
        jointsInfo.getJointData(BioData::BioloidJointsData::LANKLE).mDeg = p_Pcept.mJointsDegs[BioInterface::LANKLE];
        jointsInfo.getJointData(BioData::BioloidJointsData::LANKLE).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LANKLE];
        jointsInfo.getJointData(BioData::BioloidJointsData::LFOOT).mDeg = p_Pcept.mJointsDegs[BioInterface::LFOOT];
        jointsInfo.getJointData(BioData::BioloidJointsData::LFOOT).mSpeed = p_Pcept.mJointsSpeeds[BioInterface::LFOOT];
        BIO_ROBOT.getBioPcepetion().setRawJoints(jointsInfo);
        
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
            p_Efct.mMode = BioInterface::DEG;
            getTargetJointsDeg(p_Efct);
        } else if (BIO_ROBOT.getBioEffect().getJointsFlag() == BioEfect::BioloidJointsEffector::DEG_SPEED) {
            p_Efct.mMode = BioInterface::DEG_SPEED;
            getTargetJointsDeg(p_Efct);
            getTargetJointsSpeed(p_Efct);
        }
    }

    void IntfBioloid::getTargetJointsDeg(EffectorInfo & p_Efct) {
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
