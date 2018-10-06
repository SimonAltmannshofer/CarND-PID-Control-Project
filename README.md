### CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

This directory contains the following files:
- src folder: source and header files for the PID controller
- CMakeLists.txt, cmakepatch.txt: files for cmake
- README.md: this file, a readme

## Reflection

#Describe the effect each of the P, I, D components had in your implementation.

The P component steers the car back to the center of the lane, proportional to the lateral deviation (CTE). When P is set to high, the car oscillates around the center line. With even higher values, the car can get off the road.
The I component hat only a minor effect. Too high values lead to an oscillating behavior because the integral error can only be reduced by an error with the opposite sign.
The D component is proportional to the change/differentiation of the lateral deviation. High values for the D component prevent hugh steering angles.

# Describe how the final hyperparameters were chosen.

I tuned the final hyperparameters (P=0.1, I=0.00001, D=1.0) by hand. I started by setting I=D=0.0 and raised the P component until the car began to oscillate. Next, I raised the D component until the oscillations vanished. Last, I raised the I component but only until the car started to oscillate. The influence of the I component was neglectable.