/* 
 * File:   BioloidPerception.h
 * Author: allen
 *
 * Created on 2012年7月8日, 上午10:06
 */

#ifndef BIOLOIDPERCEPTION_H
#define	BIOLOIDPERCEPTION_H
#include"math/Math.hpp"
#include"BioloidJointsData.h"

namespace BioPcept{
    using namespace BioData;
    using namespace math;
class BioloidPerception {
public:
    BioloidPerception();
  //  BioloidPerception(const BioloidPerception& orig);
    virtual ~BioloidPerception();
    void setRawJoints(const BioData::BioloidJointsData & p_Joints );
    
protected:

    void predictJoints();

private:
   BioData::BioloidJointsData mRawJoints;
   BioData::BioloidJointsData mPredictJoints;
   math::Vector3f mTorsoAcc;
   math::Vector3f mTorsoGyr;
   float mTimeOfCycle;
};
}/*namespace BioPcept*/

#endif	/* BIOLOIDPERCEPTION_H */

