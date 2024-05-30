import matplotlib.pyplot as plt
import numpy as np

# Inicializar la figura de matplotlib
fig, ax = plt.subplots()
bar_labels = ['Ax', 'Ay', 'Az', 'Gx', 'Gy', 'Gz']
bars = ax.bar(bar_labels, [0, 0, 0, 0, 0, 0])
ax.set_ylim(-180, 180)  # Configurar el rango de grados para la inclinación

def update_graph(sensor_data):
    """
    Actualiza el gráfico de barras con los datos del sensor.

    Parameters:
    sensor_data (tuple): Una tupla que contiene seis valores (ax, ay, az, gx, gy, gz).
    """
    for bar, value in zip(bars, sensor_data):
        bar.set_height(value)
    plt.draw()
    plt.pause(0.001)  # Pausa breve para actualizar la gráfica

# Ejemplo de uso:
# sensor_data = (20, -16, -77, -71, 17, 48)
# update_graph(sensor_data)
