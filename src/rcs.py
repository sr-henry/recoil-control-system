import time
import win32api
import win32con

ak47 = {
    "name": 'ak47',
    "rpm": 600,
    "rt": 2.5,
    "recoil":[(0,0),(-1,27),(1,38),(2,49),(10,55),
              (15,60),(13,49),(0,37),(-23,21),(-38,10),
              (-35,7),(-23,9),(-23,6),(-12,1),(7,8),
              (32,5),(44,13),(45,5),(41,5),(30,-7),
              (8,-2),(-3,8),(-4,6),(4,10),(6,6),
              (-2,3),(-27,-4),(-51,-10),(-58,-14),(-57,-16)]
}

m4a4 = {
    "name": 'm4a4',
    "rpm": 666,
    "rt": 3.1,
    "recoil": [(0,0),(1,21),(-2,27),(-3,34),(-1,38),
               (-1,47),(8,46),(20,32),(24,30),(15,21),
               (-2,11),(-27,9),(-46,1),(-44,0),(-36,-1),
               (-19,1),(-8,4),(-9,3),(0,4),(16,1),
               (32,5),(36,8),(41,4),(26,7),(15,3),
               (5,4),(3,9),(6,6),(8,5),(7,1)]
}

def CalculateMult(dpi, sensi):
    return (900*1.5)/(dpi*sensi)

def CalculateDelay(rpm):
    rps = rpm/60
    ms = 1000.0/rps
    return  ms/1000

def ControlSystem(weapon, mult):
    print('rcs is on | weapon : ' + weapon["name"])
    delay = CalculateDelay(weapon["rpm"])
    shot = 0

    while True:

        if win32api.GetAsyncKeyState(win32con.VK_HOME):
            print('rcs is off')
            break

        while win32api.GetAsyncKeyState(win32con.VK_LBUTTON) and shot < len(weapon["recoil"]):
            win32api.mouse_event(win32con.MOUSEEVENTF_MOVE, int(weapon["recoil"][shot][0] * mult),
                                 int(weapon["recoil"][shot][1] * mult), 0, 0)
            time.sleep(delay)
            shot += 1
        shot = 0

def main():
    dpi = 900
    sensi = 1
    mult = CalculateMult(dpi, sensi)

    while True:
        if win32api.GetAsyncKeyState(win32con.VK_NUMPAD1):
            ControlSystem(ak47, mult)
        elif win32api.GetAsyncKeyState(win32con.VK_NUMPAD2):
            ControlSystem(m4a4, mult)


main()