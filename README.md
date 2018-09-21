# mqtt_valvula
Primer paso para automatizar el riego del jardin. Se arma un circuito para abrir o cerrar la valvula segun el comando que se le envie al NodeMcu por MQTT.

![alt text](https://raw.githubusercontent.com/gsampallo/mqtt_valvula/master/mqtt_valvula.png "Esquematico")

En la carpeta python hay tres archivos:
- abrirValvula.py Envia el comando para abrir la valvula
- cierraValvula.py Envia el comando para cerrar la valvula
- monitorearJardin.py Monitorea todos los mensajes que publica el dispositivo

Video sobre como funciona y breve explicacion:

[![Video](https://img.youtube.com/vi/z-T6LeM2Og4/0.jpg)](https://www.youtube.com/watch?v=z-T6LeM2Og4)
