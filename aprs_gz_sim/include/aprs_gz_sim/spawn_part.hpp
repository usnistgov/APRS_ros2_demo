#include <aprs_interfaces/srv/spawn_part.hpp>
#include <aprs_interfaces/srv/spawn_sensor.hpp>

#include <gflags/gflags.h>

#include <gz/msgs/boolean.pb.h>
#include <gz/msgs/entity.pb.h>
#include <gz/msgs/entity_factory.pb.h>
#include <gz/msgs/stringmsg_v.pb.h>

#include <sstream>
#include <string>
#include <cmath>
#include <fstream>

#include <gz/math/Pose3.hh>
#include <gz/msgs/Utility.hh>
#include <gz/transport/Node.hh>

#include <rclcpp/rclcpp.hpp>

class SpawnPart : public rclcpp::Node
{
    public:
        SpawnPart();

    private:
        rclcpp::Service<aprs_interfaces::srv::SpawnPart>::SharedPtr spawn_part_srv_;
        rclcpp::Service<aprs_interfaces::srv::SpawnSensor>::SharedPtr spawn_sensor_srv_;

        gz::transport::Node gz_node;

        int part_count = 0;
        int sensor_count = 0;

        void spawn_part_cb_(const std::shared_ptr<aprs_interfaces::srv::SpawnPart::Request> request,
                            std::shared_ptr<aprs_interfaces::srv::SpawnPart::Response> response);
        void spawn_sensor_cb_(const std::shared_ptr<aprs_interfaces::srv::SpawnSensor::Request> request,
                            std::shared_ptr<aprs_interfaces::srv::SpawnSensor::Response> response);
        
        std::vector<float> get_rpy_from_quaternion(float, float, float, float);
};