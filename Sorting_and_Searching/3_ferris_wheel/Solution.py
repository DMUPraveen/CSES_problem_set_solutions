
def main():
    n,x = map(int,input().split())

    p = list(map(int,input().split()))


    p.sort()


    s = 0
    l = len(p)-1

    if(len(p) <=1):
        print(len(p))
        return
    
    g = 0
    while (s <= l):
        if(s == l):
            g += 1
            break
        if(p[s]+p[l] <= x):
            s +=1
            l-=1
        else:
            l-=1
        g +=1
    print(g)

if __name__ == "__main__":
    main()