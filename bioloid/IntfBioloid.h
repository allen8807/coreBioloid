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

    //Without Sensor Mode

    enum BLIND_MODE {
        GETUP_LIE,
        GETUP_DIVE,
        WALK_STRAIGHT
    };

    //用于传感器信息传递的结构体

    struct PerceptionInfo {
        float mJointsDegs[BioInterface::DOF]; //各关节的位置信息
        float mJointsSpeeds[BioInterface::DOF]; //各关节的速度信息
        float mTorsoAcc[3]; //加速度计的值
        float mTorsoGyr[3]; //陀螺仪的值
        float mTorsoPosture[3];//获得的身体姿态
        float mCameraSlope;
        float mCameraOffset;
    };
    
    //控制器控制的模式

    enum EFFECTOR_MODE {
        DEG = 0,               //只有目标角度控制的信息
        DEG_SPEED = 1,        //有角度和速度的控制信息
    };
    //用于控制器信息传出的值

    struct EffectorInfo {
        float mJointsDegs[BioInterface::DOF];  //目标角度的控制信息
        float mJointsSpeeds[BioInterface::DOF];//目标速度的控制信息
        BioInterface::EFFECTOR_MODE mMode;  // 控制模式
    };
/**
 *IntfBioloid
 * 该类为Bioloid模块的接口类，用于读入传感器信息和输出控制命令
 *
 *
 */
    class IntfBioloid : public Singleton<IntfBioloid> {
    public:
        IntfBioloid();
        virtual ~IntfBioloid();
        void setPerceptionMode(const PerceptionInfo& p_Pcept);
        void setBlindMode(BioInterface::BLIND_MODE p_Mode);
        void getTargetJoints(EffectorInfo& p_Efct);
        void setTimeOfCycle(float p_timeOfCycle);
    private:
        void getTargetJointsDeg(EffectorInfo& p_Efct);
        void getTargetJointsSpeed(EffectorInfo& p_Efct);

    };
#define  IB BioInterface::IntfBioloid::GetSingleton()
}
#endif	/* INTFBIOLOID_H */

