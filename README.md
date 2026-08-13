# ball-simulation-falling
# Code Description: Console Bouncing Ball Simulation
# Overall Concept
This program implements a physical simulation of a bouncing ball in a console window with visualization of its trajectory. The ball moves under the influence of gravity, bounces off the "floor" with energy loss, until it completely stops.

Data Structure
Ball Structure
c
typedef struct Ball { 
    float y;          // Current ball height
    float speed;      // Current velocity (positive - up, negative - down)
    float gravity;    // Gravitational acceleration (9.8 m/s²)
    int is_moving;    // Movement flag (1 - moving, 0 - stopped)
} Ball;

#Main Functions
1. main() - Entry Point
Allocates memory for the Ball structure

#Initializes ball parameters:

Height: 5.0 units

Speed: 0

Gravity: 9.8

Starts the main simulation loop

Clears console on each frame (system("cls"))

Updates physics and displays the ball

10ms delay between frames

2. update_ball() - Physics Update
Updates velocity: speed = speed - gravity * 0.02

Updates position: y = y + speed * 0.02

Handles floor collision (y <= 0):

Clamps ball to y = 0

Reduces velocity on bounce (coefficient -0.5)

Stops the ball when velocity threshold (±0.1) is reached

Outputs debug information about ball state

3. print() - Visualization
Creates an a x b rectangular area (16 x 48)

Draws borders using '#' characters

Displays the ball as '@' at the position corresponding to height y

Uses horizontal centering (half = b/2)

How It Works
Motion Physics:

Ball starts falling from height 5 units

Accelerates downward under gravity

Undergoes inelastic collision with the floor

Visualization:

Console is cleared before each frame

A 16x48 character "screen" is created

Borders marked with '#', ball marked with '@'

Stopping:

Ball loses energy on each bounce

When velocity drops below threshold (0.1), motion stops

Implementation Features
Dynamic memory allocation

Physical simulation with discrete time steps

Simple text-based graphics

Windows-specific functions (system, Sleep)

Limitations and Possible Improvements
Using system("cls") is inefficient and insecure

No user input handling

Hardcoded display parameters

No vertical bounds checking
