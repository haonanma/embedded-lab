import serial

with serial.serial_for_url("loop://", timeout=1) as s:
    s.write(b"hello pyserial\n")
    print(s.readline().decode().strip())
