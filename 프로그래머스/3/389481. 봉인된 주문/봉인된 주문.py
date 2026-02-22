def solution(n, bans):

    bans_num = []

    for i in range(len(bans)):
        string = bans[i]
        length = len(string)
        number = 0

        for j in range(length):
            char = string[j]
            number += (ord(char) - 96) * pow(26, length - j - 1)
            
        bans_num.append(number)
    
    bans_num.sort()

    for i in range(len(bans_num)):
        if n >= bans_num[i]:
            n += 1
        else:
            break
    
    share = n
    spell = ''

    while share > 0:
        share -= 1
        spell += chr(share % 26 + 97)
        share //= 26
    

    answer = spell[::-1]
    return answer