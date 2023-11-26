from matplotlib import pyplot as plt
from matplotlib import rcParams
import serial
import time 
if __name__ == "__main__":
    arduinoData = serial.Serial('COM4', 1200)
    print("connected to: ", arduinoData.portstr)    
    
    #plt.ion()
    fig = plt.figure()
    ax = fig.add_subplot(111)
    
    voltage = [0]
    rt = [0]
    timer = [0]
    temp = [0]

    li, = ax.plot(timer, temp)
    ax.set_xlabel('time [s]')
    ax.set_ylabel('temperature [C]')
    rcParams['font.family'] = "Futura PT"
    rcParams['font.weight'] = "book"

    fig.canvas.draw()
    plt.pause(0.1)
    plt.show(block = False)

    started = False
    
    while started != True:
        datalist = arduinoData.readline().decode()
        started = datalist[0:6] == 'start\n'
        # print(datalist[0:6], datalist[0:6] == 'start\n')

    while started == True:
        try:
            # arduinoData.flushInput()
            # arduinoData.flushOutput()
            datalist = arduinoData.readline().decode().split("\t")
            print(datalist)
            voltage.append(float(datalist[0]))
            rt.append(float(datalist[1]))
            temp.append(float(datalist[2]))
            timer.append(float(datalist[3]))
            # print(voltage)
            # print(rt)
            # print(temp)
            # print(timer)
            ax.relim() 
            ax.autoscale_view(True,True,True) 
            
            li.set_xdata(timer)
            li.set_ydata(temp)

            fig.canvas.draw()
            plt.pause(0.05)

        except IndexError or ValueError:
            voltage.append(0)
            rt.append(0)
            temp.append(0)
            timer.append(timer[-1] + 1)
        
        except KeyboardInterrupt:
            plt.close('all')
            break


