#include "pubsub/pubsub.h"


template<typename T>
pub_sub<T>::pub_sub(const std::string& topic_name_, const std::string& pub_sub_, int queue_size_) {
 if(pub_sub_ == "pub"){
    pub_ = nh_.advertise<T>(topic_name_, queue_size_);
 }else if(pub_sub_ == "sub"){
    sub_ = nh_.subscribe(topic_name_, queue_size_, &pub_sub<T>::callback, this);
 }
 
 //pub_ = nh_.advertise<std_msgs::Int32>(topic_name_, queue_size);
 //sub_ = nh_.subscribe("topic_ex1", 1000, &pub_sub::callback, this);
 // have to add -> data_type_ , data_value_
}


template<typename T>
void pub_sub<T>::publish(const T& msg) { 
 pub_.publish(msg);
}


template<typename T>
void pub_sub<T>::callback(const typename T::ConstPtr& msg) {
 buffer_=*msg;
}


template class pub_sub<std_msgs::Int32>;
template class pub_sub<std_msgs::String>;
template class pub_sub<std_msgs::Bool>;
