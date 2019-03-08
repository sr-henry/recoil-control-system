import win32api
import win32con
import winsound
import time

def rastreamento():

    print("Iniciando\n")

    fp = open("padrao.txt", "w")

    old_x = 0
    old_y = 0

    while(True):
        time.sleep(0.2)
        if (win32api.GetAsyncKeyState(win32con.VK_LBUTTON)):
            winsound.Beep(1800, 150)
            pos = win32api.GetCursorPos()
            if (old_x == 0 and old_y == 0):
                old_x = pos[0]
                old_y = pos[1]
                dx = 0
                dy = 0
            else:
                dx = int((pos[0] - old_x)+1)
                dy = int((pos[1] - old_y)+1)
                old_x = pos[0]
                old_y = pos[1]

            print("(" + str(dx) +","+str(dy)+"),")

            fp.write("(" + str(dx) +","+str(dy)+"),\n")
        
        if (not win32api.GetKeyState(win32con.VK_INSERT)):
            break

    fp.close()

    return True



print("insert para iniciar o rastreamento")

while(True):
    if (win32api.GetKeyState(win32con.VK_INSERT)):
        if (rastreamento()):
            break

print("fim")