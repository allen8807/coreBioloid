/* 
 * File:   IntfBioloid.h
 * Author: allen
 *
 * Created on 2012年7月9日, 上午10:09
 */

#ifndef INTFBIOLOID_H
#define	INTFBIOLOID_H
#include "Singleton.hpp"
namespace BioInterface {
    //Interface Hinge Joints ID

    enum IHJ_ID {
        NECK = 0,
        RSHOULDER = 1,
        RUPPERARM = 2,
        RLOWERARM = 3,
        LSHOULDER = 4,
        LUPPERARM = 5,
        LLOWERARM = 6,
        RHIP1 = 7,
        RHIP2 = 8,
        RTHIGH = 9,
        RSHANK = 10,
        RANKLE = 11,
        RFOOT = 12,
        LHIP1 = 13,
        LHIP2 = 14,
        LTHIGH = 15,
        LSHANK = 16,
        LANKLE = 17,
        LFOOT = 18,
        DOF = 19
    };

    enum BLIND_MODE {
        GETUP_LIE,
        GETUP_DIVE,
        WALK_STRAIGHT
    };

    struct PerceptionInfo {
        float mJointsDegs[BioInterface::DOF];
        float mJointsSpeeds[BioInterface::DOF];
        float mTorsoAcc[3];
        float mTorsoGyr[3];
    };

    enum EFFECTOR_FLAG {
        DEG = 0,
        SPEED = 1,
        //     DEG_SPEED = 2
    };

    struct EffectorInfo {
        float mJointsDegs[BioInterface::DOF];
        float mJointsSpeeds[BioInterface::DOF];
        BioInterface::EFFECTOR_FLAG flag;
    };

    class IntfBioloid : public Singleton<IntfBioloid> {
    public:
        IntfBioloid();
        //   IntfBioloid(const IntfBioloid& orig);
        virtual ~IntfBioloid();
        void setPerceptionMode(const PerceptionInfo& p_Pcept);
        void setBlindMode(BioInterface::BLIND_MODE p_Mode);
        void getTargetJoints(EffectorInfo& p_Efct);
    private:
        void getTargetJointsDeg(EffectorInfo& p_Efct);
        void getTargetJointsSpeed(EffectorInfo& p_Efct);

    };
#define  IB BioInterface::IntfBioloid::GetSingleton()
}
#endif	/* INTFBIOLOID_H */

