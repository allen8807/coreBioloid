/* 
 * File:   BioloidFixedActionData.h
 * Author: allen
 *
 * Created on 2012年7月7日, 下午11:04
 */

#ifndef BIOLOIDFIXEDACTIONDATA_H
#define	BIOLOIDFIXEDACTIONDATA_H
#include<string>
#include<map>
#include "Singleton.hpp"
#include "BioloidJointsData.h"

namespace BioData {
    using namespace std;
    // using namespace math;

    class BioloidFixedActionData : public Singleton<BioloidFixedActionData> {
    public:

        /** an angle step means to desired angle and needed time */
        struct BioFixedTask {
            std::string pose; // desired pose
            float time; // move in given time
            bool changeable; // can be changed by other tasks?
            int adjustFoot; // can adjust foot? which?
            std::string next; // next task name
            bool changeFoot; // will the foot changed in next task?
        };
        typedef std::map<std::string, BioFixedTask> TTaskMap;
        typedef std::map<std::string, BioData::BioloidJointsData> TPoseMap;

        BioloidFixedActionData();
        void init();
        ~BioloidFixedActionData();
               const TTaskMap& getTaskMap() const{
            return mTaskMap;
        }

       const TPoseMap& getPoseMap() const{
           return mPoseMap;
       }
       
    protected:
        bool loadConfigFile(const std::string& filename, std::map<std::string, BioFixedTask>& map);
        bool loadConfigFile(const std::string& filename, std::map<std::string, BioData::BioloidJointsData>& map);
        void writeToPoseMap(std::istream &p_Stream, BioData::BioloidJointsData& p_BJD);
        BioData::BioloidJointsData::HJ_ID getIDByHJName(const string& p_Name);
        //   BioloidFixedActionData(const BioloidFixedActionData& orig);
        bool loadConfigString(const std::string& p_String, std::map<std::string, BioFixedTask>& map);
        bool loadConfigString(const std::string& p_String, std::map<std::string, BioData::BioloidJointsData>& map);

    private:
        /** fixed angles */
        TTaskMap mTaskMap;
        TPoseMap mPoseMap;
    };
    std::ostream & operator<<(std::ostream &p_Stream, BioloidFixedActionData::BioFixedTask& p_Task);
    std::istream & operator>>(std::istream &p_Stream, BioloidFixedActionData::BioFixedTask& p_Task);

#define BFAD BioData::BioloidFixedActionData::GetSingleton()
}/* namespace BioData */

#endif	/* BIOLOIDFIXEDACTIONDATA_H */

