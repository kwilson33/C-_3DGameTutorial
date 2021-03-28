# C++_3DGameTutorial
Following this [tutorial series](https://www.youtube.com/watch?v=ssGka-bSTvQ&amp;list=PLv8DnRaQOs5-ST_VDqgbbMRtzMtpK36Hy&amp;index=1) from YouTuber PardCode 

## Day 1: 3/27/21 
[C++ 3D Game Tutorial 1: Creating a Window with Win32 API](https://www.youtube.com/watch?v=ssGka-bSTvQ&list=PLv8DnRaQOs5-ST_VDqgbbMRtzMtpK36Hy&index=1)
* Created Window base class.
* Created AppWindow child class.
* Wrote low-level C++ code to initialize and create a window using the WNDCLASSEX structure.
* Created a function that returns a callback function. Returns NULL on creation or destruction of window (after doing creation/deletion stuff), and DefWindowProc() otherwise.
* This window receives messages from the OS and handles them until there are no messages left from the OS.
* Instantiated an AppWindow object in main.cpp, and this window exists until you close it.
