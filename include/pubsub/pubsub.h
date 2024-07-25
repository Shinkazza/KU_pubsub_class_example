#ifndef PUBSUB
#define PUBSUB
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Bool.h"


using namespace std;


template<typename T>
class pub_sub {
public:
 pub_sub(const std::string& topic_name_,const std::string& pub_sub_, int queue_size_);
 void publish(const T& msg);
 void callback(const typename T::ConstPtr& msg);
  ros::NodeHandle nh_;
 ros::Publisher pub_;
 ros::Subscriber sub_;
 T buffer_;
};
#endif
