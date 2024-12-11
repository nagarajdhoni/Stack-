# Stack Application Using Templates - README

## Overview
A C++ stack application supporting multiple data types (int, char, float, double, string) with a user-friendly menu system for stack operations.

## Features
- **Data Types Supported**: int, char, float, double, string.
- **Operations**: Push, Pop, Display Stack, Exit.
- **Error Handling**: Stack overflow, underflow, and invalid input with up to 3 retry attempts.

## Requirements
- C++11 or later.

## Usage
1. **Run the program** and select a data type.
2. **Choose operations**: Push, Pop, Display, or Exit.
3. After 3 invalid inputs, the program will prompt warnings and terminate after multiple failed attempts.

## Code Structure
- **Stack Class**: Manages stack operations.
- **Main Menu**: Handles user interaction.
- **Error Handling**: Ensures valid inputs and retries.
