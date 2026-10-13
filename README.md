# TerminalBPMTap

A tiny terminal tool that figures out the BPM of whatever you're tapping along to. That's it. That's the whole thing.

## What it does

You tap the spacebar to the beat of a song. It measures the time between your taps and shows you a running average BPM. Useful for when you're like "wait, what's the tempo of this track?" and don't want to leave the terminal.

## Usage

Build it with CMake, run the binary, and:

- **Space** - tap along to the beat
- **q** - quit

The first spacebar press starts the timer. Every press after that registers a tap and updates the average BPM on screen. It caps out at 100 taps, which is... probably enough.

## Building

```bash
cmake -B build
cmake --build build
```

Then run `TerminalBPMTap` from the build directory.

> **Note:** Uses `conio.h` (`_kbhit` / `_getch`), so this is Windows-only for now.

## Why

Needed to tap out a BPM quickly and didn't feel like opening a browser. So here we are.
