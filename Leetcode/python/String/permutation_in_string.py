class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        """
        lou

        gobertluiso
        adc
        dcda

        louis

        louiilous

        """

        perm = list(s1)

        min = 10000000
        i = 0

        i_start = 0

        while i != len(s2):

            char = s2[i]
            if char in perm:
                perm.remove(char)
                if len(perm) == 0:
                    return True

                i += 1

            else:



                if len(perm) < min:
                    print(min)
                    min = len(perm)


                perm = list(s1)
                if char in s1:



                    while s2[i_start] != char:
                        i_start += 1

                    i = i_start
                    i_start += 1

                else:
                    i_start = i

                i += 1

        return False
