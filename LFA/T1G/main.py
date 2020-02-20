from graphics import *
from random import randint


def setup():
    screen = GraphWin('LFA T1', 700, 700)
    screen.setBackground('yellow')
    return screen


RADIUS = 20


def drawNodes():
    screen = setup()
    # Get and draw three vertices of triangle
    old_point = None
    with open("input.in", "r") as f:
        while(True):
            center = screen.getMouse()
            line = None
            if old_point != None:
                line = Line(old_point, center)
                line.setArrow("last")
                line.draw(screen)
            old_point = center
            c = Circle(center, RADIUS)
            message = Text(Point(center.x, center.y +
                                 RADIUS + 20), f.readline())
            message.draw(screen)
            message.setSize(10)
            c.setFill(color_rgb(randint(0, 256),
                                randint(0, 256), randint(0, 256)))
            c.draw(screen)
            line.draw(screen)

    screen.getMouse()
    screen.close()


drawNodes()
