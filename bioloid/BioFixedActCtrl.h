/* 
 * File:   BioFixedActCtrl.h
 * Author: allen
 *
 * Created on 2012年7月8日, 下午5:33
 */

#ifndef BIOFIXEDACTCTRL_H
#define	BIOFIXEDACTCTRL_H
#include<string>
#include"BioloidFixedActionData.h"

namespace BioCtrl{
  using  namespace std;
  using namespace BioData;
class BioFixedActCtrl {
public:
    BioFixedActCtrl();
  //  BioFixedActCtrl(const BioFixedActCtrl& orig);
    virtual ~BioFixedActCtrl();

    void getUpFromLieBlindDeg();
    void getUpFromDiveBlindDeg();
     void walkBlindDeg();

private:
    void performTaskBlindDeg(std::string p_FisrtTaskName );
    bool isLastTaskCompleted();
    int mRemainCycle;
    std::string mNowTaskName;
    std::string mNextTaskName;
    std::string mPreTaskName;
};
}

#endif	/* BIOFIXEDACTCTRL_H */

