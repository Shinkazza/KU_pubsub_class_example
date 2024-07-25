#include "pubsub/pubsub.h"


int main(int argc, char **argv) {
 ros::init(argc, argv, "pub_sub_node");  //node name = custom//
  ////////////////////////CUSTOM/////////////////////////////
 pub_sub<std_msgs::Int32> pub_sub_obj1("topic_ex1","pub",1000);
 pub_sub<std_msgs::String> pub_sub_obj2("topic_ex2","pub",1000);
 pub_sub<std_msgs::String> pub_sub_obj3("topic_ex3","pub",1000);
 pub_sub<std_msgs::Int32> pub_sub_obj4("topic_ex1","sub",1000);
 pub_sub<std_msgs::String> pub_sub_obj5("topic_ex3","sub",1000);
 ////////////////////////CUSTOM/////////////////////////////


 // pub_sub<[data_type]> [objectname]("[topicname]",[pub or sub],[queue size])
 ros::Rate loop_rate(10);


 while (ros::ok()) {




   ////////////////////////CUSTOM/////////////////////////////
   std_msgs::Int32 msg1;
   msg1.data =42;
   pub_sub_obj1.publish(msg1);
   std_msgs::String msg2;
   msg2.data ="2312";
   pub_sub_obj2.publish(msg2);
   std_msgs::String msg3;
   msg3.data = "hi";
   pub_sub_obj3.publish(msg3);
   cout << "Int : " << pub_sub_obj4.buffer_.data << endl;
   cout << "String : " << pub_sub_obj5.buffer_.data << endl;
   ////////////////////////CUSTOM/////////////////////////////




  
   ros::spinOnce();
   loop_rate.sleep();
 }


 return 0;
}
