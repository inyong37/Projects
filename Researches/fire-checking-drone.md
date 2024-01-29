### Fire Checking Drone using Computer Vision

This project is a system that, when a fire is detected by a fire detection sensor, a drone goes to the location, checks the image to see if there is fire, and returns to the original location. The drone calcuates its position by the strength of the signals of the bluetooth beacons to recognize its position. Calculate its position using triangulation. (It is an indoor environment, but the test site is open, so I used the method because it was free from the multipath propagation phenomenon. After that, I developed a fingerprint method using deep learning as a future work of localization). Considering the processing power, it is designed to determine that a fire has occurred when the pixels have a fire color(color gamut of flame is detected among the colors in the image).