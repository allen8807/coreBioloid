/* 
 * File:   BioloidPerception.cpp
 * Author: allen
 * 
 * Created on 2012年7月8日, 上午10:06
 */

#include "BioloidPerception.h"
namespace BioPcept{
BioloidPerception::BioloidPerception()
:mTimeOfCycle(0.1f)
{

}

//BioloidPerception::BioloidPerception(const BioloidPerception& orig) {
//}




BioloidPerception::~BioloidPerception() {
}

void BioloidPerception::setRawJoints(const BioData::BioloidJointsData & p_Joints ){
 mRawJoints = p_Joints;
}

void BioloidPerception::predictJoints(){
      for (int i = BioloidJointsData::NECK ; i < BioloidJointsData::DOF ; i++) {
            mPredictJoints.getJointsData()[i].mDeg =
                    mRawJoints.getJointsData()[i].mDeg+mRawJoints.getJointsData()[i].mSpeed*mTimeOfCycle;
            mPredictJoints.getJointsData()[i].mSpeed =mRawJoints.getJointsData()[i].mSpeed;
        }
}

}/*namespace BioPcept*/

