/* 
 * File:   BioloidPerception.cpp
 * Author: allen
 * 
 * Created on 2012年7月8日, 上午10:06
 */

#include "BioloidPerception.h"
namespace BioPcept{
BioloidPerception::BioloidPerception()
:mTimeOfCycle(0.02f)
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

void BioloidPerception::update(){
    predictJoints();
    cout<<"Acc.y:"<<mTorsoPosture.y()<<endl;
    if(mTorsoPosture.y()<-9){
        mNowBalanceState = LIED_STATE;
    }else if(mTorsoPosture.y()>9){
        mNowBalanceState = DIVED_STATE;
    }else{
        mNowBalanceState =  BALANCE_STATE;
    }
}

}/*namespace BioPcept*/

