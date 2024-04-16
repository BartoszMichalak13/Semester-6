class GF:
    def __init__(self, p=1234577, value=0):
        self.p = p
        self.value = value % p

    @classmethod
    def from_value(cls, value):
        return cls(value=value)

    def setValue(self,val):
        self.value = val

    def __mod_pow(self, other_gf, exp):
        if exp == 0:
            return 1
        prev_gf = 1
        gf_val = other_gf.value
        while exp > 0:
            # print("prev ", prev_gf)
            prev_gf *= gf_val
            prev_gf %= other_gf.p
            exp -= 1
        return prev_gf

    def getP(self):
        return self.p

    def __bool__(self):
        return self.value != 0

    def __int__(self):
        return int(self.value)

    def __float__(self):
        return float(self.value)

    def __add__(self, other):
        if isinstance(other, GF):
            return GF(self.p, (self.value + other.value) % self.p)
        else:
            raise TypeError("unsupported operand type(s) for +: 'GF' and '{}'".format(type(other).__name__))

    def __sub__(self, other):
        if isinstance(other, GF):
            return GF(self.p, (self.value - other.value) % self.p)
        else:
            raise TypeError("unsupported operand type(s) for -: 'GF' and '{}'".format(type(other).__name__))

    def __mul__(self, other):
        if isinstance(other, GF):
            return GF(self.p, (self.value * other.value) % self.p)
        else:
            raise TypeError("unsupported operand type(s) for *: 'GF' and '{}'".format(type(other).__name__))

    def __truediv__(self, other):
        if isinstance(other, GF):
            if other.value == 0:
                raise ValueError("Division by zero")
            return GF(self.p, (self.value * self.__mod_pow(other, other.p - 2)) % self.p)
        else:
            raise TypeError("unsupported operand type(s) for /: 'GF' and '{}'".format(type(other).__name__))

    def __eq__(self, other):
        if isinstance(other, GF):
            return self.value == other.value
        else:
            return False

    def __ne__(self, other):
        if isinstance(other, GF):
            return self.value != other.value
        else:
            return True

    def __le__(self, other):
        if isinstance(other, GF):
            return self.value <= other.value
        else:
            raise TypeError("unsupported operand type(s) for <=: 'GF' and '{}'".format(type(other).__name__))

    def __ge__(self, other):
        if isinstance(other, GF):
            return self.value >= other.value
        else:
            raise TypeError("unsupported operand type(s) for >=: 'GF' and '{}'".format(type(other).__name__))

    def __lt__(self, other):
        if isinstance(other, GF):
            return self.value < other.value
        else:
            raise TypeError("unsupported operand type(s) for <: 'GF' and '{}'".format(type(other).__name__))

    def __gt__(self, other):
        if isinstance(other, GF):
            return self.value > other.value
        else:
            raise TypeError("unsupported operand type(s) for >: 'GF' and '{}'".format(type(other).__name__))

    def __iadd__(self, other):
        if isinstance(other, GF):
            self.value = (self.value + other.value) % self.p
            return self
        else:
            raise TypeError("unsupported operand type(s) for +=: 'GF' and '{}'".format(type(other).__name__))

    def __isub__(self, other):
        if isinstance(other, GF):
            self.value = (self.value - other.value) % self.p
            return self
        else:
            raise TypeError("unsupported operand type(s) for -=: 'GF' and '{}'".format(type(other).__name__))

    def __imul__(self, other):
        if isinstance(other, GF):
            self.value = (self.value * other.value) % self.p
            return self
        else:
            raise TypeError("unsupported operand type(s) for *=: 'GF' and '{}'".format(type(other).__name__))

    def __itruediv__(self, other):
        if isinstance(other, GF):
            if other.value == 0:
                raise ValueError("Division by zero")
            self.value = (self.value * self.__mod_pow(other, other.p - 2)) % self.p
            return self
        else:
            raise TypeError("unsupported operand type(s) for /=: 'GF' and '{}'".format(type(other).__name__))

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        return "GF({}, {})".format(self.p, self.value)

    def __int__(self):
        return int(self.value)

    def __float__(self):
        return float(self.value)

    def __round__(self):
        return round(self.value)

    def __index__(self):
        return self.value

    def __hash__(self):
        return hash((self.p, self.value))


