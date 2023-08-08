# winmp3 - Single-header MP3 Player for Windows

`winmp3` is a lightweight and user-friendly single-header MP3 player designed for Windows programs. `winmp3` allows you to play MP3 files and control playback features such as play, pause, stop, speed, and volume.

## Features

- Simple and intuitive interface
- Play, pause, and stop MP3 files
- Adjust playback speed and volume

## Installation

Simply include the `winmp3.hpp` header file in your project to start using `winmp3`.

## Example

```cpp
#include "winmp3.hpp" // Change this to wherever the library is located

int main() {
    const char* mp3_file = "D:/x/electric.mp3";
    winmp3 player;
    player.load_file(mp3_file);
    player.set_volume(0.8f); // Set volume to 80%
    player.set_speed(1.0f); // Normal speed
    player.play();
    Sleep(5000); // Play for 5 seconds
    player.pause();
    Sleep(2000); // Pause for 2 seconds
    player.set_speed(2.0f); // Double the speed
    player.play();
    Sleep(5000); // Play for 5 seconds at double speed
    player.stop();
    return 0;
}
```
