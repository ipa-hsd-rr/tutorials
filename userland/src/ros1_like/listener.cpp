// Copyright 2014 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <memory>

// #include "ros/ros.h"
#include <rclcpp/rclcpp.hpp>

// #include "std_msgs/String.h"
#include <simple_msgs/String.h>

// void chatterCallback(const std_msgs::String::ConstPtr& msg)
void chatterCallback(const simple_msgs::String::ConstPtr &msg)
{
  // ROS_INFO("I heard: [%s]", msg->data.c_str());
  std::cout << "I heard: [" << msg->data << "]" << std::endl;
  // std::cout << "I heard: [" << msg.data << "]" << std::endl;
}

int main(int argc, char *argv[])
{
  // ros::init(argc, argv, "listener");
  rclcpp::init(argc, argv);
  // ros::NodeHandle n;
  auto node = rclcpp::Node::make_shared("listener");

  // ros::Subscriber sub = n.subscribe("chatter", 7, chatterCallback);
  auto sub = node->create_subscription<simple_msgs::String>("chatter", 7, chatterCallback);

  // ros::spin();
  rclcpp::spin(node);

  return 0;
}
