import time
import win32api
import win32gui
import win32con
from winsound import Beep

info = '''
            [*] Pattern Generator for Recoil Control System
            
            [?] Como usar:
                1. Abra uma img do padrao do recoil.
                2. Ative o programa (F4).
                3. Clique nos pontos dos tiros.

            [~]F4 : Ativar | Desativar Rastreamento
            '''

def SaveConfig(recoil):
    i = 1
    with open('config.txt', 'w') as cfg:
        for cord in recoil:
            cfg.write(str(cord) + ',')
            i+=1
            if i%5==0:
                cfg.write('\n')
        cfg.close()
    print('[+] Config salva')


def MarkShot(x, y):
    dc = win32gui.GetDC(0)
    green = win32api.RGB(0, 255, 0)
    for i in range(0, 10):
        try:
            win32gui.SetPixel(dc, x - i, y, green)
            win32gui.SetPixel(dc,x + i, y, green)
            win32gui.SetPixel(dc, x, y - i, green)
            win32gui.SetPixel(dc, x , y+i, green)
        except Exception as err:
            print('[!] Fora dos limites da Tela:\n' + str(err))

def Tracking(compensation):

    track = False

    old_x = 0
    old_y = 0

    recoil = []

    while (True):

        if (win32api.GetAsyncKeyState(win32con.VK_F4)):
            track = not track
            if (track):
                print('\n[!] Lendo entradas do mouse')
                Beep(250, 300)
            else:
                print('\n[+] Leitura finalizada')
                SaveConfig(recoil)
                Beep(250, 300)
                break
            time.sleep(0.2)

        if (win32api.GetAsyncKeyState(win32con.VK_LBUTTON) and track):

            Beep(2000, 100)

            pos = win32api.GetCursorPos()

            MarkShot(pos[0], pos[1])

            if (old_x == 0 and old_y ==0):
                dx = 0
                dy = 0
                old_x = pos[0]
                old_y = pos[1]

            else:
                dx = ((pos[0] - old_x) + 1) * compensation
                dy = ((pos[1] - old_y) + 1) * compensation
                old_x = pos[0]
                old_y = pos[1]

            recoil.append((dx, dy))

            print('' + str(dx) + ' :: y: ' + str(dy))

            time.sleep(0.2)

        time.sleep(0.1)

def main():
    print(info)
    Tracking(1)

main()