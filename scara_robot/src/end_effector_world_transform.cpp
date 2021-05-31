#include<ros/ros.h>
#include<tf/transform_listener.h>
#include<iostream>

using namespace std;

int main(int argv,char **argc){
    ros::init(argv,argc,"end_effector_pose_listner");
    ros::NodeHandle n;

    tf::TransformListener listner;
    
    ros::Rate rate(0.5);

    while(n.ok()){
        tf::StampedTransform transform;
        try{
            listner.lookupTransform("/base_link","/link_04",ros::Time(0),transform);
        }
        catch(tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
        }
        double x,y,z;
        x=transform.getOrigin().x();
        y=transform.getOrigin().y();
        z=transform.getOrigin().z();

        cout<<"End Effector is at point " <<x<<" "<<y<<" "<<z<<" "<<endl;

        rate.sleep();
    }
    return 0;
}