from smbus import SMBus
 
addr = 0x04            
bus = SMBus(1)
bus.write_byte(addr, 0x01)
input ("Press return to exit")
bus.write_byte(addr, 0x00)
