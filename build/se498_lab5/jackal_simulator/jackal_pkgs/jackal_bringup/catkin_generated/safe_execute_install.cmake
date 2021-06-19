execute_process(COMMAND "/home/user/catkin_ws/build/se498_lab5/jackal_simulator/jackal_pkgs/jackal_bringup/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/user/catkin_ws/build/se498_lab5/jackal_simulator/jackal_pkgs/jackal_bringup/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
