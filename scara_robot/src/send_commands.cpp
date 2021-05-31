#include<ros/ros.h>
#include<std_msgs/Float64.h>
#include<iostream>

using namespace std;

int main(int argv,char **argc){
    ros::init(argv,argc,"send_commands");
    ros::NodeHandle n;

    ros::Publisher joint1_publisher= n.advertise<std_msgs::Float64>("/joint1_position_controller/command",100);
    ros::Publisher joint2_publisher= n.advertise<std_msgs::Float64>("/joint2_position_controller/command",100);
    ros::Publisher joint3_publisher= n.advertise<std_msgs::Float64>("/joint3_position_controller/command",100);
    ros::Publisher joint4_publisher= n.advertise<std_msgs::Float64>("/joint4_position_controller/command",100);

    ros::Rate rate(0.5);

    while(ros::ok()){
    std_msgs::Float64 theta1,theta2,theta3,theta4;

    float a,b,c,d;
    cout<<"Enter values of joints between -pi to pi"<<endl;
    cin>>theta1.data>>theta2.data>>theta3.data>>theta4.data;


    joint1_publisher.publish(theta1);
    joint2_publisher.publish(theta2);
    joint3_publisher.publish(theta3);
    joint4_publisher.publish(theta4);   

    ros::spin();

    rate.sleep();

    }
    

    return 0;
}