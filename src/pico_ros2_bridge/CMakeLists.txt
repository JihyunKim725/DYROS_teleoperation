cmake_minimum_required(VERSION 3.8)
project(pico_ros2_bridge)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

# nlohmann_json is usually header-only
find_package(nlohmann_json 3 REQUIRED)

add_executable(pico_bridge_node src/pico_bridge.cpp)
target_include_directories(pico_bridge_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(pico_bridge_node
  nlohmann_json::nlohmann_json
  ${rclcpp_LIBRARIES}
  ${geometry_msgs_LIBRARIES}
  ${visualization_msgs_LIBRARIES}
)
ament_target_dependencies(pico_bridge_node
  rclcpp
  geometry_msgs
  visualization_msgs
)

install(TARGETS pico_bridge_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
