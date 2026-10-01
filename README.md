# box

**box** is a small, Windows-native command-line toolbox inspired by Unix utilities.

It provides a collection of lightweight command-line tools in a single executable.

> **Note:** box is a Windows-only project. It relies on the Windows API and is designed specifically for the Windows platform.

## Features

- Native Windows implementation
- Windows API based
- Unicode-aware command-line arguments
- UTF-8 output support
- Single executable
- Lightweight and simple
- Unix-like command interface
- No external runtime dependencies

## Build

### Requirements

- GCC
- GNU Make
- A C11-compatible compiler
- Windows-compatible build environment

For Windows, **MSYS2 UCRT64** is recommended.

Build the project with:

    make

To remove build files:

    make clean

## Usage

    box <command> [arguments...]

Use `box help` to see the available commands.

## Design

box aims to remain small, simple, and understandable.

The project is designed specifically for Windows and uses Windows APIs for filesystem, console, and system operations where appropriate.

Command-line arguments are handled through `wmain()` and wide-character Windows APIs for proper Unicode support.

Source files are automatically discovered by the Makefile, so adding a new command does not require modifying the build configuration.

## License

box is licensed under the **GNU General Public License v3.0**.

See the `LICENSE` file for the complete license text.

Copyright (C) 2026 Samet Bilir