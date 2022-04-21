# 1. Given series of line segments and a rectangular clipping window, clip the line against the clipping window using Sutherland-Cohen line clipping algorithm.


import math
import sys

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *


def init():
    glClearColor(0.0, 0.0, 0.0, 0.0)
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0)


def glutFunct():
    glutInit(sys.argv)


glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
glutInitWindowSize(500, 500)
glutInitWindowPosition(0, 0)
glutCreateWindow("Clipping Algorithms")

init()


def drawClippingWindow(xWin0, xWinMax, yWin0, yWinMax):

    edges = [[0, 1], [1, 2], [2, 3], [3, 0]]
    points = [[xWin0, yWin0], [xWinMax, yWin0], [xWinMax, yWinMax], [xWin0, yWinMax]]
    rgb = (1.0, 1.0, 1.0)
    drawLines(edges, points, rgb)


def getClippingWindowSize():
    print("Enter the clipping window size")
    xWin0 = float(input("Enter the minimum window value of x : "))
    xWinMax = float(input("Enter the maximum window value of x : "))
    yWin0 = float(input("Enter the minimum window value of y : "))
    yWinMax = float(input("Enter the maximum window value of y : "))
    return xWin0, xWinMax, yWin0, yWinMax


def drawLines(edges, points, rgb):
    glColor3f(rgb[0], rgb[1], rgb[2])
    for e in edges:
        for v in e:
            glVertex2fv(points[v])


def getLine():
    x1 = float(input("Enter the initial x coordinate value : "))
    x2 = float(input("Enter the final x coordinate value : "))
    y1 = float(input("Enter the initial y coordinate value : "))
    y2 = float(input("Enter the final y coordinate value : "))
    return x1, x2, y1, y2


def drawGivenLine(x1, x2, y1, y2):
    edges = [[0, 1]]
    points = [[x1, y1], [x2, y2]]
    rgb = [0.0, 0.0, 1.0]
    drawLines(edges, points, rgb)


INSIDE = 0
LEFT = 1
RIGHT = 2
DOWN = 4
TOP = 8
