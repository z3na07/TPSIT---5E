
import time
from machine import Pin
import dht

def leggi_temp(N_pin):

    # Initialize DHT11 sensor
    sensor = dht.DHT11(Pin(N_pin))

    try:
        sensor.measure()  # Measure temperature and humidity
        temp = sensor.temperature()  # Get temperature
        hum = sensor.humidity()  # Get humidity

        print("temperatura: %3.1f C" % temp)
        print(f"umidità: {hum: 3.1f} %")
    except OSError as e:
        print("Errore nella lettura del sensore DHT11: ", e)

    TEMP = temp
    UMID = hum

    return TEMP, UMID

    
def main():
    INTERVALLO = 7
    PIN = 4

    try:
        while True:
            temperatura, umidità = leggi_temp(PIN)
            print("Temperatura:" +  str(temperatura).encode('utf-8') + "C")
            print("Umidità:" +  str(umidità).encode('utf-8'))
            time.sleep(INTERVALLO)

    except KeyboardInterrupt:
        print("Stop misurazioni")
