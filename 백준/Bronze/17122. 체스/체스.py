N = int(input())

for _ in range(N):
    D = 0
    H = 0
    A, B = input().split()
    B = int(B)

    if int(A[1]) > 8 or int(A[1]) < 0:
        continue

    if A[0] == 'A' or A[0] == 'C' or A[0] == 'E' or A[0] == 'G':
        if int(A[1]) % 2 > 0:
            D = 'dark'
        else:
            D = 'white'
            
    elif A[0] == 'B' or A[0] == 'D' or A[0] == 'F' or A[0] == 'H':
        if int(A[1]) % 2 == 0:
            D = 'dark'
        else:
            D = 'white'
    
    else:
        continue
    
    if B <= 8 or 17 <= B <= 24 or 33 <= B <= 40 or 49 <= B <= 56:
        if B % 2 > 0:
            H = 'dark'
        else:
            H = 'white'
    elif 9 <= B <= 16 or 25 <= B <= 32 or 41 <= B <= 48 or 57 <= B <= 64:
        if B % 2 == 0:
            H = 'dark'
        else:
            H = 'white'
    else:
        continue
    
    if D == H:
        print("YES")
        
    elif D != H:
        print("NO")