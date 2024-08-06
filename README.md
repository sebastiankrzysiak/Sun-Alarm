# Sunrise Alarm

## Introduction

The Sunrise Alarm is a project I created that uses the Tuya Smart Light Bulb to simulate a natural sunrise. By gradually increasing the brightness of the light bulb using the Tuya Cloud API, it provides a gentle wake-up experience in the morning. This project is ideal for individuals who find it difficult to wake up with traditional alarms or who prefer a more serene way to begin their day.

## Tuya Cloud API Setup

This project utilizes the [**TinyTuya**](https://github.com/jasonacox/tinytuya) Python library to communicate with the Tuya Cloud API. In order to connect with your Tuya Smart Light Bulb, you simply need to acquire your Device ID and Local Key. The following steps will summarize how to obtain these values, but it is strongly advised to refer to the official [**documentation**](https://github.com/jasonacox/tinytuya?tab=readme-ov-file#tinytuya) for detailed instructions.

1. Download the Tuya Smart app on your mobile device, create an account, and add your Tuya Smart Light Bulb
2. Create a virtual Python environment using either [**venv**](https://www.freecodecamp.org/news/how-to-setup-virtual-environments-in-python/) or [**conda**](https://www.geeksforgeeks.org/set-up-virtual-environment-for-python-using-anaconda/)
3. Create a [**Tuya Developer Account**](https://github.com/jasonacox/tinytuya) and create a cloud project following these [**instructions**](https://github.com/jasonacox/tinytuya/files/12836816/Tuya.IoT.API.Setup.v2.pdf)
4. Install the TinyTuya library using `pip install tinytuya`
5. Run the `python -m tinytuya wizard` to create a `devices.json` file
    - Locate the [**API Key and API Secret**](https://platform.tuya.com/cloud/basic)
    - Locate the Device ID either by running `python -m tinytuya scan` or clicking "Devices" on your [**project page**](https://platform.tuya.com/cloud/basic)
    - Answer "no" for all yes/no questions
6. Locate the Device ID and Local Key in the `devices.json` file
    - id: **xxxxxx**
    - key: **xxxxxx**

## Code Setup

In this section, we will set up the code to run the Sunrise Alarm project.

1. Clone the project from [**Github**](https://github.com/sebastiankrzysiak/Sun-Alarm)
2. Open the `sunrise.py` and `turnoff.py` files and replace the `DEVICE_ID` and `LOCAL_KEY` with the ones you obtained from the TinyTuya

## Running the Code

1. Run `gcc -o sunalarm sunalarm.c` and then `./sunalarm`
2. Insert the time you want the alarm to be set off in the given prompt
    - Example: **Enter the time for the alarm (HH MM AM/PM): 9 00 AM**
