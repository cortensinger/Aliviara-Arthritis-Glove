# Aliviara-Arthritis-Glove

Final Prototype:
![alt text](https://github.com/cortensinger/Aliviara-Arthritis-Glove/blob/master/IMG_8217.JPG)

For a visual overview of the project, see https://github.com/cortensinger/Aliviara-Arthritis-Glove/blob/master/Science%20project.pdf


This project won First Place at the Hack For Humanity hackathon, which was a weekend-long session of invention and design dedicated to improving the life of those suffering from Rheumatoid Arthritis (RA). Please reference the PDF of our powerpoint presentation for the project submission for further detail and photos.

Our final prototype was a smart wearable glove intended to help alleviate (or "aliviar" in Spanish, hence alivaRA) joint poin associated with RA. On the glove are 5 flex sensors (one per finger) whose values feed into a Bluetooth LE enabled microcontroller, which sends this finger data in real time to an iOS application. This application provides theraputic finger-movement exercises to the user and it receives the finger data from the glove, which it uses to determine whether the user was able to execute the proposed exercise. If the user was restricted by their RA symptoms from successfully carrying-out the exercise, the application sends a message to the glove's BLE MCU, which enables 3 coin motors to vibrate and massage the nearby joint-muscles. This vibration not only loosens up these injured muscles, but it exploits the Gate Theory of Pain by overriding signals sent to the brain from pain-receptive neurons. We tried to Hack the Nervous System in order to reduce the pain associated with RA.

Users can also switch between Massage Mode (only vibration, no exercises) and Exercise mode. On top of this, the applicaiton sends the finger information to a Heroku server in the cloud, which performs complex data analysis to determine which finger exercises are the most difficult to execute. This information is stored and can be automatically sent to an email of your choosing (potentially a physical therapist).
