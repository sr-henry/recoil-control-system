import win32api
import win32con
import time

ak = [(0,0),
(-1,29),
(1,38),
(2,51),
(10,54),
(16,60),
(13,47),
(-1,36),
(-30,25),
(-32,11),
(-36,7),
(-22,6),
(-24,7),
(-12,1),
(10,6),
(37,7),
(36,11),
(54,9),
(39,2),
(24,-6),
(7,-2),
(-3,7),
(-1,9),
(3,6),
(8,6),
(-6,4),
(-24,-2),
(-53,-12),
(-59,-16),
(-54,-14)
]

rpm = 600

reloadtime = 2.5

shot = 0

def multiplicador(dpi, sensi):
    m = (900*1.5)/(dpi*sensi)
    return m

def delay(rpm):
    rps = rpm/60
    ms = 1000/rps
    return ms/1000

t = delay(rpm)

mult = multiplicador(900, 1)

while (True):
    while (win32api.GetAsyncKeyState(win32con.VK_LBUTTON) and shot < len(ak)):
        win32api.mouse_event(win32con.MOUSEEVENTF_MOVE, int(ak[shot][0] * mult), int(ak[shot][1] * mult), 0, 0)
        time.sleep(t)
        shot += 1
    if (shot == len(ak)):
        time.sleep(reloadtime)
    shot = 0

