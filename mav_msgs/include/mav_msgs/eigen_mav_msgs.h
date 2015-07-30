/*
 * Copyright 2015 Fadri Furrer, ASL, ETH Zurich, Switzerland
 * Copyright 2015 Michael Burri, ASL, ETH Zurich, Switzerland
 * Copyright 2015 Markus Achtelik, ASL, ETH Zurich, Switzerland
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MAV_MSGS_EIGEN_MAV_MSGS_H
#define MAV_MSGS_EIGEN_MAV_MSGS_H

#include <Eigen/Eigen>

namespace mav_msgs {

struct EigenAttitudeThrust {
  EigenAttitudeThrust()
      : attitude(1.0, 0.0, 0.0, 0.0),
        thrust(0.0) {};
  EigenAttitudeThrust(const Eigen::Quaterniond& _attitude,
                      double _thrust) {
    attitude = _attitude;
    thrust = _thrust;
  }

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  Eigen::Quaterniond attitude;
  double thrust;
};

struct EigenActuator {
  //TODO(ffurrer): Find a proper way of initializing :)

  EigenActuator(const Eigen::VectorXd& _angular_velocities) {
    angular_velocities = _angular_velocities;
  };

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  Eigen::VectorXd angular_velocities; // In RPM in the case of props.
};

struct EigenRateThrust {
  EigenRateThrust()
      : angular_rates(0.0, 0.0, 0.0),
        thrust(0.0) {};

  EigenRateThrust(const Eigen::Vector3d& _angular_rates, double _thrust) {
    angular_rates = _angular_rates;
    thrust = _thrust;
  };

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  Eigen::Vector3d angular_rates;
  double thrust;
};

struct EigenRollPitchYawrateThrust {
  EigenRollPitchYawrateThrust()
      : roll(0.0),
        pitch(0.0),
        yaw_rate(0.0),
        thrust(0.0) {};

  EigenRollPitchYawrateThrust(double _roll,
                              double _pitch,
                              double _yaw_rate,
                              double _thrust)
      : roll(_roll),
        pitch(_pitch),
        yaw_rate(_yaw_rate),
        thrust(_thrust) {};

  double roll;
  double pitch;
  double yaw_rate;
  double thrust;
};

struct EigenTrajectoryPoint {
  EigenTrajectoryPoint()
      : time_from_start_ns(0),
        position(0.0, 0.0, 0.0),
        velocity(0.0, 0.0, 0.0),
        acceleration(0.0, 0.0, 0.0),
        jerk(0.0, 0.0, 0.0),
        snap(0.0, 0.0, 0.0),
        yaw(0.0),
        yaw_rate(0.0) {};

  EigenTrajectoryPoint(int64_t _time_from_start_ns,
                       const Eigen::Vector3d& _position,
                       const Eigen::Vector3d& _velocity,
                       const Eigen::Vector3d& _acceleration,
                       const Eigen::Vector3d& _jerk,
                       const Eigen::Vector3d& _snap,
                       double _yaw,
                       double _yaw_rate)
      : time_from_start_ns(_time_from_start_ns),
        position(_position),
        velocity(_velocity),
        acceleration(_acceleration),
        jerk(_jerk),
        snap(_snap),
        yaw(_yaw),
        yaw_rate(_yaw_rate) {};

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  int64_t time_from_start_ns;
  Eigen::Vector3d position;
  Eigen::Vector3d velocity;
  Eigen::Vector3d acceleration;
  Eigen::Vector3d jerk;
  Eigen::Vector3d snap;
  double yaw;
  double yaw_rate;
};

struct EigenOdometry {
  EigenOdometry()
      : timestamp_ns(-1),
        position(0.0, 0.0, 0.0),
        orientation(Eigen::Quaterniond::Identity()),
        velocity(0.0, 0.0, 0.0),
        angular_velocity(0.0, 0.0, 0.0) {
  }

  EigenOdometry(const Eigen::Vector3d& _position, const Eigen::Quaterniond& _orientation,
                const Eigen::Vector3d& _velocity, const Eigen::Vector3d& _angular_velocity)
      : position(_position),
        orientation(_orientation),
        velocity(_velocity),
        angular_velocity(_angular_velocity) {}

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  int64_t timestamp_ns; // Time since epoch, negative value = invalid timestamp.
  Eigen::Vector3d position;
  Eigen::Quaterniond orientation;
  Eigen::Vector3d velocity;  // Velocity in expressed in the Body frame!
  Eigen::Vector3d angular_velocity;
};

}

#endif // MAV_MSGS_EIGEN_MAV_MSGS_H
