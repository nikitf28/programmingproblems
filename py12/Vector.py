import math

class Vector():
    length = None
    angle = None
    x, y = None, None

    def __countLength__(self, *args):
        sum = 0
        for arg in args:
            sum += arg**2
        return math.sqrt(sum)

    def __countAngle__(self, x, l):
        return math.degrees(math.acos(x / l))

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.length = self.__countLength__(self.x, self.y)
        self.angle = self.__countAngle__(self.x, self.length)

    def getLength(self):
        return self.length

    def getAngle(self):
        return self.angle

    def sum(self, vector):
        return Vector(vector.x + self.x, vector.y + self.y)

    def add(self, vector):
        self.x += vector.x
        self.y += vector.y

    def sub(self, vector):
        return Vector(self.x - vector.x, self.y - vector.y)

    def ded(self, vector):
        self.x -= vector.x
        self.y -= vector.y

    def mul(self, vector):
        return self.x * vector.x + self.y * vector.y

    def __str__(self):
        return "(%s, %s)\nLength: %s\nAngle: %s" % (self.x, self.y, self.length, self.angle)


if __name__ == "__main__":
    v1 = Vector(3, 5)
    v2 = Vector(2, 6)
    print(v1, end="\n\n")
    print(v1.getLength(), end="\n\n")
    print(v1.getAngle(), end="\n\n")
    print(v1.sum(v2), end="\n\n")
    v1.add(v2)
    print(v1, end="\n\n")
    print(v1.sub(v2), end="\n\n")
    v1.ded(v2)
    print(v1, end="\n\n")
    print(v1.mul(v2), end="\n\n")