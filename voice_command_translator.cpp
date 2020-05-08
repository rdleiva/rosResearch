// works with three commmands but needs improvement
// voice translator node receives string messages from pocketsphinx
// voice command topic and translates it into a velocity command message


#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Char.h"

#include "uri_soft_arduino_msgs/DesiredVelocity.h"
#include "uri_soft_arduino_msgs/ArmAngles.h"

#include <istream>
#include <math.h>
#include <string>

#include <unistd.h>
#include <termios.h>

char command = 0;

// function to process the string messages and turn them into keyboard commands.
void vcTranslator(const std_msgs::String& msg){
    std::string mess = msg.data.c_str();
    if(mess == "forward "){
        command = 'w';
    }
    else if (mess == "backward "){
        command = 's';
    }
    else if (mess == "stop stop "){
        command  = 'p';
    }
    else command = 0;
}

int main(int argc, char **argv)
{
    // node initialization
    ros::init(argc, argv, "voiceTranslator");

    ros::NodeHandle n;

    // receiving voice command strings from pocketsphinx publisher voiceCommand
    ros::Subscriber sub = n.subscribe("voiceCommand", 1000, vcTranslator);

    ros::Publisher chatter_pub = n.advertise<uri_soft_arduino_msgs::DesiredVelocity>("cmdVel", 10);
    ros::Publisher arm_cmd_pub = n.advertise<uri_soft_arduino_msgs::ArmAngles>("cmdArm", 10);

    uri_soft_arduino_msgs::DesiredVelocity msg;
    msg.lvel = 0.0;
    msg.avel = 0.0;
    msg.seq = 0;
    msg.time = 0.0;

    uri_soft_arduino_msgs::ArmAngles msg_arm;
    msg_arm.j1 = 60;
    msg_arm.j2 = 100;
    msg_arm.j3 = 95;
    msg_arm.j4 = 50;

    // ros::Rate loop_rate(10);
    sleep(10);
    
    // publishing the velocity commands
    chatter_pub.publish(msg);
    arm_cmd_pub.publish(msg_arm);

    ros::spinOnce();
  
    char c = 0;
    bool keepspinning = true;

    std::cout << " Say a command! (e.g. forward)"<< std::endl; 

    while (keepspinning && ros::ok())
    {
        c = command;
        switch (c){
            case 'w': {     //forward
	            msg.lvel += 0.025;
	            break;
            }
            case 's': {     //backwards
                msg.lvel -= 0.025;
                break;
            }
            case 'p': {     //stop
                msg.lvel = 0.0;
                msg.avel = 0.0;
                break;
            }

            default: break;
        }
        // limiting the speed fo the motors
        if (msg.lvel>0.05) msg.lvel = 0.05;
        if (msg.lvel<-0.05) msg.lvel = -0.05;
        if (msg.avel>0.05) msg.avel = 0.05;
        if (msg.avel<-0.05) msg.avel = -0.05;

        chatter_pub.publish(msg);
        arm_cmd_pub.publish(msg_arm);
        ros::spinOnce();
        ++msg.seq;
    }

    return 0;
}
