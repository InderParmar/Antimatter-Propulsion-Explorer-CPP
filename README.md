# AntimatterPropulsionExplorer

## Overview
AntimatterPropulsionExplorer is a cutting-edge scientific simulation project developed for the SEP101 course, focusing on the feasibility of antimatter-driven spacecraft. This project delves into the theoretical underpinnings of using antimatter as propulsion fuel, exploring the dynamics of cargo vessels, starships, and warbirds in space travel.

## Objectives
- **Simulate Antimatter Propulsion**: Model the interactions between matter and antimatter to generate propulsion energy.
- **Spacecraft Design**: Explore the components necessary for the operation of different types of spacecraft.
- **Performance Analysis**: Evaluate the kinetic energy and fuel requirements for various spacecraft velocities.

## Features
- **Diverse Spacecraft Models**: Includes models for cargo vessels, starships, and warbirds, each with unique specifications.
- **Dynamic Propulsion Simulation**: Utilizes Einstein's E=mc² to calculate energy from matter/anti-matter annihilation.
- **Comprehensive Component Design**: Features detailed subsystems including payload, propulsion, and weapons systems.

## Getting Started
To run the AntimatterPropulsionExplorer simulation, clone the repository and compile the source files using a C++ compiler.

```bash
git clone https://github.com/yourusername/AntimatterPropulsionExplorer.git
cd AntimatterPropulsionExplorer
g++ -o simulation Main.cpp CargoShip.cpp Starship.cpp Warbird.cpp Systems.cpp
./simulation
