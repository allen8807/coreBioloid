/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on 2012年7月21日, 下午3:26
 */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include<iostream>
#include"bioloid/IntfBioloid.h"

using namespace std;
using namespace BioInterface;

pthread_mutex_t camera_mutex;
pthread_mutex_t posture_mutex;
pthread_t camera_tid;
pthread_t posture_tid;
pthread_t ctrl_tid;

float camera_info[2];
float posture_info[3];

void * cameraThread(void *pa) {
    int cycles = 10;
    while (cycles--) {
        struct timeval timeStart;
        gettimeofday(&timeStart, NULL);

        usleep(30000);
        struct timeval timeEnd;
        gettimeofday(&timeEnd, NULL);
        long timeCost = 1000000 * (timeEnd.tv_sec - timeStart.tv_sec)+(timeEnd.tv_usec - timeStart.tv_usec);
        long timeCostms = timeCost / 1000;
        printf("cameraThread cost %ld ms %ld us\n", timeCostms, timeCost);
        /*
         *以下操作camera交互数据
         *
         */
        pthread_mutex_lock(&camera_mutex);
        camera_info[0] = 0.0f;
        camera_info[1] = 0.0f;
        pthread_mutex_unlock(&camera_mutex);
    }

}

void * postureThread(void *pa) {
    int cycles = 10;
    while (cycles--) {
        struct timeval timeStart;
        gettimeofday(&timeStart, NULL);

        usleep(50000);
        struct timeval timeEnd;
        gettimeofday(&timeEnd, NULL);

        long timeCost = 1000000 * (timeEnd.tv_sec - timeStart.tv_sec)+(timeEnd.tv_usec - timeStart.tv_usec);
        long timeCostms = timeCost / 1000;
        printf("postureThread cost %ld ms %ld us\n", timeCostms, timeCost);
        /*
         *以下操作陀螺仪交互数据
         *
         */
        pthread_mutex_lock(&posture_mutex);
        posture_info[0] = 0.0f;
        posture_info[1] = 0.0f;
        posture_info[2] = 0.0f;
        pthread_mutex_unlock(&posture_mutex);


    }

}

void *ctrlThread(void* pa) {
    int cycles = 10;
    IB.setTimeOfCycle(0.02f); 
    while (cycles--) {
        struct timeval timeStart;
        gettimeofday(&timeStart, NULL);

        float cameraInfo[2] = {0.0f, 0.0f};
        float postureInfo[3] = {0.0f, 0.0f, 0.0f};

        /*
         *以下操作camera交互数据
         *
         */
        pthread_mutex_lock(&camera_mutex);
        cameraInfo[0] = camera_info[0];
        cameraInfo[1] = camera_info[1];
        pthread_mutex_unlock(&camera_mutex);
        /*
         *以下操作陀螺仪交互数据
         *
         */
        pthread_mutex_lock(&posture_mutex);
        postureInfo[0] = posture_info[0];
        postureInfo[1] = posture_info[1];
        postureInfo[2] = posture_info[2];
        pthread_mutex_unlock(&posture_mutex);
        //以下为控制主程序


        IB.setBlindMode(BioInterface::GETUP_DIVE);
        BioInterface::EffectorInfo efI;
        IB.getTargetJoints(efI);
        cout << "mDeg:\n";
        for (int i = 0; i < BioInterface::DOF; i++) {
            cout << efI.mJointsDegs[i] << " ";
        }
        cout << endl;
        usleep(20000);
        struct timeval timeEnd;
        gettimeofday(&timeEnd, NULL);
        long timeCost = 1000000 * (timeEnd.tv_sec - timeStart.tv_sec)+(timeEnd.tv_usec - timeStart.tv_usec);
        long timeCostms = timeCost / 1000;
        printf("ctrlThread cost %ld ms %ld us\n", timeCostms, timeCost);
    }
}

void runMultiplyThread(void) {
    int temp;
    memset(&camera_tid, 0, sizeof (pthread_t));
    memset(&posture_tid, 0, sizeof (pthread_t));
    memset(&ctrl_tid, 0, sizeof (pthread_t));
    /*创建线程*/
    if ((temp = pthread_create(&camera_tid,
            NULL,
            cameraThread,
            NULL)) != 0) //comment2
    {
        printf("线程camera创建失败!\n");
    } else {
        printf("线程camera被创建\n");
    }
    if ((temp = pthread_create(&posture_tid,
            NULL,
            postureThread,
            NULL)) != 0) //comment2
    {
        printf("线程posture创建失败!\n");
    } else {
        printf("线程posture被创建\n");
    }
    if ((temp = pthread_create(&ctrl_tid,
            NULL,
            ctrlThread,
            NULL)) != 0) //comment2
    {
        printf("线程control创建失败!\n");
    } else {
        printf("线程control被创建\n");
    }

    if (camera_tid != 0) { //comment4
        pthread_join(camera_tid, NULL);
        printf("线程camera已经结束\n");
    }
    if (posture_tid != 0) { //comment5
        pthread_join(posture_tid, NULL);
        printf("线程posture已经结束\n");
    }
    if (posture_tid != 0) { //comment5
        pthread_join(ctrl_tid, NULL);
        printf("线程ctrl_tid已经结束\n");
    }
}

int main() {
    /*用默认属性初始化互斥锁*/
    pthread_mutex_init(&camera_mutex, NULL);
    pthread_mutex_init(&posture_mutex, NULL);

    runMultiplyThread();


    return 0;
}
