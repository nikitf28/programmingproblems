import math

from Vector import Vector

class d3Vector(Vector):
    z = None
    angle, angleX, angleY, angleZ = None, None, None, None

    def __init__(self, x, y, z):
        self.z = z
        super().__init__(x, y)
        self.length = super().__countLength__(self.x, self.y, self.z)
        self.angleX = super().__countAngle__(self.x, self.length)
        self.angleY = super().__countAngle__(self.y, self.length)
        self.angleZ = super().__countAngle__(self.z, self.length)
        self.angle = None

    def getAngleX(self):
        return self.angleX

    def getAngleY(self):
        return self.angleY

    def getAngleZ(self):
        return self.angleZ

    def getAngle(self):
        return None

    def sum(self, vector):
        return d3Vector(vector.x + self.x, vector.y + self.y, vector.z + self.z)

    def add(self, vector):
        super().add(vector)
        self.z += vector.z

    def sub(self, vector):
        return d3Vector(self.x - vector.x, self.y - vector.y, self.z - vector.z)

    def ded(self, vector):
        super().ded(vector)
        self.z -= vector.z

    def mul(self, vector):
        return self.x * vector.x + self.y * vector.y + self.z * vector.z
    
    def __str__(self):
        return "(%s, %s, %s)\nLength: %s\nAngles: %s %s %s" % (self.x, self.y, self.z, self.length, self.angleX, self.angleY, self.angleZ)

if __name__ == "__main__":
    v1 = d3Vector(3, 5, 8)
    v2 = d3Vector(2, 6, 7)
    print(v1, end="\n\n")
    print(v1.getLength(), end="\n\n")
    print(v1.getAngleX(), end="\n\n")
    print(v1.sum(v2), end="\n\n")
    v1.add(v2)
    print(v1, end="\n\n")
    print(v1.sub(v2), end="\n\n")
    v1.ded(v2)
    print(v1, end="\n\n")
    print(v1.mul(v2), end="\n\n")