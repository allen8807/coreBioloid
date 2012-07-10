/* 
 * File:   BioFixedActCtrl.cpp
 * Author: allen
 * 
 * Created on 2012年7月8日, 下午5:33
 */

#include<map>
#include"math/Math.hpp"
#include "BioFixedActCtrl.h"
#include"BioloidCtrl.h"
#include "BioloidFixedActionData.h"

namespace BioCtrl {
    using namespace std;
    BioFixedActCtrl::BioFixedActCtrl() {
        mPreTaskName = "null";
        mNowTaskName = "null";
        mNextTaskName = "null";
        mRemainCycle = 0;
    }

    //    BioFixedActCtrl::BioFixedActCtrl(const BioFixedActCtrl& orig) {
    //    }

    BioFixedActCtrl::~BioFixedActCtrl() {
    }

    void BioFixedActCtrl::getUpFromDiveBlindDeg() {
        if (!isLastTaskCompleted()) {
            mRemainCycle = BIO_ROBOT.getActCtrl().performDeg();
            return;
        } else {
            if (mPreTaskName == "null") {
                performTaskBlindDeg("qianqi_zbl_1");
            } else {
                performTaskBlindDeg(mNowTaskName);
            }
        }
    }

    void BioFixedActCtrl::getUpFromLieBlindDeg() {
        if (!isLastTaskCompleted()) {
            mRemainCycle = BIO_ROBOT.getActCtrl().performDeg();
            return;
        } else {
            if (mPreTaskName == "null") {
                performTaskBlindDeg("houqi_zbl_1");
            } else {
                performTaskBlindDeg(mNowTaskName);
            }
        }
    }

    void BioFixedActCtrl::walkBlindDeg() {
        if (!isLastTaskCompleted()) {
            mRemainCycle = BIO_ROBOT.getActCtrl().performDeg();
            return;
        } else {
            if (mPreTaskName == "null") {
                performTaskBlindDeg("walk_zbl_1");
            } else {
                performTaskBlindDeg(mNowTaskName);
            }
        }
    }

    void BioFixedActCtrl::performTaskBlindDeg(std::string p_TaskName) {
        BioData::BioloidFixedActionData::TTaskMap::const_iterator iterTask = BFAD.getTaskMap().find(p_TaskName);
        mNowTaskName = p_TaskName;
        mNextTaskName = iterTask->second.next;
      //  float duration = iterTask->second.time;
        std::string poseName = iterTask->second.pose;
        std::string nowPoseName;
        
      //  BioData::BioloidFixedActionData::TPoseMap::const_iterator iterPose = BFAD.getPoseMap().find(poseName);
        if (mPreTaskName == "null") {
            nowPoseName = poseName;
        } else {
            nowPoseName = BFAD.getTaskMap().find(mPreTaskName)->second.pose;
        }
        mRemainCycle = std::ceil(iterTask->second.time / BIO_ROBOT.getTimeOfCycle());
        mRemainCycle = BIO_ROBOT.getActCtrl().ctrlByDeg(BFAD.getPoseMap().find(nowPoseName)->second,
                BFAD.getPoseMap().find(poseName)->second, mRemainCycle);
        mRemainCycle = BIO_ROBOT.getActCtrl().performDeg();
    }

    bool BioFixedActCtrl::isLastTaskCompleted() {
        if (mRemainCycle <= 0 && mNextTaskName == "null") {
            mPreTaskName = "null";
            mNowTaskName = "null";
            mNextTaskName = "null";
            return true;
        } else if (mRemainCycle <= 0 && mNextTaskName != "null") {
            mPreTaskName = mNowTaskName;
            mNowTaskName = mNextTaskName;
            return true;
        } else {
            return false;
        }
    }
}
