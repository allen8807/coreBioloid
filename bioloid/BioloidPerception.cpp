/* 
 * File:   BioloidPerception.cpp
 * Author: allen
 * 
 * Created on 2012年7月8日, 上午10:06
 */

#include "BioloidPerception.h"
namespace BioPcept {

    BioloidPerception::BioloidPerception()
    : mTimeOfCycle(0.02f) {
        for (int i = 0; i < STATE_NUM; i++) {
            mStateDuration[i] = 0;
        }
    }

    //BioloidPerception::BioloidPerception(const BioloidPerception& orig) {
    //}

    BioloidPerception::~BioloidPerception() {
    }

    void BioloidPerception::setRawJoints(const BioData::BioloidJointsData & p_Joints) {
        mRawJoints = p_Joints;
    }

    void BioloidPerception::predictJoints() {
        for (int i = BioloidJointsData::NECK; i < BioloidJointsData::DOF; i++) {
            mPredictJoints.getJointsData()[i].mDeg =
                    mRawJoints.getJointsData()[i].mDeg + mRawJoints.getJointsData()[i].mSpeed*mTimeOfCycle;
            mPredictJoints.getJointsData()[i].mSpeed = mRawJoints.getJointsData()[i].mSpeed;
        }
    }

    void BioloidPerception::update() {
        //需要有关节角度和速度信息
        //predictJoints();

        cout << "Posture x:" << mTorsoPosture.x() << " y:" << mTorsoPosture.y() <<
                " z:" << mTorsoPosture.z() << endl;
        if (mTorsoPosture.y()<-9) {
            cout << "[BalanceState] LIED" << endl;
            mNowBalanceState = LIED_STATE;
        } else if (mTorsoPosture.y() > 9) {
            cout << "[BalanceState] DIVED" << endl;
            mNowBalanceState = DIVED_STATE;
        } else {
            cout << "[BalanceState] BALANCE" << endl;
            mNowBalanceState = BALANCE_STATE;
        }
    }

    void BioloidPerception::upadteState() {
        cout << "Posture x:" << mTorsoPosture.x() << " y:" << mTorsoPosture.y() <<
                " z:" << mTorsoPosture.z() << endl;
        if (mTorsoPosture.y()<-9) {
            cout << "[BalanceState] LIED" << endl;
            upadteStateDuration(LIED_STATE);
        } else if (mTorsoPosture.y() > 9) {
            cout << "[BalanceState] DIVED" << endl;
            upadteStateDuration(DIVED_STATE);
        } else {
            cout << "[BalanceState] BALANCE" << endl;
            upadteStateDuration(BALANCE_STATE);
        }
        BalanceState resState = BALANCE_STATE;
        //状态持续时间最长的才要切换
        for (int i = 0; i < STATE_NUM; i++) {
            if (mStateDuration[i] > mStateDuration[resState]) {
                resState = (BalanceState) i;
            }
        }
        mNowBalanceState = resState;
        cout << "[BalanceState actual ] " << mNowBalanceState << endl;
    }

    void BioloidPerception::upadteStateDuration(BalanceState p_state) {
        //状态持续1s为最大值
        int maxDuration = (int) (1 / mTimeOfCycle);
        int minDuration = 0;

        mStateDuration[p_state] = mStateDuration[p_state] + 2;
        for (int i = 0; i < STATE_NUM; i++) {
            mStateDuration[i] = mStateDuration[i] - 1;
            if (mStateDuration[i] > maxDuration) {
                mStateDuration[i] = maxDuration;
            }
            if (mStateDuration[i] < minDuration) {
                mStateDuration[i] = minDuration;
            }
        }
    }

}/*namespace BioPcept*/

