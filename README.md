# TECHIN515-Lab3-SortingHat

## Brief Documentation of Implementation
This project implements a "Sorting Hat" system using an ESP32 microcontroller, an OLED display,
four physical buttons, and a lightweight decision tree model for inference. When powered on, the
OLED displays a series of ten personality-based questions with four answer options each (A-D).
The user selects an answer by pressing the corresponding button, and their choices are saved to an
array.
Once all ten questions are answered, the embedded model classifies the responses and predicts a
Hogwarts house: Gryffindor, Hufflepuff, Ravenclaw, or Slytherin. The result is shown on the
OLED and also printed over serial.

## Demo Video
[Click here to watch the demo](https://youtu.be/sTxRABxBnkQ)

## Hardware Used
- ESP32 Dev Board
- SSD1306 OLED Display (I2C, 128x64)
- 4 Momentary Push Buttons
- Jumper Wires + Breadboard

## Software & ML
- Arduino IDE
- Libraries: `Adafruit_SSD1306`, `Adafruit_GFX`
- Manually constructed decision tree in `sorting_hat_model.h`
- Dataset in `Sorting_Dataset.csv`

## Implementation Process
1. Wired OLED to ESP32 using I2C (SDA: GPIO 21, SCL: GPIO 22)
2. Wired buttons to GPIO 14, 27, 26, 25 (INPUT_PULLUP)
3. Wrote code in Arduino to:
   - Display questions/answers
   - Record button input
   - Call ML model to classify house
   - Show result on OLED and Serial
4. Resolved issues with screen not displaying, pin mismatches, debounce delay
5. Uploaded code and tested functionality

## Project Files
- `sorting_hat_esp_button_64_width.ino` — main Arduino code
- `sorting_hat_model.h` — decision tree model
- `Sorting_Dataset.csv` — simulated dataset
- `Lab 3 Report.pdf` — detailed writeup

## Discussion 
## - Are all 10 questions necessary?  
- Not necessarily. While having 10 questions helps balance the house prediction, some of them are
quite similar in the kind of personality trait they capture. To streamline the user experience, I would
consider removing the following:
- • Q7. Preferred pet: This is mostly symbolic and doesn’t significantly reflect personality.
- • Q9. What kind of friends do you like: This overlaps with Q1 (values) and Q5 (how friends
describe you).
- • Q6. What to do with a mystery book: Interesting, but less impactful than others like Q4 or
- Q8. Reducing the quiz to 7 core questions would make it more enjoyable and faster to complete,
especially for first-time users.

## How would I improve the system?
- Improve model accuracy and efficiency:
- Currently, the decision tree is hand-coded and quite simplistic. To improve accuracy:
    - ▪ Train a real model using scikit-learn on a larger dataset of user responses and real labels.
    - ▪ Use quantized models (e.g., TFLite) for faster inference on embedded systems.
    - ▪ Add confidence thresholds to avoid "guessing" too early.
- Add sensors or enhance UX:
    - ▪ Voice input using a microphone and wake-word detection (like “Sorting Hat, begin!”).
    - ▪ Add vibration motor or speaker for haptic or sound feedback after sorting.
    - ▪ Use a proximity or capacitive touch sensor to start the quiz when a hand approaches
(no need for a power/reset button).
- Is decision tree still suitable?
For the current setup (discrete inputs, small input space), the decision tree is ideal: fast, small
memory footprint, easy to deploy.
But if we add voice, gesture recognition, or sensor fusion, then:
    - ▪ A decision tree won’t capture complex patterns well.
    - ▪ I would switch to a small neural network, such as a quantized TFLite model with 1- 2 dense
layers.
- This way, we keep performance real-time while allowing more expressive input types.
---

