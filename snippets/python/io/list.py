
n = int(input())
# first arg = int(), second arg = list of chars
# strip() removes spaces at beginning and end
nums = list(map(int,input().strip().split()))[:n] 