/***************************************************************************
 *                              SEU RoboCup Simulation Team
 *                     -------------------------------------------------
 * Copyright (c) Southeast University , Nanjing, China.
 * All rights reserved.
 *
 * $Id$
 *
 ****************************************************************************/
/**
 * @file   main.cpp
 * @author Xu Yuan <xuyuan.cn@gmail.com.cn>
 * @date   Fri Mar 21 21:47:50 2008
 *
 * @brief  the main entrance of the seu-spark-agent program
 *
 *
 */

#include<iostream>
#include"bioloid/IntfBioloid.h"

using namespace std;
using namespace BioInterface;
int main(int argc, char* argv[])
{
    IB.GetSingleton();
    int cycle = 1;
    while(cycle>0){
 //       cout <<"1"<<endl;
    IB.setBlindMode(BioInterface::GETUP_DIVE);
  //  cout <<"2"<<endl;
    BioInterface::EffectorInfo efI;
  //  cout <<"3"<<endl;
    IB.getTargetJoints(efI);
    cout << "mDeg:\n";
    for (int i = 0; i < BioInterface::DOF; i++) {
        cout << efI.mJointsDegs[i] << " ";
    }
    cout<<endl;
    cycle--;
    }
char a;
cout<<"press any key"<<endl; 
cin>>a;
return 0;
}
