### Nodes

odroid@odroid:~/catkin_ws$ rosnode list
/keyboard
/pocketsphinx_recognizer
/rosout
/rosserial_server
/rostopic_22756_1587964518214
/rqt_gui_py_node_22622

odroid@odroid:~/catkin_ws$ rosnode info keyboard
--------------------------------------------------------------------------------
Node [/keyboard]
Publications: 
 * /cmdArm [uri_soft_arduino_msgs/ArmAngles]
 * /cmdVel [uri_soft_arduino_msgs/DesiredVelocity]
 * /rosout [rosgraph_msgs/Log]

Subscriptions: None

Services: 
 * /keyboard/get_loggers
 * /keyboard/set_logger_level


contacting node http://odroid:43109/ ...
Pid: 21790
Connections:
 * topic: /rosout
    * to: /rosout
    * direction: outbound
    * transport: TCPROS
 * topic: /cmdVel
    * to: /rosserial_server
    * direction: outbound
    * transport: TCPROS
 * topic: /cmdVel
    * to: /rostopic_22756_1587964518214
    * direction: outbound
    * transport: TCPROS
 * topic: /cmdArm
    * to: /rosserial_server
    * direction: outbound
    * transport: TCPROS

odroid@odroid:~/catkin_ws$ rosnode info phocketsphinx_recognizer
--------------------------------------------------------------------------------
Node [/phocketsphinx_recognizer]
Publications: None

Subscriptions: None

Services: None

cannot contact [/phocketsphinx_recognizer]: unknown node

odroid@odroid:~/catkin_ws$ rosnode info rosserial_server
--------------------------------------------------------------------------------
Node [/rosserial_server]
Publications: 
 * /arm_angles [uri_soft_arduino_msgs/ArmAngles]
 * /odometry [uri_soft_arduino_msgs/Odometry]
 * /rosout [rosgraph_msgs/Log]
 * /usa_debug [uri_soft_arduino_msgs/Odometry]

Subscriptions: 
 * /cmdArm [uri_soft_arduino_msgs/ArmAngles]
 * /cmdVel [uri_soft_arduino_msgs/DesiredVelocity]

Services: 
 * /rosserial_server/get_loggers
 * /rosserial_server/set_logger_level


contacting node http://odroid:35811/ ...
Pid: 21791
Connections:
 * topic: /rosout
    * to: /rosout
    * direction: outbound
    * transport: TCPROS
 * topic: /cmdVel
    * to: /keyboard (http://odroid:43109/)
    * direction: inbound
    * transport: TCPROS
 * topic: /cmdArm
    * to: /keyboard (http://odroid:43109/)
    * direction: inbound
    * transport: TCPROS

odroid@odroid:~/catkin_ws$ rosnode info rosout
--------------------------------------------------------------------------------
Node [/rosout]
Publications: 
 * /rosout_agg [rosgraph_msgs/Log]

Subscriptions: 
 * /rosout [rosgraph_msgs/Log]

Services: 
 * /rosout/get_loggers
 * /rosout/set_logger_level


contacting node http://odroid:35687/ ...
Pid: 21750
Connections:
 * topic: /rosout
    * to: /keyboard (http://odroid:43109/)
    * direction: inbound
    * transport: TCPROS
 * topic: /rosout
    * to: /rosserial_server (http://odroid:35811/)
    * direction: inbound
    * transport: TCPROS
 * topic: /rosout
    * to: /pocketsphinx_recognizer (http://odroid:46641/)
    * direction: inbound
    * transport: TCPROS
 * topic: /rosout
    * to: /rqt_gui_py_node_22622 (http://odroid:44515/)
    * direction: inbound
    * transport: TCPROS

### Topics

odroid@odroid:~/catkin_ws$ rostopic list
/arm_angles
/cmdArm
/cmdVel
/odometry
/pocketsphinx_recognizer/output
/rosout
/rosout_agg
/statistics
/usa_debug

#### topic cmdVel (command velocity)
odroid@odroid:~/catkin_ws$ rostopic info cmdVel
Type: uri_soft_arduino_msgs/DesiredVelocity

Publishers: 
 * /keyboard (http://odroid:43109/)

Subscribers: 
 * /rosserial_server (http://odroid:35811/)


#### topic cmdArm (arm commands)
odroid@odroid:~/catkin_ws$ rostopic info cmdArm
Type: uri_soft_arduino_msgs/ArmAngles

Publishers: 
 * /keyboard (http://odroid:43109/)

Subscribers: 
 * /rosserial_server (http://odroid:35811/)

#### topic pocketsphinx (voice recognition)
odroid@odroid:~/catkin_ws$ rostopic info pocketsphinx_recognizer/output
Type: std_msgs/String

Publishers: 
 * /pocketsphinx_recognizer (http://odroid:46641/)

Subscribers: None

