K = int(input())
room = list(map(int,input().strip().split()))
roomSet = set(room)
result = (sum(roomSet) * K - sum(room)) // (K - 1)
print(result)
