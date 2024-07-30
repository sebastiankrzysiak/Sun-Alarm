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

if __name__ == '__main__':
    DEVICE_ID = "INSERT YOUR DEVICE_ID HERE"
    LOCAL_KEY = "INSERT YOUR LOCAL_KEY HERE"

    light_bulb = set_up_device(DEVICE_ID, LOCAL_KEY)

    light_bulb.turn_off()