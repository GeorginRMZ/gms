def gms(string: str) -> str:
    result: int = 0
    iterator: int = 0
    match len(string):
        case 1:
            return hex(ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[0])))[2:]
        case 2:
            for _ in zip(string):
                result += (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[0]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[1])))
                iterator += 1
            return hex(result)[2:]
        case 3:
            for _ in zip(string):
                result += (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[0]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[1]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[2])))
                iterator += 1
            return hex(result)[2:]
        case 4:
            for _ in zip(string):
                result += (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[0]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[1]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[2]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[3])))
                iterator += 1
            return hex(result)[2:]
        case 5:
            for _ in zip(string):
                result += (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[0]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[1]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[2]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[3]))) * \
                          (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[4])))
                iterator += 1
            return hex(result)[2:]
        case _:
            for _ in zip(string):
                if iterator >= len(string) - 5:
                    result += (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[0]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[1]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[2]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[3]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[4])))
                else:
                    result += (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[iterator + 1]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[iterator + 2]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[iterator + 3]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[iterator + 4]))) * \
                              (ord(string[iterator]) + (ord(string[iterator]) ^ ord(string[iterator + 5])))
                iterator += 1
            return hex(result)[2:]