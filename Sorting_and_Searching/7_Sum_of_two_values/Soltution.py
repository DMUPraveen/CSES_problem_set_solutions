from collections import defaultdict
def ans(a,b):
    return f"{a+1} {b+1}"
def solution(l,x):
    m = defaultdict(lambda : list())
    for i,v in enumerate(l):
        m[v].append(i)
    for i in m:
        r = x -i
        if(r not in m):
            continue
        if(r == i):
            if(len(m[r]) == 1):
                continue
            return ans(m[r][0],m[r][1])
        return ans(m[i][0],m[r][0])
    
    return "IMPOSSIBLE"
        


def main():
    n,x = map(int,input().split())
    l = list(map(int,input().split()))
    print(solution(l,x))
        
if __name__ == "__main__":
    main()

