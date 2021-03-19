import math

class Vector():
    length = None
    angle = None

    def __countLength__(self):
        #print(math.sqrt(self.__x**2 + self.__y**2))
        return math.sqrt(self.__x**2 + self.__y**2)

    def __countAngle__(self):
        return math.degrees(math.acos(self.__x / self.__length))

    def __init__(self, x, y):
        self.__x = x
        self.__y = y
        self.__length = self.__countLength__()
        self.__angle = self.__countAngle__()

    def getLength(self):
        return self.__length

    def getAngle(self):
        return self.__angle

    def sum(self, vector):
        return Vector(vector.__x + self.__x, vector.__y + self.__y)

    def add(self, vector):
        self.__x += vector.__x
        self.__y += vector.__y

    def sub(self, vector):
        return Vector(self.__x - vector.__x, self.__y - vector.__y)

    def ded(self, vector):
        self.__x -= vector.__x
        self.__y -= vector.__y

    def mul(self, vector):
        return Vector(self.__x * vector.__x, self.__y * vector.__y)

    def __str__(self):
        return "(%s, %s)\nLength: %s\nAngle: %s" % (self.__x, self.__y, self.__length, self.__angle)


v1 = Vector(3, 5)
v2 = Vector(2, 6)
print(v1)
print(v1.ge)
print(v1.sum(v2))
v1.add(v2)
print(v1)
print(v1.sub(v2))
v1.ded(v2)
print(v2)
print(v1.mul(v2))