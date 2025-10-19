import serial
import pyvjoy
import time


vjoy_device = pyvjoy.VJoyDevice(1)

port = "COM7"

ser = serial.Serial(port, 115200, timeout=1)

buttons = ['a', 'b', 'x', 'y', 'l', 'r', 'up', 'down', 'left', 'right']
axes = ['x_axis', 'y_axis','x_axis2','y_axis2']
button_state = {button: False for button in buttons}

while True:
    ser.reset_input_buffer()

    data = ser.readline().decode(errors="ignore").strip()
    ser.flush()

    print(data)

    if data:
        states = data.split(";")

        if len(states) == len(buttons) + len(axes):
            try:
                for i, button in enumerate(buttons):
                    button_state[button] = (int(states[i]) == 1)
                    vjoy_device.set_button(i + 1, button_state[button])

                x_val = int(states[-2])
                y_val = int(states[-1])

                x_vjoy = int((x_val / 1023) * 32767)
                y_vjoy = int((y_val / 1023) * 32767)

                vjoy_device.set_axis(pyvjoy.HID_USAGE_X, x_vjoy)
                vjoy_device.set_axis(pyvjoy.HID_USAGE_Y, y_vjoy)

            except ValueError as e:
                print(f"Error processing data: {e}")
        else:
            print(f"Incorrect number of values (expected {len(buttons) + len(axes)}, got {len(states)})")
    else:
        print(f"Incomplete data: {data}")

    time.sleep(0.05)
