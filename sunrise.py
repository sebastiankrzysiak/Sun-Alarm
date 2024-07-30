import tinytuya
from time import sleep

def set_up_device(device_id, local_key):
    """
    Set up the Tuya bulb device with given credentials.

    :param device_id: The ID of the Tuya device.
    :param ip_address: The IP address of the Tuya device.
    :param local_key: The local key for the Tuya device.
    :return: Initialized Tuya bulb device.
    """

    device = tinytuya.BulbDevice(device_id, "Auto", local_key)
    return device

def simulate_sunrise(device):
    """
    Simulate a sunrise effect on Tuya device.

    :param device: The Tuya device.
    """
    # Initial settings
    ORANGE = (255, 77, 0)
    YELLOW = (255, 247, 0)
    WHITE_1 = (32, 32)
    WHITE_2 = (255, 255)
    SLEEP_DURATION = 300  # 5 minutes

    try:
        device.turn_on()

        device.set_brightness(100)
        device.set_colourtemp(100)
        device.set_colour(*ORANGE)

        sleep(SLEEP_DURATION)

        device.set_brightness(255)
        device.set_colourtemp(255)

        sleep(SLEEP_DURATION)

        device.set_colour(*YELLOW)

        sleep(SLEEP_DURATION)

        device.set_white(*WHITE_1)

        sleep(SLEEP_DURATION)

        device.set_white(*WHITE_2)

    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == '__main__':
    DEVICE_ID = "INSERT YOUR DEVICE_ID HERE"
    LOCAL_KEY = "INSERT YOUR LOCAL_KEY HERE"

    light_bulb = set_up_device(DEVICE_ID, LOCAL_KEY)


    simulate_sunrise(light_bulb)