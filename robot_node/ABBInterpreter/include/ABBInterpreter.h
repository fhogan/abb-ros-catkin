#ifndef ABBINTERPRETER_H
#define ABBINTERPRETER_H

#include <string>
#include "math.h"
#include <cstdio>


using namespace std;

/** \class namespace
    \brief ABB server interpreter.
    Collection of methods to format and parse messages between PC and server running in ABB controller.
*/
namespace ABBInterpreter
{
  string pingRobot(int idCode=0);
  string setCartesian(double x, double y, double z, double q0, double qx, double qy, double qz, int idCode=0);
  string setCartesianJ(double x, double y, double z, double q0, double qx, double qy, double qz, int idCode=0);
  string setCartesianA(double x, double y, double z, double q0, double qx, double qy, double qz, double ang, int idCode=0);
  string setJoints(double joint1, double joint2, double joint3, double joint4, double joint5, double joint6, double joint7, int idCode=0);
  string getIK(double x, double y, double z, double q0, double qx, double qy, double qz, double robotAngle, int idCode=0);
  string getFK(double j1, double j2, double j3, double j4, double j5, double j6, double joint7, int idCode=0);
  string getRobotAngle(int idCode=0);
  string getCartesian(int idCode=0);
  string getJoints(int idCode=0);
  string setTool(double x, double y, double z, double q0, double qx, double qy, double qz, int idCode=0);
  string setInertia(double m, double cgx, double cgy, double cgz, double ix, double iy, double iz, int idCode=0);
  string setWorkObject(double x, double y, double z, double q0, double qx, double qy, double qz, int idCode=0);
  string setSpeed(double tcp, double ori, int idCode=0);
  string setAcc(double acc, double deacc, int idCode=0);
  string setZone(bool fine=0, double tcp_mm = 5.0, double ori_mm = 5.0, double ori_deg = 1.0, int idCode=0);
  string setMotionSupervision(double sup = 90, int idCode=0);
  string closeConnection(int idCode=0);
  // Buffers
  // TCP Pose
  string addBuffer(double x, double y, double z, double q0, double qx, double qy, double qz, double handpose, int idCode=0);
  string clearBuffer(int idCode=0);
  string executeBuffer(bool simultaneous, bool useHandPose, int idCode=0);
  string lenBuffer(int idCode=0);
  // Joint Configuration
  string addJointPosBuffer(double q1, double q2, double q3, double q4, double q5, double q6, double q7, int idCode=0);
  string clearJointPosBuffer(int idCode=0);
  string executeJointPosBuffer(bool simultaneous, int idCode=0);
  // Hand
  string handJogIn(int idCode=0);
  string handJogOut(int idCode=0);
  string handStop(int idCode=0);
  string handCalibrate(int idCode=0);
  string handGripIn(double handForce, int idCode=0);
  string handGripOut(double handForce, int idCode=0);
  string handOnBlow(int idCode=0);
  string handOffBlow(int idCode=0);
  string handOnVacuum(int idCode=0);
  string handOffVacuum(int idCode=0);
  string handSetSpeed(double handSpeed, int idCode=0);
  string handSetForce(double handForce, int idCode=0);
  string handMoveTo(double handPose, int idCode=0);
  string handGetPose(int idCode=0);
  string handGetPressure(int idCode=0);
  string handIsCalibrated(int idCode=0);
  // RRI
  string connectRRI(int idCode=0);
  string closeRRI(int idCode=0);
  // CSS
  string actCSS(int refFrame, double refOrient_q0, double refOrient_qx, double refOrient_qy, double refOrient_qz,
                int softDir, double stiffness, double stiffnessNonSoftDir, int allowMove, double ramp, int idCode=0);
  string deactCSS(double x, double y, double z, double q0, double qx, double qy, double qz, int idCode=0);
  // EGM
  string actEGM(int idCode=0);

  string iosignal(int output_num, int signal, int idCode=0);

  int parseCartesian(string msg, double *x, double *y, double *z,
      double *q0, double *qx, double *qy, double *qz);
  int parseJoints(string msg, double *joint1, double *joint2,
      double *joint3, double *joint4, double *joint5, double *joint6, double *joint7);
  int parseIK(string msg, double *joint1, double *joint2,
      double *joint3, double *joint4, double *joint5, double *joint6, double *joint7, double *errorNum);
  int parseHandValue(string msg, double *value);
}
#endif
